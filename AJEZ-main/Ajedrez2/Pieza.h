#pragma once
#include "freeglut.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include"Vector2D.h"
#include"Movimiento.h"
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
		posicion.y = 0
	}

	//Funciones para obtener la posicion de nuestras piezas
	Vector2D getPos();
	int getCoordX();
	int getCoordY();
	void setPos(Vector2D);
	color getCol() const;

  void dibujar(); //Derivada de func virtual en Pieza
  //virtual void dibuja(Vector2D p) = 0; 
	bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
	Movimiento getMov(Vector2D pos_ini, Vector2D pos_fin);
  
};

