#include "Peon.h"

#include"Peon.h"
void Peon::dibujar() {

	if (Pieza::colour == 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peonblanco.png").id);
		glDisable(GL_LIGHTING);

	}
	else if (Pieza::colour == 1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peonnegro.png").id);
		glDisable(GL_LIGHTING);

	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glTexCoord2d(0, 1); glVertex3f(posicion.x, posicion.y + 1, 0.1);
	glTexCoord2d(1, 1); glVertex3f(posicion.x + 1, posicion.y + 1, 0.1);
	glTexCoord2d(1, 0); glVertex3f(posicion.x + 1, posicion.y, 0.1);
	glTexCoord2d(0, 0); glVertex3f(posicion.x, posicion.y, 0.1);


	glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);





}
void Peon::dibujarSW()
{
	if (Pieza::colour == 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenesSW/peonblanco.png").id);
		glDisable(GL_LIGHTING);

	}
	else if (Pieza::colour == 1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenesSW/peonnegro.png").id);
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
bool Peon::movimiento(Vector2D pos_ini, Vector2D pos_fin) {
	
	//Movimiento piezas blancas (igual para las negras)
	if (colour == color::BLANCA) {
		if (pos_ini.y == 1) { //Primer movimiento
			if ((pos_fin.x - pos_ini.x) == 0 && ((pos_fin.y - pos_ini.y) == 1 || (pos_fin.y - pos_ini.y) == 2)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if ((pos_fin.x - pos_ini.x) == 0 && (pos_fin.y - pos_ini.y) == 1) { //Movimiento para avanzar normal hacia delante
				return true;
		}
		else 
			return false;

	}
	//Idem Negras

	else if (colour == color::NEGRA) {
		if (pos_ini.y == 6) {
			if ((pos_fin.x - pos_ini.x) == 0 && ((pos_fin.y - pos_ini.y) == -1 || (pos_fin.y - pos_ini.y) == -2)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if ((pos_fin.x - pos_ini.x) == 0 && (pos_fin.y - pos_ini.y) == -1) { //Movimiento para avanzar normal hacia delante
			return true;
		}
		else 
			return false;

	}


}

bool Peon::movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c) {

	//Movimiento piezas blancas (igual para las negras)
	if (colour == color::BLANCA) {
		// if (abs(pos_fin.x - pos_ini.x) == 1 && (pos_fin.y - pos_ini.y) == 1) return true;
		if (pos_ini.y == 1) { //Primer movimiento
			if ((pos_fin.x - pos_ini.x) == 0 && ((pos_fin.y - pos_ini.y) == 1 || (pos_fin.y - pos_ini.y) == 2)) {
				return true;
			}
		}
		else if ((pos_fin.x - pos_ini.x) == 0 && (pos_fin.y - pos_ini.y) == 1) { //Movimiento para avanzar normal hacia delante
			return true;
		}
		else if (c == NEGRA && abs((pos_fin.x - pos_ini.x)) == 1 && (pos_fin.y - pos_ini.y) == 1) {  //Movimiento para comer, limitado en la clase interacción cuando no detecta una pieza que comer
			return true;
		}
		else
			return false;

	}
	//Idem Negras

	else if (colour == color::NEGRA) {
		// if (abs(pos_fin.x - pos_ini.x) == 1 && (pos_fin.y - pos_ini.y) == 1) return true;
		if (pos_ini.y == 6) { // primer movimiento negras
			if ((pos_fin.x - pos_ini.x) == 0 && ((pos_fin.y - pos_ini.y) == -1 || (pos_fin.y - pos_ini.y) == -2)) {
				return true;
			}

		}
		else if ((pos_fin.x - pos_ini.x) == 0 && (pos_fin.y - pos_ini.y) == -1) //Movimiento para avanzar normal hacia delante NEGRAS
			return true;

		else if (c == BLANCA && abs((pos_fin.x - pos_ini.x)) == 1 && (pos_fin.y - pos_ini.y) == -1) { // COMER PIEZA BLANCA
			return true;
		}else return false;
		

	}
}

color Peon::getCol() const{
	if (colour == color::BLANCA) {
		return color::BLANCA;
	}
	else if (colour == color::NEGRA) {
		return color::NEGRA;
	}

}
char Peon::getTipo() {
	return 'P';

}