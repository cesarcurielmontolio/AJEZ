#pragma once
#include "Selector.h"

Selector::Selector(float r, float px, float py)
{
	radio = r;
	posicion.x = px;
	posicion.y = py;
	rojo = verde = 255;
	azul = 0;
	radio = 1.0f;
}

Selector::~Selector()
{
}

void Selector::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

Vector2D Selector::seleccion(unsigned char key)
{
	
	Vector2D pieza;
	if (key == 's') {
		pieza.x = getPos().x;
		pieza.y = getPos().y;
	}
	
	return (0, 0);
}

void Selector::setPosInicial(Vector2D v) {
	posicionInicial.x = v.x;
	posicionInicial.y = v.y;
}

Vector2D Selector::getPos()
{
	return(posicion);

}




int Selector::getPieza(Vector2D v)
{
	for (int i = -22; i <= 20; i + 6) {
		for (int j = -22; j <= 20; j + 6) {
			
		}
	}

	return 1;
}




