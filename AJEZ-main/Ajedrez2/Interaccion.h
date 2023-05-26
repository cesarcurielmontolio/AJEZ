#pragma once
#include "Tablero.h"
#include "Selector.h"
#include"CaballoN.h"
#include "Vector2D.h"

class interaccion {

public:

	
	


	
	static bool selC(CaballoN& c, Selector s);
	static bool sitioCCorrecto(Selector& s, Vector2D p);
	//static bool CaballoCorrecto(CaballoN& c, Vector2D v);
	// 
	// 
	// 
	// RECORRIDOS 
	static bool recorridoTorre(Tablero& t, Vector2D pos_ini, Vector2D pos_fin);
	static bool recorridoAlfil(Tablero& t, Vector2D pos_ini,Vector2D inter, Vector2D pos_fin);
	static bool comerPeon(Tablero& t, Vector2D pos_ini, Vector2D pos_fin);

};