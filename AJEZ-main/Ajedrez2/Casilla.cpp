#include"Casilla.h"
#include "Tablero.h"

# define limite 0,5

void Casilla::dibujarCasilla() { //Dibujar casillas
	
	glDisable(GL_LIGHTING);
	glColor3ub(137, 107, 73);
	glBegin(GL_QUADS);

	glVertex3f((p->getCoordX() ), (p->getCoordY() ), -0.1);
	glVertex3f((p->getCoordX()), (p->getCoordY()+1), -0.1);
	glVertex3f((p->getCoordX() +1), (p->getCoordY() +1), -0.1);
	glVertex3f((p->getCoordX() +1), (p->getCoordY() +0), -0.1);

	glEnd();
	glEnable(GL_LIGHTING);

}

void Casilla::setPieza(Pieza* p) {
	this->p = p;
}
Pieza* Casilla::getPieza() {
	return p;
}

Vector2D Casilla::getCasilla()
{
	return Vector2D();
}
