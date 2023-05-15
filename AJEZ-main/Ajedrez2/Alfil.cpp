#include"Alfil.h"
void Alfil::dibujar() {

}
bool Alfil::movimiento(Vector2D pos_ini, Vector2D pos_fin) {
	//Al moverse en diagonal la diferencia absoluta de las coordenadas x e y debe coincidir siempre
	if (abs(pos_fin.x - pos_ini.x) == abs(pos_fin.y - pos_ini.y)) {
		return true;
	}
	else {
		return false;
	}
	//Movimiento para comer
}
Movimiento Alfil::getMov(Vector2D pos_ini, Vector2D pos_fin) {

}
	