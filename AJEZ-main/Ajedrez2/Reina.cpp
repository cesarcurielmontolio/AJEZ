#include"Reina.h"
void Reina::dibujar() {
	if (Pieza::colour == 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reinablanca.png").id);
		glDisable(GL_LIGHTING);

	}
	else if (Pieza::colour == 1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reinanegra.png").id);
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
void Reina::dibujarSW()
{
	if (Pieza::colour == 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenesSW/reinablanca.png").id);
		glDisable(GL_LIGHTING);

	}
	else if (Pieza::colour == 1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenesSW/reinanegra.png").id);
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
bool Reina::movimiento(Vector2D pos_ini, Vector2D pos_fin) {
	//El movimiento de la Reina es una combinación de los mov del Alfil y de la Torre
	//Movimiento Alfil
	if (abs(pos_fin.x - pos_ini.x) == abs(pos_fin.y - pos_ini.y)) {
		return true;
	}
	//Movimiento Torre
	else if ((pos_fin.x == pos_ini.x) && (pos_fin.y != pos_ini.y)) { //Movimiento ascendente o descendente
		return true;
	}

	//Movimientos horizontales (eje x, no cambia pos en y)
	else if ((pos_fin.y == pos_ini.y) && (pos_fin.x != pos_ini.x)) {  //Desplazamiento lateral
		return true;
	}
	else {
		return false;
	}
}

bool Reina::movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c) {
	//El movimiento de la Reina es una combinación de los mov del Alfil y de la Torre
	//Movimiento Alfil
	if (abs(pos_fin.x - pos_ini.x) == abs(pos_fin.y - pos_ini.y)) {
		return true;
	}
	//Movimiento Torre
	else if ((pos_fin.x == pos_ini.x) && (pos_fin.y != pos_ini.y)) { //Movimiento ascendente o descendente
		return true;
	}

	//Movimientos horizontales (eje x, no cambia pos en y)
	else if ((pos_fin.y == pos_ini.y) && (pos_fin.x != pos_ini.x)) {  //Desplazamiento lateral
		return true;
	}
	else {
		return false;
	}
}

color Reina::getCol() const {
	if (colour == color::BLANCA) {
		return color::BLANCA;
	}
	else if (colour == color::NEGRA) {
		return color::NEGRA;
	}

}
char Reina::getTipo() {
	return 'Q';

}
