#pragma once
#include"Pieza.h"

class Reina : public Pieza {

public:

	Reina(color c, Vector2D p) {
		type = REINA;
		colour = c;
		posicion = p;

	}

  void dibujar(); //Derivada de func virtual en Pieza
  //virtual void dibuja(Vector2D p) = 0; 
	bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
	Movimiento getMov(Vector2D pos_ini, Vector2D pos_fin);

};
