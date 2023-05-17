#include "Mundo.h"
Mundo::Mundo() {

	Mundo::n = INICIO;
}

void Mundo::Dibuja() {
	
}

void Mundo::Inicializa() { //Se da valor a las coordenadas para definir la perspectiva

	x_ojo = 7,5;
	y_ojo = 7,5;
	z_ojo = 30;
}

void Mundo::Tecla(unsigned char key) {
	switch (key) {
		case '0': { //menu de inicio
			if (key == '1') {
				n = JUEGO;
			}
			if (key == '2') {
				n = PAUSA;
			}
			if (key == '3') { //sale del juego
				n = SALIR;
				exit(0); 
			}	
		}

	}
}

void Mundo::Mueve() {


}
