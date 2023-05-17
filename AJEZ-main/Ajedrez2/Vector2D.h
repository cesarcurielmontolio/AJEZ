#pragma once

class Vector2D {

public:
	int x, y;
	Vector2D(int x, int y);
	Vector2D() :x(0), y(0){}

	Vector2D operator - (Vector2D); // resta de vectores
	Vector2D operator + (Vector2D); // suma de vectores
	
	//Sobrecarga de operadores
	bool operator==(const Vector2D& v);
	bool operator!=(const Vector2D& v);
	bool operator<(const Vector2D& v);
	bool operator>(const Vector2D& v);
	
};