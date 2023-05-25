#include"Pieza.h"

class Reina : public Pieza {

public:

	Reina(color c,tipo t, Vector2D p) {
		type = t;
		colour = c;
		posicion = p;

	}

	void dibujar(); //Derivada de func virtual en Pieza
	void dibujarSW(); // dibujar piezas star wars 
	bool movimiento(Vector2D pos_ini, Vector2D pos_fin);
	bool movimiento2(Vector2D pos_ini, Vector2D pos_fin, color c);
	color getCol() const;
	char getTipo();

};
