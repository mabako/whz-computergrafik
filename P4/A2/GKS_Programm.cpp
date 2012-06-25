#include "StdAfx.h"
#include <iostream>
#include "GKS_Programm.h"
#include "Workstation.h"

CGKS_Programm::CGKS_Programm(void)
{
}

CGKS_Programm::~CGKS_Programm(void)
{
}

void CGKS_Programm::execute()
{
	// Server starten	
	gopen_gks("con");
	
	// Alle Fenster & Viewports einrichten.
	Workstation* w[5] = {0, new Workstation(this, 1), new Workstation(this, 2), new Workstation(this, 3), new Workstation(this, 4)};
	w[1]->SetViewport(0, 0.5f, 0.5f, 1)->SetWindow(0, 100, 0, 100)->SetColors(0xFFFFAA, 0xFF0000, 0x00FF00, 0xAAAAFF);
	w[2]->SetViewport(0.5f, 1, 0.5f, 1)->SetWindow(0, 100, 0, 100)->SetColors(0xAAAAFF, 0xFFFFFF, 0, 0xFFFFFF);
	w[3]->SetViewport(0, 0.5f, 0, 0.5f)->SetWindow(50, 100, 20, 70)->SetColors(0xAAFFAA, 0, 0, 0xAAAAFF);
	w[4]->SetViewport(0.5f, 1, 0, 0.5f)->SetWindow(0, 50, 20, 70)->SetColors(0xFFAAAA, 0xFF0000, 0, 0);

	// Quadrat vorbereiten
	Gpoint_list Quadrat;
	Gpoint QuadratPunkte[5] = {{10, 30}, {40, 30}, {40, 60}, {10, 60}, {10, 30}};
	Quadrat.points = QuadratPunkte;
	Quadrat.num_points = 5;

	// Kreuzschraffur nur in der ersten Workstation
	w[1]->Activate();

	gcreate_seg(1);
	gset_fill_colr_ind(2);
	gset_fill_int_style(GSTYLE_HATCH);
	gset_fill_style_ind(GHATCH_DIAG_45_135);

	Gfloat_size MusterGroesse;
	MusterGroesse.size_x = 10;
	MusterGroesse.size_y = 10;
	gset_pat_size(&MusterGroesse);

	gfill_area(&Quadrat);
	gclose_seg();

	for(int i = 2; i <= 4; ++ i)
		w[i]->Activate();

	// Quadrat zeichnen
	gcreate_seg(2);
	gset_fill_colr_ind(1);
	gset_fill_int_style(GSTYLE_HOLLOW);
	gfill_area(&Quadrat);
	gclose_seg();

	// Dreieck zeichnen
	gcreate_seg(3);
	Gpoint_list Dreieck;
	Gpoint DreieckPunkte[4] = {{60, 30}, {90, 30}, {75, 60}, {60, 30}};
	Dreieck.points = DreieckPunkte;
	Dreieck.num_points = 4;
	gset_line_colr_ind(3);
	gpolyline(&Dreieck);
	gclose_seg();

	for(int i = 1; i <= 4; ++ i)
		w[i]->Deactivate();

	// Haltepunkt
	std::cin.ignore();

	for(int i = 1; i <= 4; ++ i)
		delete w[i];
		
	// Server beenden
	gclose_gks();
}