#include"Rey.h"
void Rey::dibujar(int) {

}
bool Rey::movimiento(Vector2D pos_ini, Vector2D pos_fin) {
	//No permite realizar desplazamientos de m�s de una casilla con el rey
	if ((abs(pos_fin.x - pos_ini.x) == 1 || abs(pos_fin.y - pos_ini.y) == 1)) {
		return true;
	}                                                   
	else { 
		return false; 
	}
	//Habr�a que limitar movimiento cuando no pueda desplazar el Rey porque estar�a en jaque
}