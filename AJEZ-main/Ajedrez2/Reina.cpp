#include"Reina.h"
void Reina::dibujar() {

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

Movimiento Reina::getMov(Vector2D pos_ini, Vector2D pos_fin) {


}