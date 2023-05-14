#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
Mundo::Mundo() {
}
Mundo::~Mundo() {
	
}

void Mundo::Dibuja() {
	
}

void Mundo::Inicializa() { //Se da valor a las coordenadas para definir la perspectiva

	x_ojo = 7,5;
	y_ojo = 7,5;
	z_ojo = 30;
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