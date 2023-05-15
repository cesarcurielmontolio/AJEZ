#pragma once
#include"Pieza.h"
#include"Vector2D.h"
#include "Casilla.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "Peon.h"
#include "Caballo.h"
#include "NoPieza.h"
#include<stdlib.h>
#include<vector>
#define LADO 8

class board
{
	/*float sqsize; //tamaño de casillas
	float bdsize; //grosor del borde exterior*/
	Pieza* p;
	Casilla c[8][8]; //Matriz de 8x8 que representa el tablero

public:


	board();
	virtual ~board(){}
	void init();

	//Parte gráfica
	void set_board(float sqz, float bdz);
	void draw_board(); //dibuja el tablero y las piezas

	//Movimientos
	
	
};

