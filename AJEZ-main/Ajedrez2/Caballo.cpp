#include "Caballo.h"

void Caballo::dibujar()
{
	if (Pieza::colour == 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballoblanco.png").id);
		glDisable(GL_LIGHTING);

	}
	else if (Pieza::colour == 1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballonegro.png").id);
		glDisable(GL_LIGHTING);

	}
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(posicion.x, posicion.y + 1, 0.1);
	glTexCoord2d(1, 1); glVertex3f(posicion.x + 1, posicion.y + 1, 0.1);
	glTexCoord2d(1, 0); glVertex3f(posicion.x + 1, posicion.y, 0.1);
	glTexCoord2d(0, 0); glVertex3f(posicion.x, posicion.y, 0.1);



	glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Caballo::dibujarSW()
{

	if (Pieza::colour == 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenesSW/caballoblanco.png").id);
		glDisable(GL_LIGHTING);

	}
	else if (Pieza::colour == 1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenesSW/caballonegro.png").id);
		glDisable(GL_LIGHTING);

	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(posicion.x, posicion.y + 1, 0.1);
	glTexCoord2d(1, 1); glVertex3f(posicion.x + 1, posicion.y + 1, 0.1);
	glTexCoord2d(1, 0); glVertex3f(posicion.x + 1, posicion.y, 0.1);
	glTexCoord2d(0, 0); glVertex3f(posicion.x, posicion.y, 0.1);



	glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

bool Caballo::movimiento(Vector2D pos_ini, Vector2D pos_fin) {

	//Cuando se desplaza el caballo una posición (en cualquier sentido) en la dirección horizontal (eje x), se tiene que desplazar 2 casillas en el eje y
	if ((abs(pos_fin.x - pos_ini.x) == 1) && (abs(pos_fin.y - pos_ini.y) == 2)) {
		return true;
	}
	//Situación inversa, cuando solo se desplaza en el eje y una posición debe hacerlo 2 en el eje x
	else if ((abs(pos_fin.y - pos_ini.y) == 1) && (abs(pos_fin.x - pos_ini.x) == 2)) {
		return true;
	}
	else {
		return false;
	}
}


bool Caballo::movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c) {
	//Cuando se desplaza el caballo una posición (en cualquier sentido) en la dirección horizontal (eje x), se tiene que desplazar 2 casillas en el eje y
	if ((abs(pos_fin.x - pos_ini.x) == 1) && (abs(pos_fin.y - pos_ini.y) == 2)) {
		return true;
	}
	//Situación inversa, cuando solo se desplaza en el eje y una posición debe hacerlo 2 en el eje x
	else if ((abs(pos_fin.y - pos_ini.y) == 1) && (abs(pos_fin.x - pos_ini.x) == 2)) {
		return true;
	}
	else {
		return false;
	}
}

color Caballo::getCol() const {
	if (colour == color::BLANCA) {
		return color::BLANCA;
	}
	else if (colour == color::NEGRA) {
		return color::NEGRA;
	}

}
char Caballo::getTipo() {
	return 'C';

}
