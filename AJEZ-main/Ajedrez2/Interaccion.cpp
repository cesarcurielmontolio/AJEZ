#include "Interaccion.h"
#include "Tablero.h"



bool interaccion::recorridoTorre(Tablero& t, Vector2D pos_ini, Vector2D pos_fin)
{
	Vector2D vi;
	Vector2D vf;
	Vector2D vdif;
	int countx;
	int county;
	int xpos = 1;
	int ypos = 1;
	
	
	
	vi = pos_ini;
	vf = pos_fin;
	vdif = (vf - vi);
	if (vdif.x == 0) xpos = 0;
	else ypos = 0;

	if (vdif.x < 0) xpos = -1;
	if (vdif.y < 0)ypos = -1;

	vf.x = vf.x - xpos; // Se comprueba el recorrido hasta la ultima pieza antes de la pieza final 
	vf.y = vf.y - ypos;
	

	if (t.c[(int)vi.x][(int)vi.y].getPieza()->getTipo() == 'T' || t.c[(int)vi.x][(int)vi.y].getPieza()->getTipo() == 'Q')
	{
		if (t.c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() != t.c[(int)pos_ini.x][(int)pos_ini.y].getPieza()->getCol())//Cmprobamos si la ultima pieza se puede comer si es del color contrario a la del color del turno. 
		{
			if (vdif.x == 1.0 || vdif.y == 1 || vdif.x == -1 || vdif.y == -1) return true;


		if (xpos == 0) {
			do
			{
				if (t.c[(int)vi.x + xpos][(int)vi.y + ypos].getPieza()->getCol() == NO_DEFINIDO) {
					vi.x += xpos;
					vi.y += ypos;

				}
				else return false;
			} while (vi.y != vf.y); // se puede sobre cargar el operador != 
				// Si se sale del while se devuelve true ya que el camino esta despejado
			return true;

		}

		else {
			do
			{
				if (t.c[(int)vi.x + xpos][(int)vi.y + ypos].getPieza()->getCol() == NO_DEFINIDO) {
					vi.x += xpos;
					vi.y += ypos;

				}
				else return false;

			} while (vi.x != vf.x); // se puede sobre cargar el operador != 
		// Si se sale del while se devuelve true ya que el camino esta despejado
			return true;
		}


		
	}else return false;
		
	}else return false;
	
}

bool interaccion::recorridoAlfil(Tablero& t, Vector2D pos_ini, Vector2D inter,  Vector2D pos_fin)
{
	Vector2D vi;
	Vector2D vf;
	Vector2D vdif;
	Vector2D vinter;
	int countx;
	int county; 
	int xpos = 1;
	int ypos = 1;
	vi = pos_ini;
	vinter = inter;
	vf=pos_fin;
	// vdif=(vf - vi);
	vdif.x = vf.x - vinter.x;
	vdif.y = vf.y - vinter.y;
	if (vdif.x < 0) xpos *= -1;
	if (vdif.y < 0) ypos *= -1;
	if (vdif.x == 0.0 || vdif.y== 0.0) return false;

	vf.x -=xpos;
	vf.y -=ypos;

	if (t.c[(int)vi.x][(int)vi.y].getPieza()->getTipo() == 'A' || t.c[(int)vi.x][(int)vi.y].getPieza()->getTipo() == 'Q') {
		if (t.c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() != t.c[(int)pos_ini.x][(int)pos_ini.y].getPieza()->getCol())//Cmprobamos si la ultima pieza se puede comer si es del color contrario a la del color del turno. 
		{
			if (vdif.x == 1.0  || vdif.y == 1 || vdif.x== -1 || vdif.y==-1 ) return true;

			do
			{
				if (t.c[(int)vinter.x + xpos][(int)vinter.y + ypos].getPieza()->getCol() == NO_DEFINIDO) {
					vinter.x += xpos;
					vinter.y += ypos;

				}
				else return false;
			} while (vinter.x != vf.x && vinter.y != vf.y); // se puede sobre cargar el operador != 

			return true; // Si se sale del while se devuelve true ya que el camino esta despejado


		}else return false;
		 
		
	}else return false;
}

bool interaccion::comerPeon(Tablero& t, Vector2D pos_ini, Vector2D pos_fin)
{
	Vector2D vi;
	Vector2D vf;
	Vector2D vdif;
	int countx;
	int county;
	int xpos = 1;
	int ypos = 1;
	vi = pos_ini;
	vf = pos_fin;
	vdif = (vf - vi);
	if (vdif.x < 0) xpos = -1;

	if (t.c[(int)vi.x][(int)vi.y].getPieza()->getTipo() == 'P')
	{
		if (t.c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() != t.c[(int)pos_ini.x][(int)pos_ini.y].getPieza()->getCol() && t.c[(int)pos_fin.x][(int)pos_fin.y].getPieza()->getCol() != NO_DEFINIDO)
			return true;
	}else return false;


}


