#include"Alfil.h"
void Alfil::dibujar(int) {

}
bool Alfil::movimiento(Vector2D pos_ini, Vector2D pos_fin, int blancas, int negras) {

	if (blancas == Pieza::BLANCA) {
		if ((pos_fin.y > pos_ini.y) && (pos_fin.x > pos_ini.x)) { //Movimientos diagonal positivo en x e y (dcha ascendente). Se incrementan ambos valores
			int i = pos_ini.x + 1;
			int j = pos_ini.y + 1;
			for (int i; i < pos_fin.x; i++) {
				for (int j; j < pos_fin.y; j++) {
					//Restricción si encuentra pieza igual que con la torre

				}
			}
		}
		else if ((pos_fin.y > pos_ini.y) && (pos_fin.x < pos_ini.x)) { //Movimientos diagonal positivo en y, negativo en x (izq ascedente)
			int i = pos_ini.x - 1;
			int j = pos_ini.y + 1;
			for (int i; i > pos_fin.x; i--) {
				for (int j; j < pos_fin.y; j++) {
					//Restricción si encuentra pieza igual que con la torre

				}
			}
		}
		else if ((pos_fin.y < pos_ini.y) && (pos_fin.x > pos_ini.x)) { //Movimiento izq descendente
			int i = pos_ini.x + 1;
			int j = pos_ini.y - 1;
			for (int i; i < pos_fin.x; i++) {
				for (int j; j > pos_fin.y; j--) {
					//Restricción si encuentra pieza igual que con la torre

				}
			}
		}
		else if ((pos_fin.y < pos_ini.y) && (pos_fin.x < pos_ini.x)) { //Mov izq descendente
			int i = pos_ini.x - 1;
			int j = pos_ini.y - 1;
			for (int i; i > pos_fin.x; i--) {
				for (int j; j > pos_fin.y; j--) {
					//Restricción si encuentra pieza igual que con la torre

				}
			}
		}
	}
	else if (negras == Pieza::NEGRA) {
		//Idem
	}
}