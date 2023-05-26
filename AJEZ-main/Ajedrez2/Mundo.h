#pragma once
#include "Tablero.h"
#include "Selector.h"
#include "Casilla.h"
#include"Torre.h"
#include "Interaccion.h"
#define MAX_2 2
#define NP 8

class Mundo
{
private:
	// variables de la posicion de la cámara
	float x_ojo;
	float y_ojo;
	float z_ojo;
	// variables a utilizar para el uso del ratón
	float mousex, mousey;
	
	friend class Tablero;
	friend class Casilla;


	Tablero tablero;
	Selector selector;
	Casilla c;
protected:
	
public:
	/*POR COMO FUNCIONAN LAS FUNCIONES DE MOVIMIENTO*/
	friend class Alfil;
	friend class Torre;
	friend class Reina;
	
	
	int i = 0;
	Vector2D casi; // se deben inicializar en el mundo.h;
	Vector2D pos_fin;
	Vector2D pos_ini;
	virtual ~Mundo();
	
	
	void inicializa();
	
	void mueve(color c);
	void dibuja();
	void dibujaSW();
	void teclaEspecial(unsigned char key);
	void guardaPos();
	void reset();

	bool inTablero(float  x, float y); // saber si se clica dentro del tablero o no 
	bool checkTurno (color col);
	bool checkRecorridos();
	bool checkJaque();
	bool checkMate();

	bool estaEnJaque(Vector2D pos_ini, Vector2D pos_fin);
	bool jaqueMate();


	//boolclicCorrecto()

	// USO DEL RATÓN EN LA PANTALLA 

	void mouseFunc(int button, int state, int x, int y);
	Vector2D getMouseCas(int x, int y); // Averiguar que casilla se selecciona con el raton sea cual sea el tamaño de la pantalla
	void motionFunc(int x, int y);


	
};
