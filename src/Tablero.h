#pragma once


class Tablero {
public:
	Tablero();
	virtual~Tablero();
	void dibuja();
	friend class interaccion;
};
