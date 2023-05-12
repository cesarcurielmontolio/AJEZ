#include"Torre.h"
void Torre::dibujar(int) {

}
bool Torre::movimiento(Vector2D pos_ini, Vector2D pos_fin, int blancas, int negras) {

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
