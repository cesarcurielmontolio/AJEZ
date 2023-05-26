#pragma once

#include "Casilla.h"
#include "Pieza.h"
#include "NoPieza.h"
#include "Torre.h"
#include "Alfil.h"
#include "Peon.h"
#include "Rey.h"
#include "Reina.h"
#include "Caballo.h"

class Tablero {
public:
	bool inicializado;
	/*float sqsize; //tamaño de casillas
	float bdsize; //grosor del borde exterior*/
	Pieza* p;
	Casilla c[8][8]; //Matriz de 8x8 que representa el tablero

	// static Tablero* t;

	Tablero();
	Tablero(int a, int  b, Vector2D v);
	void init();
	Vector2D obtenerPos(Vector2D v);

	bool estaInicializado();
	virtual~Tablero();


	void dibuja();
	void dibujaSW();

	bool maniobraValidada(char pieza, Vector2D pos_ini, Vector2D pos_fin);
	

	void muevePieza(Vector2D pos_ini, Vector2D pos_fin, color col); // para encontrar la casilla mediante los pixeles de la pantalla. 
	friend class interaccion;
	void reset();
};
