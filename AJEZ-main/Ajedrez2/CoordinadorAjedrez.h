#pragma once
#include "Mundo.h"


class CoordinadorAjedrez {
public:
	CoordinadorAjedrez();
	virtual ~CoordinadorAjedrez();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	
	
	void mouseFunc(int button, int state, int x, int y);
	void mueve();
	void dibuja();
protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO, MUEVE, PAUSA, JUEGOSW, JUEGAN_BLANCAS, JUEGAN_NEGRAS};  //Estados de juego de la máquina de estados
	enum Turno {BLANCAS, NEGRAS};  //Se encarga de gestionar los turnos
	enum Partida{JAQUEN, JAQUEB, MATE};  //Para la detección del jaque
	Estado estado;
	Turno turno;
	Partida partida;
};





