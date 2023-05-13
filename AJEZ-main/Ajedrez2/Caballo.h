#pragma once
#include"Pieza.h"

class Caballo : public Pieza {

public:

	Caballo(color c, Vector2D p) {
		type = CABALLO;
		colour = c;
		posicion = p;

	}
	virtual void dibuja(Vector2D p) = 0; 
	virtual bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
};
