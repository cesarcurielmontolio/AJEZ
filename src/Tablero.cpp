#pragma once
#include "Tablero.h"
#include "ETSIDI.h"
#include "freeglut.h"


Tablero::Tablero()
{

}

Tablero::~Tablero()
{
}

void Tablero::dibuja()
{

	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.4.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-24, -24, 0);
	glTexCoord2d(1, 1); glVertex3f(24, -24, 0);
	glTexCoord2d(1, 0); glVertex3f(24, 24, 0);
	glTexCoord2d(0, 0); glVertex3f(-24, 24, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}