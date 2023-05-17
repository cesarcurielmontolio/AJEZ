#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(int x, int y) {
	this->x = x;
	this->y = y;
}

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

bool Vector2D::operator==(const Vector2D& v) {
	return (this->x == v.x && this->y == v.y);
};

bool Vector2D::operator!=(const Vector2D& v) {
	return !operator == (v);
}
bool Vector2D::operator < (const Vector2D& v) {
	return (this->x < v.x && this->y < v.y);
}
bool Vector2D::operator > (const Vector2D& v) {
	return !operator < (v);
}