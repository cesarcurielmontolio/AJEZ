#pragma once
#include"Pieza.h"

class Caballo : public Pieza {

public:

	Caballo(color c, Vector2D p) {
		type = CABALLO;
		colour = c;
		posicion = p;

	}
  
	void dibujar(); //Derivada de func virtual en Pieza
  //virtual void dibuja(Vector2D p) = 0; 
	bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
	Movimiento getMov(Vector2D pos_ini, Vector2D pos_fin);
};