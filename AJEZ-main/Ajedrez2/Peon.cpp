#include"Peon.h"
void Peon::dibujar() {

}
bool Peon::movimiento(Vector2D pos_ini, Vector2D pos_fin, color c_destino) {
	//Movimiento piezas blancas (igual para las negras)
	if (colour == color::BLANCA) {
		if (c_destino == color::NO_DEFINIDO) { //No tenemos ninguna pieza delante
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
		else if (c_destino == color::NEGRA) { //Movimiento para comer una pieza (dcha o izq, utilizando la función absoluto)
			if ((abs(pos_fin.x - pos_ini.x) == 1) && (pos_fin.y - pos_ini.y) == 1) {
				return true;
			}
			else return false;
		}
	}
	//Idem Negras

	else if (colour == color::NEGRA) {
		if (c_destino == color::NO_DEFINIDO) { //No tenemos ninguna pieza delante
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
		else if (c_destino == color::NEGRA) { //Movimiento para comer una pieza (dcha o izq, utilizando la función absoluto)
			if ((abs(pos_fin.x - pos_ini.x) == 1) && (pos_fin.y - pos_ini.y) == 1) {
				return true;
			}
			else return false;

		}
	}

	
}
Movimiento Peon::getMov(Vector2D pos_ini, Vector2D pos_fin) {
	
	Movimiento mov;
	Vector2D desp(0, 0); //Inicializamos el desplazamiento a 0 en ambos sentidos
	Vector2D origen = pos_ini; //Guardamos en origen la posición inicial

	if (pos_fin.x != pos_ini.x) { //Mov eje x
		if (pos_fin.x > pos_ini.x) {
			desp.x = 1; //Desplazamiento positivo en el eje x de la matriz
		}
		else {
			desp.x = -1;
		}
	}
	else if (pos_fin.y != pos_ini.y) { //Mov eje y
		if (pos_fin.y > pos_ini.y) {
			desp.y = 1; //Desplazamiento positivo en el eje y de la matriz
		}
		else {
			desp.y = -1;
		}
	}
	while (origen != pos_fin) { //Hay que hacer la sobrecarga del operador 
		
		if (pos_fin.y != origen.y) {
			origen.y += desp.y; //Desplazamiento normal. Incrementa coord y

			if (pos_fin.x != origen.x) { //Come pieza. Se incrementan ambas coord.
				origen.x += desp.x;
			}
		}
		mov.insertarMov(origen);
	}
	return mov;
}