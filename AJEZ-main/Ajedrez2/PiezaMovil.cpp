#include "PiezaMovil.h"
#include <iostream>
using namespace std;
void PiezaMovil::mueve(unsigned char t)
{

	switch (t) {
	case '8':
		posicion.y = posicion.y + 6;
		if (posicion.y >= 44)
			posicion.y = 44;
		break;
	case '4':
		posicion.x = posicion.x - 6;
		if (posicion.x <= 4)
			posicion.x = 4;
		break;
	case'2':
		posicion.y = posicion.y - 6;
		if (posicion.y <= 4)
			posicion.y = 4;
		break;
	case '6':
		posicion.x = posicion.x + 6;
		if (posicion.x >= 44)
			posicion.x = 44;
		break;
	}


	if (t!=0) // sacar la posicion del puntero y sacar la casilla del cuadrado donde estoy situado. 
	{
		std::cout << "La posicion es: (" << posicion.x << ", " << posicion.y << ")" << endl;
		std::cout << "La Casilla es la : (" << posicion.x/4 << ", " << posicion.y/4 << ")" << endl;


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
Vector2D PiezaMovil::getCasilla(Vector2D v) // Se podría realizar un solo operador para no tener que hacer cada coordenada
{
	Vector2D aux; 
	aux.x = v.x / 4;
	aux.y = v.y / 4;
	return aux;
}

void PiezaMovil::printCasilla(Vector2D v)
{
	int x ,y;
	x = v.x;
	y = v.y;
	std::cout << "La Casilla es la : (" << x/4 << ", " << y/4 << ")" << endl;
}
