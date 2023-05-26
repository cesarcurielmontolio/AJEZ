#pragma once
#include "Tablero.h"
#include "ETSIDI.h"
#include "freeglut.h"

#include "Pieza.h"


bool okMOV= false;
#define LADO 8 
using namespace std;

Tablero::Tablero() : inicializado(false) //Constructor clase board. Se construye con las casillas vacías 
{
	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {  //Se crea el tablero vacío sin piezas
			c[i][j].setPieza(new NoPieza(NO_DEFINIDO, VACIA, Vector2D(i,j)));
		}
	}
}

Tablero::Tablero(int a, int b, Vector2D v)
{
	a = 2;
	b = 6;
	v.x = 0;
	v.y = 0;
	
	
}

void Tablero::init()
{
	
	for (int i = 0; i < LADO; i++) {  //Se inicializan las piezas en el tablero. He puesto los dos casos,
									//tanto si tenemos clases derivadas de cada pieza por color, como si especificamos el color y tipo en la propia clase de cada pieza
		for (int j = 0; j < LADO; j++) {  
			c[i][j].setPieza(new NoPieza (NO_DEFINIDO, VACIA, Vector2D(i, j)));	 //Se inicializa el tablero sin piezas	
									 
		}
	}
	// PIEZAS BLANCAS
	//Torres
	c[0][0].setPieza(new Torre(color::BLANCA, tipo::TORRE, Vector2D(0, 0))); //Origen del tablero. La matriz crece en el sentido positivos de x e y.
	//c[0][0].setPieza(new TorreBlanca());
	c[7][0].setPieza(new Torre(BLANCA,TORRE, Vector2D(7, 0)));
	//c[7][0].setPieza(new TorreBlanco());
	//Alfiles
	c[2][0].setPieza(new Alfil(BLANCA, ALFIL, Vector2D(2, 0)));
	//c[2][0].setPieza(new AlfilBlanco());
	c[5][0].setPieza(new Alfil(color::BLANCA, tipo::ALFIL, Vector2D(5, 0)));
	//c[5][0].setPieza(new AlfilBlanco());
	// 
	//Rey y Reina
	c[4][0].setPieza(new Rey(color::BLANCA, tipo::REY, Vector2D(4, 0)));
	//c[4][0].setPieza(new ReyBlanco());
	c[3][0].setPieza(new Reina(color::BLANCA, tipo::REINA, Vector2D(3, 0)));
	//c[3][0].setPieza(new ReinaBlanca());

	
	//Caballos
	c[1][0].setPieza(new Caballo (BLANCA, CABALLO, Vector2D(1, 0)));
	//c[1][0].setPieza(new CaballoBlanco());
	c[6][0].setPieza(new Caballo (color::BLANCA, tipo::CABALLO, Vector2D(6, 0)));
	//c[6][0].setPieza(new CaballoBlanco());
	
	//PIEZAS NEGRAS 
	//Torres
	c[0][7].setPieza(new Torre(color::NEGRA, tipo::TORRE, Vector2D(0, 7)));
	//c[0][7].setPieza(new TorreNegra());
	c[7][7].setPieza(new Torre(color::NEGRA, tipo::TORRE, Vector2D(7, 7)));
	//c[7][7].setPieza(new TorreNegra());

	//Caballos
	c[1][7].setPieza(new Caballo(color::NEGRA, tipo::CABALLO, Vector2D(1, 7)));
	//c[1][7].setPieza(new CaballoNegro());
	c[6][7].setPieza(new Caballo(color::NEGRA, tipo::CABALLO, Vector2D(6, 7)));
	//c[6][7].setPieza(new CaballoNegro());

	//Alfiles
	c[2][7].setPieza(new Alfil(color::NEGRA, tipo::ALFIL, Vector2D(2, 7)));
	//c[2][7].setPieza(new AlfilNegro());
	c[5][7].setPieza(new Alfil(color::NEGRA, tipo::ALFIL, Vector2D(5, 7)));
	//c[5][7].setPieza(new AlfilNegro());

	//Rey y Reina
	c[4][7].setPieza(new Rey(color::NEGRA, tipo::REY, Vector2D(4, 7)));
	//c[4][7].setPieza(new ReyNegro());
	c[3][7].setPieza(new Reina(color::NEGRA, tipo::REINA, Vector2D(3, 7)));
	//c[3][7].setPieza(new ReinaNegra());

	//Inicialización peones
	//Blancos
	for (int i = 0; i < LADO; i++) {
		int j = 1;  //Segunda fila de nuestra matriz tablero
		c[i][j].setPieza(new Peon(color::BLANCA, tipo::PEON, Vector2D(i, j)));
		//c[i][j].setPieza(new PeonBlanco());
	}


	//Negros
	for (int i = 0; i < LADO; i++) {
		int j = 6;  //En la sexta fila, que es la segunda para las piezas negras
		c[i][j].setPieza(new Peon(color::NEGRA, tipo::PEON, Vector2D(i, j)));
		//c[i][j].setPieza(new PeonNegro());
	}

	inicializado = true;
	
}



