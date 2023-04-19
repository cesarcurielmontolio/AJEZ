#pragma once
#include "CaballoN.h"
#include "Interaccion.h"
#include "Selector.h"
#include "vector2D.h"
#include"PiezaMovil.h"

#define MAX_CABALLOS 2
class ListaCaballosN :public PiezaMovil
{
private:
	int numero;
	CaballoN* lista[MAX_CABALLOS];
public:
	ListaCaballosN();
	int getNumero() { return numero; };
	bool agregar(CaballoN* c);
	void dibuja();
	void mueve(unsigned char key, Vector2D vPosCInicial, Vector2D vPosInicial);
	void eliminar(int index);
	void eliminar(CaballoN* e);
	void destruircontenido();
	int selC(Selector s);
	Vector2D escoge(Vector2D vPosInicial);
	void MueveC(unsigned char key, int i, Vector2D v);

	friend class selector;
};



