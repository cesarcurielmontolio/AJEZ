#pragma once
#ifndef __CASILLA_H__
#define __CASILLA_H__
#include "vector2D.h"
#include "Pieza.h"
#include "Torre.h";

class Casilla {
	private: 
	Pieza* p; 


	public:
		Casilla(){}
		virtual ~Casilla() {}
		void dibujarCasilla();
		//Obtener pieza que hay en la casilla y colocarla
		void setPieza(Pieza* p);

		Pieza* getPieza();
		Vector2D getCasilla();

};
#endif 

	 
