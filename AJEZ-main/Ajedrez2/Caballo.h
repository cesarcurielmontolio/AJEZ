#pragma once
#include"Pieza.h"

class Caballo : public Pieza {

public:

	Caballo(color c, Vector2D p) {
		type = CABALLO;
		colour = c;
		posicion = p;

	}
	void dibujar(int); //Derivada de func virtual en Pieza
	virtual bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
};