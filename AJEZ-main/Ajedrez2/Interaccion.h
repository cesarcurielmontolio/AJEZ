#pragma once
#include "Tablero.h"
#include "Selector.h"
#include "Vector2D.h"

class interaccion {

public:
	// RECORRIDOS 
	static bool recorridoTorre(Tablero& t, Vector2D pos_ini, Vector2D pos_fin);
	static bool recorridoAlfil(Tablero& t, Vector2D pos_ini,Vector2D inter, Vector2D pos_fin);
	static bool comerPeon(Tablero& t, Vector2D pos_ini, Vector2D pos_fin);

};
