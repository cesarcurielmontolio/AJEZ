#include "Pieza.h"
Vector2D Pieza::getPos() {
	return posicion;
}
int Pieza::getCoordX() {
	return posicion.x;
}
int Pieza::getCoordY() {
	return posicion.y;
}
void Pieza::setPos(Vector2D p) {
	posicion = p;
}
color Pieza::getCol() const {
	return colour;
}