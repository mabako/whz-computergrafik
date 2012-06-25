#include "StdAfx.h"
#include <assert.h>
#include <iostream>
#include "GKS_Programm.h"

CGKS_Programm::CGKS_Programm(void)
{
}

CGKS_Programm::~CGKS_Programm(void)
{
}

void CGKS_Programm::execute()
{
	// Server starten	
	gopen_gks(NULL);
	
	// Workstation ˆffnen
	gopen_ws(1, NULL, GKS_SUBWINDOW);

	gx_set_win(1, -250, 250, -50, 350);
	gx_set_vp(1, 0, 1, 0.1f, 0.9f);

	// Workstation aktivieren
	gactivate_ws(1);

	// Rechteck
	gcreate_seg(1);
	Gpoint_list Rechteck;
	Gpoint RechteckPunkte[5] = {{-200, 0}, {200, 0}, {200, 300}, {-200, 300}, {-200, 0}};
	Rechteck.points = RechteckPunkte;
	Rechteck.num_points = 5;
	gset_linewidth(1);
	gset_line_colr_ind(2);
	gpolyline(&Rechteck);

	// Mittelsenkrechte
	Gpoint_list Mittellinie;
	Gpoint MittellinienPunkte[2] = {{0, 0}, {0, 300}};
	Mittellinie.points = MittellinienPunkte;
	Mittellinie.num_points = 2;

	gset_linewidth(0.3f);
	gset_linetype(GLINE_DASH);
	gpolyline(&Mittellinie);

	gclose_seg();

	// Dreieck
	gcreate_seg(2);
	Gpoint_list Dreieck;
	Gpoint DreieckPunkte[4] = {{20, 20}, {140, 20}, {140, 260}, {20, 20}};
	Dreieck.points = DreieckPunkte;
	Dreieck.num_points = 4;

	gset_linewidth(2);
	gset_linetype(GLINE_SOLID);
	gset_line_colr_ind(4);
	gpolyline(&Dreieck);

	// Seitenhalbierende
	Gpoint_list Seitenhalbierende;
	Gpoint SeitenhalbierendenPunkte[2] = {{20, 20}, {140, 140}};
	Seitenhalbierende.points = SeitenhalbierendenPunkte;
	Seitenhalbierende.num_points = 2;
	gpolyline(&Seitenhalbierende);

	// Eckpunkte des Dreiecks
	gset_linetype(1);
	gset_marker_size(1.5f);
	gset_marker_colr_ind(7);
	gset_marker_type(GMARKER_CIRCLE);
	Dreieck.num_points = 3;
	gpolymarker(&Dreieck);

	gclose_seg();

	// Quadrat
	gcreate_seg(3);

	Gpoint_list Quadrat;
	Gpoint QuadratPunkte[5] = {{-100, 0}, {-20, 80}, {-100, 160}, {-180, 80}, {-100, 0}};
	Quadrat.points = QuadratPunkte;
	Quadrat.num_points = 5;

	gset_fill_colr_ind(2);
	gset_fill_int_style(GSTYLE_SOLID);
	gfill_area(&Quadrat);

	gset_fill_colr_ind(7);
	gset_fill_int_style(GSTYLE_HOLLOW);
	gfill_area(&Quadrat);

	gclose_seg();

	// Text
	gcreate_seg(4);
	
	gset_text_colr_ind(3);
	gset_char_ht(25);

	Gtext_align Ausrichtung;
	Ausrichtung.hor = GHOR_CTR;
	Ausrichtung.vert = GVERT_HALF;
	gset_text_align(&Ausrichtung);

	Gpoint textPunkt = {-100, 80};
	gtext(&textPunkt, "QUADRAT");

	gclose_seg();


	// Punktmuster f¸r x>0

	// Workstation deaktivieren
	gdeactivate_ws(1);

	std::cin.ignore();
	// Workstation schlieﬂen
	gclose_ws(1);

	// Server beenden
	gclose_gks();
}