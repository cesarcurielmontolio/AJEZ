#pragma once
#include "Vector2D.h"

class PiezaMovil {
public:
	virtual void mueve(unsigned char  t);
	void setPos(float x, float y);
	void setVel(float vx, float vy);

	Vector2D getPos();
	void setPosInicial(Vector2D v);
	Vector2D getCasilla(Vector2D v);
	void printCasilla(Vector2D v);
	
protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Vector2D posicionInicial;
};