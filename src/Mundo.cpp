#include "Mundo.h"
#include "freeglut.h"
#include "Interaccion.h"
#include "ETSIDI.h"
#include <iostream>
#include <math.h>

#define MAX_2 2
#define NP 8

int i = 0;

void Mundo::rotarOjo()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
//dibujo del suelo

/*glDisable(GL_LIGHTING);
glBegin(GL_POLYGON);
	glColor3ub(255,0,0);
	glVertex3f(-5.0f,0,-5.0f);
	glVertex3f(-5.0f,0,5.0f);
	glColor3ub(255,255,0);
	glVertex3f(5.0f, 0, 5.0f);
	glVertex3f(5.0f,0,-5.0f);
glEnd();
glEnable(GL_LIGHTING);*/
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("Ajedrez estrepitoso", -11, 17);
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("EquipoZ - Informática Industrial ", 3.5, 17);


	tablero.dibuja();

	peonesB.dibuja();
	caballosN.dibuja();

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

}


void Mundo::teclaMueve(unsigned char key)
{
	
	Vector2D vPosInicial= selector.posicionInicial;
	
	int i = selector.getPieza(vPosInicial);
	Vector2D v = selector.getPos();
	selector.mueve(key); 
	
	Vector2D vPosCInicial = caballosN.escoge(vPosInicial);
		caballosN.mueve(key, vPosCInicial, vPosInicial);
	
	
	peonesB.mueve(key, v);
	
	switch (i)
	{
		case '1':

			break;
		case '2':

			break;
		case '3':

			break;
		case '4':
			//caballosN.mueve(key, v, vPosInicial);
			break;
		case '5':

			break;
		case '6':
			peonesB.mueve(key, v);
			break;
	}

}

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 0;
	z_ojo = 70;

	//tablero inicial con todos sus componentes:  



	//PEONES BLANCOS

	/*
		for (int i = 0; i < NP; i++) {
		PeonB* aux = new PeonB(inicio, 13);
		peonesB.agregar(aux);
			inicio += 6;
	}
	*/

	//CABALLOS NEGROS
	/*
	int inicioc = -18;
	for (int i = 0; i <= MAX_2; i++)
	{

		CaballoN* aux = new CaballoN(inicioc, -22);
		caballosN.agregar(aux);
		inicioc += 31;
	}
	*/
	// Inicializar de este modo todas las piezas para comenzar la partida. 
	for (int i = -22; i <= 20; i++)
	{
		if (i == -16 || i == 14) {
			CaballoN* aux = new CaballoN(i, -22);
			caballosN.agregar(aux);
		}
		if (i == -22 || i == -16 || i == -10 || i == -4 || i == 2 || i == 8 || i == 14 || i == 20)
		{
			PeonB* aux = new PeonB(i, 14);
			peonesB.agregar(aux);
		}
	}
}


Mundo::~Mundo()
{

}

void Mundo::teclaSeleccion(unsigned char key)
{

	//caballosN.mueve(key);
	selector.mueve(key);
	//caballosN.mueve(key, selector.getPos());

	switch (key)
	{
	case 'p':
		peonesB.seleccionPieza(key);

	}
}

void Mundo::guardaPos()
{
	selector.setPosInicial(selector.getPos());
	

}
