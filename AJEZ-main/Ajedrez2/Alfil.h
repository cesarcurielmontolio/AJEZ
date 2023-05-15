#pragma once
#include"Pieza.h"

class Alfil : public Pieza {

public:

	Alfil(color c, Vector2D p) {
		type = ALFIL;
		colour = c;
		posicion = p;

	}
	void dibujar(); //Derivada de func virtual en Pieza
	bool movimiento(Vector2D pos_ini, Vector2D pos_fin, color c_destino));
	Movimiento getMov(Vector2D pos_ini, Vector2D pos_fin);
};