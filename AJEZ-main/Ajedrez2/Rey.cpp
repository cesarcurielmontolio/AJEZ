#include"Rey.h"
void Rey::dibujar() {

}
bool Rey::movimiento(Vector2D pos_ini, Vector2D pos_fin) {
	//No permite realizar desplazamientos de más de una casilla con el rey
	if ((abs(pos_fin.x - pos_ini.x) == 1 || abs(pos_fin.y - pos_ini.y) == 1)) {
		return true;
	}
	else {
		return false;
	}
}

Movimiento Rey::getMov(Vector2D pos_ini, Vector2D pos_fin) {

}