#include"Caballo.h"
void Caballo::dibujar() {

}
bool Caballo::movimiento(Vector2D pos_ini, Vector2D pos_fin) {

	//Cuando se desplaza el caballo una posición (en cualquier sentido) en la dirección horizontal (eje x), se tiene que desplazar 2 casillas en el eje y
	if ((abs(pos_fin.x - pos_ini.x) == 1) && (abs(pos_fin.y - pos_ini.y) != 2)) {
		return false;
	}
	//Situación inversa, cuando solo se desplaza en el eje y una posición debe hacerlo 2 en el eje x
	else if ((abs(pos_fin.y - pos_ini.y) == 1) && (abs(pos_fin.x - pos_ini.x) != 2)) {
		return false;
	}
	//Rango de movimiento del caballo. No se puede desplazar en ningún eje más de 2 posiciones ni menos de 1
	else if ((1 > abs(pos_fin.x - pos_ini.x) > 2) || (1 > abs(pos_fin.y - pos_ini.y) > 2)) {
		return false;
	}
	else {
		return true;
	}
}

Movimiento Caballo::getMov(Vector2D pos_ini, Vector2D pos_fin) {


}
