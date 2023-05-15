#include"Torre.h"
void Torre::dibujar() {

}
bool Torre::movimiento(Vector2D pos_ini, Vector2D pos_fin, color c_destino) {

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

Movimiento Torre::getMov(Vector2D pos_ini, Vector2D pos_fin) {
	Movimiento mov;
	Vector2D desp(0, 0); //Inicializamos el desplazamiento a 0 en ambos sentidos
	Vector2D origen = pos_ini; //Guardamos en origen la posición inicial

	if (pos_fin.x != pos_ini.x) { //Mov eje x
		if (pos_fin.x > pos_ini.x) {
			desp.x = 1; //Desplazamiento positivo en el eje x de la matriz
		}
		else {
			desp.x = -1;
		}
	}
	else if (pos_fin.y != pos_ini.y) { //Mov eje y
		if (pos_fin.y > pos_ini.y) {
			desp.y = 1; //Desplazamiento positivo en el eje y de la matriz
		}
		else {
			desp.y = -1;
		}
	}

	//Se incrementa o decrementa según proceda hasta que llegue a la posición final
	while (origen != pos_fin) { //Hay que hacer la sobrecarga del operador 
		if (pos_fin.x != origen.x) {
			origen.x += desp.x;
		}
		else if (pos_fin.y != origen.y) {
			origen.y += desp.y;
		}
		mov.insertarMov(origen);
	}
	return mov;

}