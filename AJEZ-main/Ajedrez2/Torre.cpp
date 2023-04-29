#include"Torre.h"
void Torre::dibujar(int) {

}
bool Torre::movimiento(Vector2D pos_ini, Vector2D pos_fin, int blancas, int negras) {

	if (blancas == Pieza::BLANCA) {
		//Movimientos verticales (eje y, no cambia posición en x)
		if ((pos_fin.x == pos_ini.x) && (pos_fin.y > pos_ini.y)) { //Movimiento ascendente, se incrementa la y inicial hasta la final.
			int i = pos_ini.y + 1;
			for (i; i < pos_fin.y; i++) {
				//Poner restricción cuando encuentre una pieza en el camino. Si es del color contrario come y sino no puede pasar
			}
		}

		else if ((pos_fin.x == pos_ini.x) && (pos_fin.y < pos_ini.y)) { //Movimiento descendente
			int i = pos_ini.y - 1;
			for (i; i > pos_fin.y; i--) {

			}

		}
		//Movimientos horizontale (eje x, no cambia pos en y)
		else if ((pos_fin.y == pos_ini.y) && (pos_fin.x > pos_ini.x)){  //Desplazamiento hacia la dcha
			//Idem
		}
		else if ((pos_fin.y == pos_ini.y) && (pos_fin.x < pos_ini.x)) { //Desplazamiento izquierda
			//Idem
		}
	}
	else if (negras == Pieza::NEGRA) { //Igual para el movimientos de las torres negras

	}


}