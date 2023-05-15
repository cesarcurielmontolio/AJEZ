#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
Mundo::Mundo() {
}
Mundo::~Mundo() {
	
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
	cargarNivel();
}

void Mundo::Tecla(unsigned char key) {
	switch (key) {
	case ' ':
	{

		break;
	}
	}
}

void Mundo::Mueve() {


}

bool Mundo::cargarNivel() {
	
}
