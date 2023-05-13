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

class Pieza
{
public:
	tipo type;
	color colour;
	Vector2D posicion;
	

	Pieza(tipo t, color c, Vector2D p) : colour(c), type(t), posicion(0,0) {}
	Pieza() { colour = NO_DEFINIDO; type = VACIA;}

	//Funciones virtuales que se definen en las clases derivadas (Peón, rey, etc)
	virtual void dibuja(Vector2D p) = 0;
	virtual bool movimiento(Vector2D pos_ini, Vector2D pos_fin) = 0; //Función bool para que realice mov adecuado para cada pieza

};

