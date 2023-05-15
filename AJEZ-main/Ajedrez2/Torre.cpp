#include"Torre.h"
void Torre::dibujar() {

}
bool Torre::movimiento(Vector2D pos_ini, Vector2D pos_fin) {

	//Movimientos verticales (eje y, no cambia posición en x)
	if ((pos_fin.x == pos_ini.x) && (pos_fin.y != pos_ini.y)) { //Movimiento ascendente o descendente
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

Movimiento Torre::getMov(Vector2D pos_ini, Vector2D pos_fin) {


}