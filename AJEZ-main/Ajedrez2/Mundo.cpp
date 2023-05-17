#include "Mundo.h"
Mundo::Mundo() {

	Mundo::n = INICIO;
}

void Mundo::Dibuja() {
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
	b.draw(); 
}

void Mundo::Inicializa() { //Se da valor a las coordenadas para definir la perspectiva


	x_ojo = 24;
	y_ojo = 24;
	z_ojo = 70;
	
  
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

