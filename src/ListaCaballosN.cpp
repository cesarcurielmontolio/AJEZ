#include "ListaCaballosN.h"

ListaCaballosN::ListaCaballosN()
{
	numero = 0;
	for (int i = 0; i < MAX_CABALLOS; i++) {
		lista[i] = NULL;//0
	}
}

bool ListaCaballosN::agregar(CaballoN* c)
{
	if (numero >= MAX_CABALLOS) {
		return false;
	}
	else {
		lista[numero] = c;
		numero++;
		return true;
	}
	for (int i = 0; i < numero; i++) {
		if (lista[i] == c);
		return false;
	}
}

void ListaCaballosN::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();

	}
}


Vector2D ListaCaballosN::escoge(Vector2D vPosInicial) {
	for (int i = 0; i < numero; i++) {
		if (vPosInicial.x == lista[i]->getPos().x && vPosInicial.y == lista[i]->getPos().y) {
			return(vPosInicial);
		}
	}
}

void ListaCaballosN::mueve(unsigned char key, Vector2D vPosCInicial, Vector2D vPosInicial)
{
	

	for (int i = 0; i < numero; i++) {
		if (vPosInicial.x == lista[i]->getPos().x && vPosInicial.y == lista[i]->getPos().y) {
			lista[i]->mueve(key);

		}





		// MueveC(key, i, v);
		// mover el caballo junto con el selector
		if (!interaccion::CaballoCorrecto(*lista[i], vPosInicial) && key == 'b')
			lista[i]->setPos(vPosInicial.x, vPosInicial.y);
	}
}


void ListaCaballosN::eliminar(int index)
{
	if (index < 0 || index >= numero)
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
	{
		lista[i] = lista[i + 1];
	}
}

void ListaCaballosN::eliminar(CaballoN* c)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i] == c)
		{
			eliminar(i);
			return;
		}
	}
}

void ListaCaballosN::destruircontenido()
{
	for (int i = 0; i < numero; i++)
		delete(lista[i]);
	numero = 0;
}

int ListaCaballosN::selC(Selector s)
{
	for (int i = 0; i < MAX_CABALLOS; i++)
	{
		if (interaccion::selC(*lista[i], s))
			return i;
		else
			return 0;
	}
}

void ListaCaballosN::MueveC(unsigned char key, int i, Vector2D v) 
{
	lista[i]->mueve(key); // mover el caballo junto con el selector
	/*
	if (interaccion::CaballoCorrecto(*lista[i], v) && key == 'b') 
		lista[i]->setPos(/*lista[i]->getPos().x, lista[i]->getPos().y20,20); // esto es para clavar el caballo si el sitio es correcto. 
	*/
}