#pragma once
#include "Pieza.h"
class Caballo : public Pieza {



public: 
	Caballo(color c, tipo t, Vector2D p) {
		colour = c; 
		type = t;
		posicion = p;
	}

	void dibujar(); //Derivada de func virtual en Pieza
	void dibujarSW();  //Funci�n para dibujar las figuras con tem�tica de Star Wars
	bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
	bool movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c);  //Funci�n de movimiento de la pieza
	color getCol() const;
	char getTipo();
};





