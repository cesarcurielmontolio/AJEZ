#include"Peon.h"
void Peon::dibujar() {

}
bool Peon::movimiento(Vector2D pos_ini, Vector2D pos_fin) {
	//Movimiento piezas blancas (igual para las negras)
	if (colour == color::BLANCA) {
		if (colour == color::NO_DEFINIDO) { //No tenemos ninguna pieza delante
			if ((pos_fin.x - pos_ini.x) == 0 && (pos_fin.y - pos_ini.y) == 1) { //Movimiento para avanzar normal hacia delante
				return true;
			}
			else if (pos_ini.y == 1) { //Movimiento inicial (opción de mover 1 o 2 casillas). Peones situados en la segunda casilla del tablero (pos 1)
				if ((pos_fin.x - pos_ini.x) == 0 && ((pos_fin.y - pos_ini.y) == 1 || (pos_fin.y - pos_ini.y) == 2)) {
					return true;
				}
			}
			else return false;
		}
		else if (colour == color::NEGRA) { //Movimiento para comer una pieza (dcha o izq, utilizando la función absoluto)
			if ((abs(pos_fin.x - pos_ini.x) == 1) && (pos_fin.y - pos_ini.y) == 1) {
				return true;
			}
			else return false;
		}
	}
	//Idem Negras

	else if (colour == color::NEGRA) {
		if (colour == color::NO_DEFINIDO) { //No tenemos ninguna pieza delante
			if ((pos_fin.x - pos_ini.x) == 0 && (pos_fin.y - pos_ini.y) == 1) { //Movimiento para avanzar normal hacia delante
				return true;
			}
			else if (pos_ini.y == 1) { //Movimiento inicial (opción de mover 1 o 2 casillas). Peones situados en la segunda casilla del tablero (pos 1)
				if ((pos_fin.x - pos_ini.x) == 0 && ((pos_fin.y - pos_ini.y) == 1 || (pos_fin.y - pos_ini.y) == 2)) {
					return true;
				}
			}
			else return false;
		}
		else if (colour == color::NEGRA) { //Movimiento para comer una pieza (dcha o izq, utilizando la función absoluto)
			if ((abs(pos_fin.x - pos_ini.x) == 1) && (pos_fin.y - pos_ini.y) == 1) {
				return true;
			}
			else return false;

		}
	}

	
}
Movimiento Peon::getMov(Vector2D pos_ini, Vector2D pos_fin) {
	

}