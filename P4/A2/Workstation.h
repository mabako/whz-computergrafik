#pragma once
#include "stdafx.h"
#include "GKS_Programm.h"

class Workstation
{
private:
	// Interne ID
	int id;

	// der zugrundeliegende Server
	CServer* server;

public:
	// Öffnet die Workstation
	Workstation(CServer* server, int id)
	{
		this->id = id;
		this->server = server;
		this->server->gopen_ws(this->id, NULL, GKS_SUBWINDOW);
	}

	// Schließt die Workstation
	~Workstation()
	{
		server->gclose_ws(id);
	}

	// Aktiviert die Workstation
	void Activate()
	{
		server->gactivate_ws(id);
	}

	// Deaktiviert die Workstation
	void Deactivate()
	{
		server->gdeactivate_ws(id);
	}

	// Ändert den Viewport je nach Bedarf relativ zum Ausgabefenster von 0.0f bis 1.0f
	Workstation* SetViewport(float min_x, float max_x, float min_y, float max_y)
	{
		server->gx_set_vp(id, min_x, max_x, min_y, max_y);
		return this;
	}

	// Ändert die verwendeten Koordinaten in der "Welt"
	Workstation* SetWindow(float min_x, float max_x, float min_y, float max_y)
	{
		server->gx_set_win(id, min_x, max_x, min_y, max_y);
		return this;
	}

private:
	// Ändert einen Farbindex auf eine RGB-Farbe
	void SetColor(int colorIndex, unsigned int color)
	{
		Gcolr_rep Color;
		Color.rgb.red = ((color >> 16) & 0xFF)/256.0f;
		Color.rgb.green = ((color >> 8) & 0xFF)/256.0f;
		Color.rgb.blue = (color & 0xFF)/256.0f;
		server->gset_colr_rep(id, colorIndex, &Color);
	}

public:
	// Ändert die Farben 0, 1, 2 und 3 auf die jeweils angegebenen RGB-Farben
	Workstation* SetColors(unsigned int color0, unsigned int color1, unsigned int color2, unsigned int color3)
	{
		SetColor(0, color0);
		SetColor(1, color1);
		SetColor(2, color2);
		SetColor(3, color3);
		return this;
	}
};
