#pragma once
#include"Pieza.h"

class Peon : public Pieza {

public:

	Peon(color c, Vector2D p) {
		type = PEON;
		colour = c;
		posicion = p;

	}
	void dibujar(int); //Derivada de func virtual en Pieza
	virtual bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
};