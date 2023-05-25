#include"Pieza.h"

#include"Rey.h"
void Rey::dibujar() {
	if (Pieza::colour == 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reyblanco.png").id);
		glDisable(GL_LIGHTING);

	}
	else if (Pieza::colour == 1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reynegro.png").id);
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
void Rey::dibujarSW()
{
	if (Pieza::colour == 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenesSW/reyblanco.png").id);
		glDisable(GL_LIGHTING);

	}
	else if (Pieza::colour == 1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenesSW/reynegro.png").id);
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
bool Rey::movimiento(Vector2D pos_ini, Vector2D pos_fin) {
	//No permite realizar desplazamientos de más de una casilla con el rey
	if ((abs(pos_fin.x - pos_ini.x) == 1 && abs(pos_fin.y - pos_ini.y) == 1)) {
		return true;
	}
	else if ((abs(pos_fin.x - pos_ini.x) == 1 && abs(pos_fin.y - pos_ini.y) == 0)) {

	}
	else if ((abs(pos_fin.x - pos_ini.x) == 0 && abs(pos_fin.y - pos_ini.y) == 1)) {

	}
	else {
		return false;
	}
}

bool Rey::movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c) {
	//No permite realizar desplazamientos de más de una casilla con el rey
	if ((abs(pos_fin.x - pos_ini.x) == 1 && abs(pos_fin.y - pos_ini.y) == 1)) {
		return true;
	}
	else if ((abs(pos_fin.x - pos_ini.x) == 1 && abs(pos_fin.y - pos_ini.y) == 0)) {

	}
	else if ((abs(pos_fin.x - pos_ini.x) == 0 && abs(pos_fin.y - pos_ini.y) == 1)) {

	}
	else {
		return false;
	}
}

color Rey::getCol() const{
	if (colour == color::BLANCA) {
		return color::BLANCA;
	}
	else if (colour == color::NEGRA) {
		return color::NEGRA;
	}

}
char Rey::getTipo() {
	return 'K';

}
