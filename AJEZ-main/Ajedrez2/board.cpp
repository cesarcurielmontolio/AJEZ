#include "board.h"
#include "freeglut.h"

board::board() { //Constructor clase board. Se construye con las casillas vacías
	
	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {  //Se crea el tablero vacío sin piezas
			c[i][j].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, Vector2D(i, j)));
		}
	}

}

void board::init() { //Se inicializan las piezas en el tablero. He puesto los dos casos, tanto si tenemos clases derivadas de cada pieza por color, como si especificamos el color y tipo en la propia clase de cada pieza
	//Se inicializa el tablero sin piezas
	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {
			c[i][j].setPieza(new NoPieza(color::NO_DEFINIDO, tipo::VACIA, Vector2D(i, j)));
		}
	}
	//Inicialización piezas blancas
	//Torres
	c[0][0].setPieza(new Torre(color::BLANCA, tipo::TORRE, Vector2D(0, 0))); //Origen del tablero. La matriz crece en el sentido positivos de x e y.
	//c[0][0].setPieza(new TorreBlanca());
	c[7][0].setPieza(new Torre(color::BLANCA, tipo::TORRE, Vector2D(7, 0)));
	//c[7][0].setPieza(new TorreBlanco());

	//Caballos
	c[1][0].setPieza(new Caballo(color::BLANCA, tipo::CABALLO, Vector2D(1, 0)));
	//c[1][0].setPieza(new CaballoBlanco());
	c[6][0].setPieza(new Caballo(color::BLANCA, tipo::CABALLO, Vector2D(6, 0)));
	//c[6][0].setPieza(new CaballoBlanco());

	//Alfiles
	c[2][0].setPieza(new Alfil(color::BLANCA, tipo::ALFIL, Vector2D(2, 0)));
	//c[2][0].setPieza(new AlfilBlanco());
	c[5][0].setPieza(new Alfil(color::BLANCA, tipo::ALFIL, Vector2D(5, 0)));
	//c[5][0].setPieza(new AlfilBlanco());

	//Rey y Reina
	c[4][0].setPieza(new Rey(color::BLANCA, tipo::REY, Vector2D(4, 0)));
	//c[4][0].setPieza(new ReyBlanco());
	c[3][0].setPieza(new Reina(color::BLANCA, tipo::REINA, Vector2D(3, 0)));
	//c[3][0].setPieza(new ReinaBlanca());



	//Inicialización piezas negras
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

}

void board::draw_board() {

	//borde (realmente es un cuadrado que está detras de las casillas)
	/*glColor3ub(100, 25, 25); //color del borde
	glBegin(GL_POLYGON);
	glVertex3f((0.0f - 4) * sqsize - bdsize, (0.0f - 4) * sqsize - bdsize, -0.1f);
	glVertex3f((0.0f - 4) * sqsize - bdsize, (1.0f + 3) * sqsize + bdsize, -0.1f);
	glVertex3f((1.0f + 3) * sqsize + bdsize, (1.0f + 3) * sqsize + bdsize, -0.1f);
	glVertex3f((1.0f + 3) * sqsize + bdsize, (0.0f - 4) * sqsize - bdsize, -0.1f);
	glEnd();*/

	//Dibujo de las casillas del tablero
	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {
			c[i][j].dibujar();

			/*glBegin(GL_POLYGON);
			glVertex3f((0.0f + i) * sqsize, (0.0f + j) * sqsize, 0.0f);
			glVertex3f((0.0f + i) * sqsize, (1.0f + j) * sqsize, 0.0f);
			glVertex3f((1.0f + i) * sqsize, (1.0f + j) * sqsize, 0.0f);
			glVertex3f((1.0f + i) * sqsize, (0.0f + j) * sqsize, 0.0f);
			glEnd();*/
		}
	}
	//Dibujo de las piezas una vez se haya inicilializado el tablero
	for (int i = 0; i < LADO; i++) {
		for (int j = 0; j < LADO; j++) {
			c[i][j].getPieza()->dibujar(); //El dibujo de cada pieza se define en su clase

		}
	}
}


void board::set_board(float sqz, float bdz) {
	/*sqsize = sqz;
	bdsize = bdz;*/
}