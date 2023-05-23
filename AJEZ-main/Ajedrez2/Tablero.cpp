#pragma once
#include "Tablero.h"
#include "ETSIDI.h"
#include "freeglut.h"

#include "Pieza.h"



#define LADO 8 
using namespace std;

int k = 0;
int c = 0; 

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

void Tablero::muevePieza(Vector2D pos_ini, Vector2D pos_fin) // Funcion para una vez obtenida la casilla llamar a la pieza que corresponde y moverla. 
{
	Vector2D vi = pos_ini;
	Vector2D vf = pos_fin;
	Vector2D dif = pos_fin -pos_ini;

	 // se comprobara si se puede mover ahi o no si hay piezas en la posicion de destino. 
	// de momento se mueve a cualquier lado. 
	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {

			if (i == pos_ini.x && j == pos_ini.y)
				if (c[i][j].getPieza()->movimiento(pos_ini, pos_fin)) {
					std::cout << "MOVIMIENTO POSIBLE" << endl;
					//... FUNCION PARA HACER EL MOVIMIENTO DE LA PIEZA DESPUES DE COMPROBAR QUE SE PUEDE REALIZAR. 
					//c[i][j].getPieza()->setPos(pos_fin);

					// averiguar que pieza se selecciona y hacer el set de esa pieza con su color y tipo 
					do {
						 k = 0;
						if (c[((int)pos_ini.x) + k][((int)pos_ini.y) + k].getPieza()->NohayPieza()== true);
						{
							k++;
						}
						else { c++; };
						 

						 if (k == dif.x) {
							c[(int)pos_fin.x][(int)pos_fin.y].setPieza(new Alfil (c[i][j].getPieza()->getCol(), c[i][j].getPieza()->getTipo(), pos_fin));
							c[(int)pos_ini.x][(int)pos_ini.y].setPieza(new NoPieza(c[i][j].getPieza()->getCol(), c[i][j].getPieza()->getTipo(), pos_fin));
						}else { std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl; }

					} while ((pos_ini.x)+k != pos_fin.x);



							
								

						
						
				
							
				}
				else {std::cout << "MOVIMIENTO NO POSIBLE, VUELVA A SELECCIONAR EL MOVIMIENTO" << endl;}

		}
	}
}








bool Tablero::estaInicializado() // FUNCION QUE COMPRUEBA SI SE HA INICIALIZADO EL TABLERO 
{
	return inicializado;
}