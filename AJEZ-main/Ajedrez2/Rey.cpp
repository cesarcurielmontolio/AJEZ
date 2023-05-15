#include"Rey.h"
void Rey::dibujar() {

}
bool Rey::movimiento(Vector2D pos_ini, Vector2D pos_fin, color c_destino) {
	//No permite realizar desplazamientos de más de una casilla con el rey
	if ((abs(pos_fin.x - pos_ini.x) == 1 || abs(pos_fin.y - pos_ini.y) == 1)) {
		return true;
	}
	else {
		return false;
	}
}

Movimiento Rey::getMov(Vector2D pos_ini, Vector2D pos_fin) {
	
	Movimiento mov;   //Misma situación que con el caballo. Solo mueve a la posición final si la función bool retorna verdadero

	return mov;  
}