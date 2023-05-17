#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "board.h"
#include"Vector2D.h"

class Mundo {
public:
	enum Nivel {INICIO, PAUSA, JUEGO, SALIR};

	Mundo();
	virtual ~Mundo() {}
	void Tecla(unsigned char key);
	void Inicializa();
	void Dibuja();
	void Mueve();
	board b;
	Vector2D vec;
	Nivel n;

private:
	
	float x_ojo;
	float y_ojo;
	float z_ojo;
};