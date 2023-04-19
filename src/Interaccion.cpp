#include "Interaccion.h"
#include "Tablero.h"

bool interaccion::selC(CaballoN& c, Selector s)
{

	Vector2D dif = s.getPos() - c.getPos();
	float u = dif.modulo();
	if (u <= 2.0)
		return true;
	else return false;



}

bool interaccion::sitioCCorrecto(Selector& s, Vector2D p)
{
	if (s.getPos().x == p.x + 6 && s.getPos().y == p.y + 12)
		return true;
	else return false;

	/*
	for (float i = 6; i <= 12; i + 6)
	{
		for (float j = 12; j >= 0; j - 6)
		{

			if (c.getPos().x == p.x + i && c.getPos().y == p.y + j)
				return true;
			else if ((c.getPos().x == p.x + i) && (c.getPos().y == p.y - j))
				return true;
			else if (c.getPos().x == p.x - i && c.getPos().y == p.y + j)
				return true;
			else if ((c.getPos().x == p.x - i) && (p.y - j))
				return true;
			else
				return false;
		}
	}
	*/

}


bool interaccion::CaballoCorrecto(CaballoN& c, Vector2D p)
{
	/*if (c.getPos().x == p.x + 6 && c.getPos().y == p.y + 12)
		return true;
	else return false;*/

	for (float i = 6; i <= 12; i + 6)
	{
		for (float j = 12; j >= 0; j - 6)
		{

			if (c.getPos().x == p.x + i && c.getPos().y == p.y + j)
				return true;
			else if ((c.getPos().x == p.x + i) && (c.getPos().y == p.y - j))
				return true;
			else if (c.getPos().x == p.x - i && c.getPos().y == p.y + j)
				return true;
			else if ((c.getPos().x == p.x - i) && (p.y - j))
				return true;
			else
				return false;
		}

	}

}

