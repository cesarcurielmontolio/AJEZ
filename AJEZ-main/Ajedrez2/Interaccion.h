#pragma once
#include "Tablero.h"
#include "Selector.h"
#include "Vector2D.h"

class interaccion {

public:

	// 
	// RECORRIDOS 
	static bool recorridoTorre(Tablero& t, Vector2D pos_ini, Vector2D pos_fin);  //Realiza la traza del movimiento de la Torre y detecta si hay obstáculos en medio
	static bool recorridoAlfil(Tablero& t, Vector2D pos_ini,Vector2D inter, Vector2D pos_fin); //Idem Alfil
	static bool comerPeon(Tablero& t, Vector2D pos_ini, Vector2D pos_fin);  //Movimineto para comer del peon

};