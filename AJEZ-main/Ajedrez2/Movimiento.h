#pragma once
#include"Vector2D.h"
#include<vector>

using namespace std;
class Movimiento {
private:

	vector<Vector2D> lista_mov; 
public:

	Movimiento() {}
	virtual ~Movimiento(){}
	void insertarMov(const Vector2D& );
};