#include "PiezaMovil.h"
#include <iostream>

void PiezaMovil::mueve(unsigned char t)
{

	switch (t) {
	case '8':
		posicion.y = posicion.y + 6;
		if (posicion.y >= 20)
			posicion.y = 20;
		break;
	case '4':
		posicion.x = posicion.x - 6;
		if (posicion.x <= -22)
			posicion.x = -22;
		break;
	case'2':
		posicion.y = posicion.y - 6;
		if (posicion.y <= -22)
			posicion.y = -22;
		break;
	case '6':
		posicion.x = posicion.x + 6;
		if (posicion.x >= 20)
			posicion.x = 20;
		break;
	}
}
void PiezaMovil::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void PiezaMovil::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

Vector2D PiezaMovil::getPos()
{
	return Vector2D(posicion);
}

void PiezaMovil::setPosInicial(Vector2D v)
{
	posicionInicial.x = v.x;
	posicionInicial.y = v.y;

}
