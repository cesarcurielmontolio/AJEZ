#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "board.h"
#include"Vector2D.h"

class Mundo
{
public:
	Mundo();
	virtual ~Mundo();
	void Tecla(unsigned char key);
	void Inicializa();
	void Dibuja();
	void Mueve();
	bool cargarNivel();
	board b;
private:
	
	float x_ojo;
	float y_ojo;
	float z_ojo;
};