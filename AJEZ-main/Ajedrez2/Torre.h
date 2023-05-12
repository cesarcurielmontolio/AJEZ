#pragma once
#include"Pieza.h"

class Torre : public Pieza {

public:

	Torre(color c, Vector2D p) {
		type = TORRE;
		colour = c;
		posicion = p;

	}
	void dibujar(int); //Derivada de func virtual en Pieza
	virtual bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
};
