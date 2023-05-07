#include "board.h"
#include "freeglut.h"

void board::set_board(float sqz, float bdz) {
	sqsize = sqz;
	bdsize = bdz;
}

void board::draw_board() {

	//borde (realmente es un cuadrado que está detras de las casillas)
	glColor3ub(100, 25, 25); //color del borde
	glBegin(GL_POLYGON);
	glVertex3f((0.0f - 4) * sqsize - bdsize, (0.0f - 4) * sqsize - bdsize, -0.1f);
	glVertex3f((0.0f - 4) * sqsize - bdsize, (1.0f + 3) * sqsize + bdsize, -0.1f);
	glVertex3f((1.0f + 3) * sqsize + bdsize, (1.0f + 3) * sqsize + bdsize, -0.1f);
	glVertex3f((1.0f + 3) * sqsize + bdsize, (0.0f - 4) * sqsize - bdsize, -0.1f);
	glEnd();

	//casillas
	for (int i = -4; i < 4; i++) {
		for (int j = -4; j < 4; j++) {
			
			//cambio de color de las casillas
			if ((i + j) % 2) {
				glColor3ub(255, 255, 255);
			}
			else {
				glColor3ub(0, 0, 0);
			}

			glBegin(GL_POLYGON);
			glVertex3f((0.0f + i) * sqsize, (0.0f + j) * sqsize, 0.0f);
			glVertex3f((0.0f + i) * sqsize, (1.0f + j) * sqsize, 0.0f);
			glVertex3f((1.0f + i) * sqsize, (1.0f + j) * sqsize, 0.0f);
			glVertex3f((1.0f + i) * sqsize, (0.0f + j) * sqsize, 0.0f);
			glEnd();
		}
	}

}
