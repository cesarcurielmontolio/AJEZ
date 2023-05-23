#pragma once
#include "Tablero.h"

#include "ListaCaballosN.h"
#include "CaballoN.h"
#include "Selector.h"
#include "Casilla.h"
#include"Torre.h"

class Mundo
{
private:
	// variables de la posicion de la cámara
	float x_ojo;
	float y_ojo;
	float z_ojo;
	// variables a utilizar para el uso del ratón
	float mousex, mousey;
	bool mouseleftdown; 
	bool mouserightdown;
	

	//ListaPeonesB peonesB;
	ListaCaballosN caballosN;

	Tablero tablero;
	//PeonB peonB;
	// CaballoN caballoN;
	Selector selector;
	Casilla c;

public:
	virtual ~Mundo();
	void teclaSeleccion(unsigned char key);
	void teclaMueve(unsigned char key);
	void inicializa();
	
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
	void guardaPos();


	bool inTablero(float  x, float y); // saber si se clica dentro del tablero o no 



	// USO DEL RATÓN EN LA PANTALLA 

	void mouseFunc(int button, int state, int x, int y);
	Vector2D getMouseCas(int x, int y); // Averiguar que casilla se selecciona con el raton sea cual sea el tamaño de la pantalla
	void motionFunc(int x, int y);


	
};
