#pragma once

#include "Casilla.h"
#include "Pieza.h"
#include "NoPieza.h"
#include "CaballoN.h"
#include "Torre.h"
#include "Alfil.h"
#include "Peon.h"
#include "Rey.h"
#include "Reina.h"
#include "Caballo.h"

class Tablero {
public:
	bool inicializado; 
	/*float sqsize; //tama�o de casillas
	float bdsize; //grosor del borde exterior*/
	Pieza* p;
	Casilla c[8][8]; //Matriz de 8x8 que representa el tablero

	Tablero(); 
	Tablero (int a,int  b, Vector2D v);
	void init(); 


	bool estaInicializado(); 
	virtual~Tablero();
	void dibuja();
	void muevePieza(Vector2D pos_ini, Vector2D pos_fin); // para encontrar la casilla mediante los pixeles de la pantalla. 
	friend class interaccion;
};
