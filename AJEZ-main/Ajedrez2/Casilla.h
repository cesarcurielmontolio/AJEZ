#pragma once
#include "Vector2D.h"
#include "Pieza.h"

class Casilla {

	Pieza* p;

public:

	Casilla() {}
	virtual ~Casilla(){}
	void dibujar();

	//Obtener pieza que hay en la casilla y colocarla
	void setPieza(Pieza* p);
	Pieza* getPieza();


};