#include"Peon.h"
void Peon::dibujar(int) {

}
bool Peon::movimiento(Vector2D pos_ini, Vector2D pos_fin, int blancas, int negras) {
	//Movimiento piezas blancas (igual para las negras)
	if (blancas == Pieza::BLANCA) {
		if (negras == Pieza::NO_DEFINIDO) { //No tenemos ninguna pieza delante
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
		else if (negras == Pieza::NEGRA) { //Movimiento para comer una pieza (dcha o izq, utilizando la función absoluto)
			if ((abs(pos_fin.x - pos_ini.x) == 1) && (pos_fin.y - pos_ini.y) == 1) {
				return true;
			}
			else return false;
		}
	}
	else if (negras == Pieza::NEGRA) {
		//idem
	}

	//Se podría añadir la promoción del peón cuando llegamos a la última fila
}