Tablero::~Tablero()
{

}

void Tablero::dibuja()
{
	
	// Dibujo de la base del tablero por casillas 

	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {
			
			
			c[i][j].dibujarCasilla();
			
		}
	}

	//DIBUJO DEL MARCO DEL TABLERO
	// No se muy bien para que es necesario 
	glDisable(GL_LIGHTING);
		glColor3ub(137, 107, 73);
		glBegin(GL_QUADS);
		glVertex3f(0.0, 0.0, -0.1f);
		glVertex3f(8.0f, -0.0, -0.1f);
		glVertex3f(8.0f, 8.0f, -0.1f);
		glVertex3f(0.0, 8.0f, -0.1f);
		glEnd();
	
		// prueba del tamaño de las casillas 
		// cada casilla dibujo 
	glColor3ub(137, 107, 73);
		glBegin(GL_QUADS);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(2, 1, 0);
		glVertex3f(2, 0, 0);
		glEnd(); 
		

	//dibujo del fondo TABLERO DE AJEDREZ 
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.4.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(0, 8, 0);
	glTexCoord2d(1, 1); glVertex3f(8, 8, 0);
	glTexCoord2d(1, 0); glVertex3f(8, 0, 0);
	glTexCoord2d(0, 0); glVertex3f(0, 0, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	
	// SI ESTA INICIALIZADO Y CADA CASILLA CREADA SE EMPIEZAN A DIBUJAR TODAS LAS CASILLAS. 

	if (estaInicializado()) {

		for (int i = 0; i < LADO; i++){
			for (int j = 0; j < LADO; j++) {
				c[i][j].getPieza()->dibujar();
			}
			
		}
	}

}

void Tablero::dibujaSW()
{
	// Dibujo de la base del tablero por casillas 

	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {


			c[i][j].dibujarCasilla();

		}
	}

	//DIBUJO DEL MARCO DEL TABLERO
	// No se muy bien para que es necesario 
	glDisable(GL_LIGHTING);
	glColor3ub(137, 107, 73);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, -0.1f);
	glVertex3f(8.0f, -0.0, -0.1f);
	glVertex3f(8.0f, 8.0f, -0.1f);
	glVertex3f(0.0, 8.0f, -0.1f);
	glEnd();

	// prueba del tamaño de las casillas 
	// cada casilla dibujo 
	glColor3ub(137, 107, 73);
	glBegin(GL_QUADS);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(2, 1, 0);
	glVertex3f(2, 0, 0);
	glEnd();


	//dibujo del fondo TABLERO DE AJEDREZ 

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.4.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(0, 8, 0);
	glTexCoord2d(1, 1); glVertex3f(8, 8, 0);
	glTexCoord2d(1, 0); glVertex3f(8, 0, 0);
	glTexCoord2d(0, 0); glVertex3f(0, 0, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	// SI ESTA INICIALIZADO Y CADA CASILLA CREADA SE EMPIEZAN A DIBUJAR TODAS LAS CASILLAS. 

	if (estaInicializado()) {

		for (int i = 0; i < LADO; i++) {
			for (int j = 0; j < LADO; j++) {
				c[i][j].getPieza()->dibujarSW();
			}

		}
	}




}

bool Tablero::maniobraValidada(char pieza, Vector2D pos_ini, Vector2D pos_fin)
{
	// Aquí implementa la lógica para verificar si la pieza puede atacar la posición objetivo
	int filaDif = abs(pos_fin.x - pos_ini.x);
	int colDif = abs(pos_fin.y - pos_ini.y);
	switch (pieza) {
	case 'T': // Torre

		// La torre puede atacar en la misma fila o columna
		return (pos_ini.x == pos_fin.x) || (pos_ini.y == pos_fin.y);

	case 'A': // Alfil

		// El alfil puede atacar en la misma diagonal
		return filaDif == colDif;

	case 'Q': // Reina

		// La reina puede atacar en la misma fila, columna o diagonal
		return (pos_ini.x == pos_fin.x) || (pos_ini.y == pos_fin.y) || (filaDif == colDif);

	case 'C': // Caballo

		// El caballo puede atacar en forma de L en todas las direcciones posibles
		return (filaDif == 2 && colDif == 1) || (filaDif == 1 && colDif == 2);

	case 'P': // Peón (solo verificando ataque diagonal hacia arriba)

		// El peón puede atacar en diagonal hacia arriba
		return (pos_ini.y - pos_fin.y == 1 || pos_ini.y - pos_fin.y == -1) &&
			(pieza == 'P' && pos_ini.x - pos_fin.x == 1) ||
			(pieza == 'p' && pos_ini.x - pos_fin.x == -1);

	default:
		return false;
	}
}


