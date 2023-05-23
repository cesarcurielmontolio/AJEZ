#include "Mundo.h"
#include "freeglut.h"
#include "Interaccion.h"
#include "ETSIDI.h"
#include <iostream>
#include <math.h>
 
#define MAX_2 2
#define NP 8

int i = 0;
Vector2D casi; // se deben inicializar en el mundo.h;
Vector2D pos_fin;
Vector2D pos_ini;
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo



	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("Ajedrez estrepitoso", -11, 17);
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("EquipoZ - Informática Industrial ", 3.5, 17);


	tablero.dibuja();

	if (!tablero.estaInicializado()) {
		tablero.init();
	}
	//peonesB.dibuja();
	//caballosN.dibuja();

	//caballoN.dibuja();
	//peonB.dibuja();
	selector.dibuja();
}

void Mundo::teclaEspecial(unsigned char key)
{

	//caballosN.mueve(key);
	switch (key)
	{
	case GLUT_KEY_LEFT:
		//caballosN.mueve(key);
		break;
	case GLUT_KEY_RIGHT:
		//caballosN.mueve(key);
		break;

	}
}

void Mundo::mueve()
{
	tablero.muevePieza(Vector2D (pos_ini), Vector2D (pos_fin));
}


void Mundo::teclaMueve(unsigned char key)
{
	
	
}

void Mundo::inicializa()
{
	x_ojo = 4;
	y_ojo = 4;
	z_ojo =15;

	//tablero inicial con todos sus componentes:  
}


Mundo::~Mundo()
{
	

	
}

void Mundo::teclaSeleccion(unsigned char key)
{

	//caballosN.mueve(key);
	//selector.mueve(key);
	//caballosN.mueve(key, selector.getPos());

	//selector.printCasilla(selector.getPos());// Imprime por pantalla la posicion de la casilla en la que se situa el Puntero. 
	
}

void Mundo::guardaPos()
{
	selector.setPosInicial(selector.getPos());
	

}

bool Mundo::inTablero(float x, float y)
{
	if (x < 0 || x>8 || y < 0 || y>8) { return false; }
	else {
		return true;
	}
}




void Mundo::mouseFunc(int button, int state, int x, int y)
{ 
	Vector2D v;
	mousex = x;
	mousey = y;
	
	
	if ((button == GLUT_LEFT_BUTTON) && (state== GLUT_DOWN)) 
	{
		
				v.x = getMouseCas(x, y).x; 
				v.y = getMouseCas(x, y).y;
			std::cout << "EL PIXEL CLICADO ES: (" << mousex << ", " <<mousey << ")" << endl;
		
				if (inTablero(v.x, v.y)==true) 
				{
					std::cout << "La Casilla Clicada es: (" << (int) getMouseCas(x, y).x << ", " << (int)getMouseCas(x, y).y << ")" << endl;
					std::cout << "La Casilla Clicada es: (" << casi.x << ", " << casi.y << ")" << endl;
					std::cout << "La Ventana MIDE: (" << glutGet(GLUT_WINDOW_WIDTH) << ", " << glutGet(GLUT_WINDOW_HEIGHT) << ")" << endl;
					

				}else 

				std::cout << "Has pulsado fuera del tablero vuelve a intentarlo" << endl;

				// POSICION FINAL E INICIAL DE LA PIEZA SELECCIONADA. 
				// si i == 0 estamos diciendo que estamos seleccionando la casilla que movemos 
				// si i !=0 selecccionamos la siguente casilla donde moveremos la pieza. 
				
				if (i == 0) { 
					pos_ini = casi; // SE PODRÍA HACER UNNA FUNCION PARA DETECTAR SI LA POSICION INICIAL QUE CLICAS HAY UNA PIEZA O NO. 
					i++;
				}
				else { pos_fin = casi; i = 0; }
				
				
				



		if (inTablero(v.x, v.y) && i == 0) { // seleccionamos pieza para mover solo si se clica dentro del tablero y solo si hemos clicado dos veces 
			mueve();
		}
		}
		
		
		

		
	
}



Vector2D Mundo::getMouseCas(int x, int y) // funcion para saber que casilla es la que seleccionamos 
{
	Vector2D window;
	Vector2D cas;

	window.x = glutGet(GLUT_WINDOW_WIDTH);
	window.y = glutGet(GLUT_WINDOW_HEIGHT);
	float minx = window.x * 180 / 800; // Regla de 3 para sacar la esquina superior del tablero en pixeles usando los datos de la pantalla 800 x 600 
	float miny = window.y * 80 / 600; // Idem pero con la y 
	// para poder variar el ancho de la pantalla realizamos una modificación para cada ventana. 
	 cas.x = (window.x - minx - minx) / 8; 
	 cas.y = (window.y - miny - miny) / 8;


	Vector2D v;
	
	 
	v.x = (x - minx)/cas.x;
	v.y = (y - miny) /cas.y; // Si lo dejamos asi la casilla (0,0) Será la suerior izquierda 

	// Ahora recolocamos la casilla inferior izquierda a (0,0) 
	v.y -= 8;
	v.y *= -1; 
	casi.x = (int) v.x;
	casi.y = (int)v.y;
	return v;
	
}

void Mundo::motionFunc(int x, int y)
{
}





