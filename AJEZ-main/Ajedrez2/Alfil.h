#pragma once
#include"Pieza.h"

class Alfil : public Pieza {

public:

	Alfil(color c,tipo t, Vector2D p) {
		type = ALFIL;
		colour = c;
		posicion = p;

	}
	void dibujar(); //Derivada de func virtual en Pieza
	void dibujarSW();  //Función para dibujar las figuras con temática de Star Wars
	bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
	bool movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c);  //Función de movimiento de la pieza
	color getCol() const;
	char getTipo();
};