/*bool Tablero::estaEnJaque(char rey) {
	Vector2D posRey = obtenerPos(rey);

	// Iterar sobre las piezas enemigas
	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {
			if (c[i][j].getPieza()->getCol() == color::BLANCA) {
				Vector2D posPieza = obtenerPos(BLANCA);

				// Verificar si la pieza enemiga puede atacar al rey
				if (maniobravalida(BLANCA, posPieza, posRey)) {
					return true; // El rey está en jaque
				}
			}
		}
	}
	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {
			if (c[i][j].getPieza()->getCol() == color::NEGRA) {
				Vector2D posPieza = obtenerPos(BLANCA);

				// Verificar si la pieza enemiga puede atacar al rey
				if (maniobravalida(NEGRA, posPieza, posRey)) {
					return true; // El rey está en jaque
				}
			}
		}
	}

	return false; // El rey no está en jaque
}*/






void Tablero::muevePieza(Vector2D pos_ini, Vector2D pos_fin, color col) // Funcion para una vez obtenida la casilla llamar a la pieza que corresponde y moverla. 
{
	
	 // se comprobara si se puede mover ahi o no si hay piezas en la posicion de destino. 
	// de momento se mueve a cualquier lado. 
	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {

			if (i == pos_ini.x && j == pos_ini.y) {
				if (c[i][j].getPieza()->movimiento2(pos_ini, pos_fin, c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol())  /*&& okTurno(col, pos_ini) == true*/ ) {//... FUNCION PARA HACER EL MOVIMIENTO DE LA PIEZA DESPUES DE COMPROBAR QUE SE PUEDE REALIZAR. 
					std::cout << "MOVIMIENTO POSIBLE" << endl;
	
					okMOV = true;
					//c[i][j].getPieza()->setPos(pos_fin);


					//Movimiento BLANCAS
					if (c[i][j].getPieza()->getCol() == color::BLANCA) {
						if (c[i][j].getPieza()->getTipo() == 'T') {
							if (c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() == color::BLANCA) {
								std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;
							}
							else {
								c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Torre(color::BLANCA, tipo::TORRE, pos_fin));
								c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
							}
						}
						else if (c[i][j].getPieza()->getTipo() == 'C') {
							if (c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() == color::BLANCA) {
								std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;
							}
							else
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Caballo(color::BLANCA, tipo::CABALLO, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}
						else if (c[i][j].getPieza()->getTipo() == 'A') {
							if (c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() == color::BLANCA) {
								std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;
							}
							else
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Alfil(color::BLANCA, tipo::ALFIL, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}
						else if (c[i][j].getPieza()->getTipo() == 'K') {
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Rey(color::BLANCA, tipo::REY, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}
						else if (c[i][j].getPieza()->getTipo() == 'Q') {
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Reina(color::BLANCA, tipo::REINA, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}
						else if (c[i][j].getPieza()->getTipo() == 'P') {
							if (c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() == color::BLANCA) {
								std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;
							}
							else
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Peon(color::BLANCA, tipo::PEON, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}

					} // si seleccionnas ua pieza del color que no es tu turno el juego te avisa. 
					

					//Movimiento NEGRAS
					if (c[i][j].getPieza()->getCol() == color::NEGRA) {
						if (c[i][j].getPieza()->getTipo() == 'T') {
							if (c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() == color::NEGRA) {
								std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;
							}else
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Torre(color::NEGRA, tipo::TORRE, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}
						else if (c[i][j].getPieza()->getTipo() == 'C') {
							if (c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() == color::NEGRA) {
								std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;
							}
							else
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Caballo(color::NEGRA, tipo::CABALLO, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}
						else if (c[i][j].getPieza()->getTipo() == 'A') {
							if (c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() == color::NEGRA) {
								std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;
							}
							else
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Alfil(color::NEGRA, tipo::ALFIL, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}
						else if (c[i][j].getPieza()->getTipo() == 'K') {
							if (c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() == color::NEGRA) {
								std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;
							}
							else
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Rey(color::NEGRA, tipo::REY, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}
						else if (c[i][j].getPieza()->getTipo() == 'Q') {
							if (c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() == color::NEGRA) {
								std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;
							}
							else
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Reina(color::NEGRA, tipo::REINA, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}
						else if (c[i][j].getPieza()->getTipo() == 'P') {
							if (c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() == color::NEGRA) {
								std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;
							}
							else
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Peon(color::NEGRA, tipo::PEON, pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, pos_ini));
						}

					} // ciera el if que no le toca mover a las negras

				}
				else { std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl; okMOV = false; }// cierra el bool del chequeo de si el movimiento es correcto o no
				

				ETSIDI::play("sonidos/mov.mp3");
			}// cierra el if seleccionar pieza despues de recorrer la matriz

		}// cierra el for (j)

	} // cierra el for (i)
} // cierra la funcion mueve pieza

void Tablero::reset()
{



}


	





Vector2D Tablero::obtenerPos(Vector2D v) {
	int i = v.x;
	int j = v.y;
	return v; 
}




bool Tablero::estaInicializado() // FUNCION QUE COMPRUEBA SI SE HA INICIALIZADO EL TABLERO 
{
	return inicializado;
}




