#pragma once
#include"Pieza.h"

class Alfil : public Pieza {

public:

	Alfil(color c, Vector2D p) {
		type = ALFIL;
		colour = c;
		posicion = p;

	}
	void dibujar(int); //Derivada de func virtual en Pieza
	virtual bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
};
