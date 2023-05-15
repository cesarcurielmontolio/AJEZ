#pragma once

class Vector2D {

public:
	float x, y;
	Vector2D(float xv, float yv):x(xv),y(yv){}
	Vector2D operator - (Vector2D v);
	Vector2D() :x(0), y(0){}
};
