#pragma once
#include "Tablero.h"
#include "Selector.h"
#include"CaballoN.h"

class interaccion {
public:
	static bool selC(CaballoN& c, Selector s);
	static bool sitioCCorrecto(Selector& s, Vector2D p);
	static bool CaballoCorrecto(CaballoN& c, Vector2D v);
};