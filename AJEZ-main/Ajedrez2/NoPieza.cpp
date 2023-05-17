#include"NoPieza.h"

void NoPieza::dibujar() {

}
bool NoPieza::movimiento(Vector2D pos_ini, Vector2D pos_fin) {
	return false; //No realiza el mov porque no hay pieza
}
Movimiento NoPieza::getMov(Vector2D pos_ini, Vector2D pos_fin) { //No realiza movimiento
	Movimiento mov;
	return mov;
}
