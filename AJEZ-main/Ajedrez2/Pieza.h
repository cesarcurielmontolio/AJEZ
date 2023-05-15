#pragma once
#include "freeglut.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include"Vector2D.h"
#include"Movimiento.h"

using namespace std;
enum tipo { TORRE, CABALLO, ALFIL, REY, REINA, PEON, VACIA };
enum color { BLANCA, NEGRA, NO_DEFINIDO };

class Pieza {

protected:
	tipo type;
	color colour;

public:
	
	Vector2D posicion;
	Pieza() { 
		colour = NO_DEFINIDO; 
		type = VACIA;
		posicion.x = 0;
		posicion.y = 0
	}

	//Funciones para obtener la posicion de nuestras piezas
	Vector2D getPos();
	int getCoordX();
	int getCoordY();
	void setPos(Vector2D);
	color getCol() const;

	//Funciones virtuales que se definen en las clases derivadas (Peón, rey, etc)
	virtual void dibujar() = 0;
	virtual bool movimiento(Vector2D pos_ini, Vector2D pos_fin) = 0; //Función bool para que realice mov adecuado para cada pieza
	virtual Movimiento getMov(Vector2D pos_ini, Vector2D pos_fin) = 0;
};

