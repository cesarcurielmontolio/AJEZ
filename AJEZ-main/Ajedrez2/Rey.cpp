#include"Rey.h"
void Rey::dibujar() {

}
bool Rey::movimiento(Vector2D pos_ini, Vector2D pos_fin, color c_destino) {
	//No permite realizar desplazamientos de m�s de una casilla con el rey
	if ((abs(pos_fin.x - pos_ini.x) == 1 || abs(pos_fin.y - pos_ini.y) == 1)) {
		return true;
	}
	else {
		return false;
	}
}

Movimiento Rey::getMov(Vector2D pos_ini, Vector2D pos_fin) {
	
	Movimiento mov;   //Misma situaci�n que con el caballo. Solo mueve a la posici�n final si la funci�n bool retorna verdadero

	return mov;  
}