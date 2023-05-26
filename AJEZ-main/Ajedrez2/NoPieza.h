#pragma once
#include"Pieza.h"

class NoPieza : public Pieza {

public:
	NoPieza() {
		colour = color::NO_DEFINIDO;
		type = tipo::VACIA;
		posicion = Vector2D(10, 10); //Fuera de la matriz que define el tablero
	}
	NoPieza(color c, tipo t, Vector2D p) {
		colour = c;
		type = t;
		posicion = p;
	}
	virtual ~NoPieza() {}
	void dibujar();
	bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
	bool movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c);
	color getCol() const;
	char getTipo();

};