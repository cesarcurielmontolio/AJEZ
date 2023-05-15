#include "Vector2D.h"
#include <math.h>

Vector2D Vector2D::operator - (Vector2D v) {
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}
Vector2D Vector2D::operator + (Vector2D v) {
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}