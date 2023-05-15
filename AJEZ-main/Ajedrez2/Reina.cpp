#include"Reina.h"
void Reina::dibujar() {

}
bool Reina::movimiento(Vector2D pos_ini, Vector2D pos_fin, color c_destino) {
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

Movimiento Reina::getMov(Vector2D pos_ini, Vector2D pos_fin) {
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
		//Mov torre
		if (pos_fin.x != origen.x) {
			origen.x += desp.x;
		}
		else if (pos_fin.y != origen.y) {
			origen.y += desp.y;
		}

		//Mov alfil
		else if (abs(pos_fin.x - origen.x) == abs(pos_fin.y - origen.y)) {
			origen.x += desp.x;
			origen.y += desp.y;
		}
		mov.insertarMov(origen);
	}
	return mov;
}