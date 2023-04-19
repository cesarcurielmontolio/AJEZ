#pragma once
#include "Tablero.h"
#include "ListaPeonesB.h"
#include "ListaCaballosN.h"
#include "CaballoN.h"
#include "PeonB.h"
#include "Selector.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	ListaPeonesB peonesB;
	ListaCaballosN caballosN;

	Tablero tablero;
	PeonB peonB;
	CaballoN caballoN;
	Selector selector;
public:
	virtual ~Mundo();
	void teclaSeleccion(unsigned char key);
	void teclaMueve(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
	void guardaPos();
};
