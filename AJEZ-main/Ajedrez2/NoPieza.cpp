#include "NoPieza.h"


void NoPieza::dibujar() {

}
bool NoPieza::movimiento(Vector2D pos_ini, Vector2D pos_fin) {
	return false; //No realiza el mov porque no hay pieza
}

bool NoPieza::movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c) {
	return false;
}

color NoPieza::getCol() const {
	
	return color::NO_DEFINIDO;
	

}
char NoPieza::getTipo() {
	return 'N';

}