#pragma once
#include"Pieza.h"

class Rey : public Pieza {

public:

	Rey(color c, Vector2D p) {
		type = REY;
		colour = c;
		posicion = p;

	}
	void dibujar(int); //Derivada de func virtual en Pieza
	virtual bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
};