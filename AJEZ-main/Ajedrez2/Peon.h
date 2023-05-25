#pragma once
#include"Pieza.h"

class Peon : public Pieza {

public:

	Peon(color c,tipo t, Vector2D p) {
		type = t;
		colour = c;
		posicion = p;

	}

	void dibujar(); //Derivada de func virtual en Pieza
	void dibujarSW();
	bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
	bool movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c); //Movimiento
	color getCol()const;
	char getTipo();

};
