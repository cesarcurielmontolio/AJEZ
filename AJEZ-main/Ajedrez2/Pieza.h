#pragma once
#include "freeglut.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include"Vector2D.h"
#include"ETSIDI.h"

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
		posicion.y = 0;
	}

	//Funciones para obtener la posicion de nuestras piezas
	Vector2D getPos();
	int getCoordX();
	int getCoordY();
	void setPos(Vector2D v);
	virtual color getCol() const = 0;
	virtual char getTipo() = 0;


	// Funciones virtuales que se realizan en las piezas derivadas
	virtual void dibujar()=0; //Derivada de func virtual en Pieza
	virtual void dibujarSW()=0;


	virtual bool movimiento(Vector2D pos_ini, Vector2D pos_fin) = 0; // debe ser funcion virtual para que pase a la funcion de cada clase más concreta 
	virtual bool movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c) = 0;


};


