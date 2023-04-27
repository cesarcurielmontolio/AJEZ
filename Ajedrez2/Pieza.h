#pragma once
#include "freeglut.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

enum tipo { TORRE, CABALLO, ALFIL, REY, REINA, PEON, VACIA }; 
enum color { BLANCA, NEGRA };

class Pieza
{
public:
	tipo type;
	color colour;

	

	Pieza(tipo t, color c) : colour(c), type(t) {}
	Pieza() { colour = BLANCA; type = VACIA; }
};

