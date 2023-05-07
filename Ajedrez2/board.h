#pragma once
class board
{
	float sqsize; //tamaño de casillas
	float bdsize; //grosor del borde exterior

public:
	void set_board(float sqz, float bdz);
	void draw_board(); //dibuja el tablero

};

