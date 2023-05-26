#include "CoordinadorAjedrez.h"

CoordinadorAjedrez::CoordinadorAjedrez()
{
	estado = INICIO;
	turno = BLANCAS;
}

CoordinadorAjedrez::~CoordinadorAjedrez()
{
}

void CoordinadorAjedrez::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO || estado == JUEGOSW) 
		mundo.teclaEspecial(key);

}





void CoordinadorAjedrez::mouseFunc(int button, int state, int x, int y)
{
	// debe detectar cada dos pulsaciones. 

	if (estado == JUEGO || JUEGOSW) { // sistema para definir el turno de cada jugador.
		mundo.mouseFunc(button, state, x, y);	// cada vez un un jugador realiza su turno se cambia el turno. 
		if (turno == BLANCAS && mundo.checkTurno(BLANCA)) {
			mundo.mueve(BLANCA);

			if (mundo.checkJaque()) {
				partida = JAQUEN;
			}
			
			turno = NEGRAS;
		}
		else if (turno==NEGRAS && mundo.checkTurno(NEGRA)){
			//mundo.mouseFunc(button, state, x, y);
			mundo.mueve(NEGRA);
			turno = BLANCAS;
			if (mundo.checkJaque()){
				partida = JAQUEB;
			}
		}
	}

	if (partida == JAQUEN && turno==BLANCAS) {
		if (mundo.jaqueMate()) {
			partida = MATE;
			std::cout << "JAQUE MATE GANAN LAS BLANCAS" << endl;
		}
	}
	


}

void CoordinadorAjedrez::tecla(unsigned char key)  //UTILIZAR EL TECLADO DEL ORDENADOR
{
	if (estado == INICIO) { // estado inicio se inicializa todo y sale el Menu de Inicio. 
		mundo.inicializa(); // COMPRUEBA SI ESTA INICIALIZADO Y ACTO SEGUIDO LO DIBUJA
							// no es necesario comprobar si esta inicializado si le damos a iniciar juego se puede llamar a la funcion dibuja (if(key=='e')
		if (key == 'e') {
			estado = JUEGO;
		//mundo.dibuja();
		}
		else if (key == 'w') {
			estado = JUEGOSW;
		
		}else if (key == 's') {
			exit(1);
		}
			
	}
		


	



		if (estado==JUEGO && key=='p')
		{
			estado = PAUSA;
		}

		if (estado == PAUSA) {
			switch (key) 
			{
			case 's': {
				exit(1);
				break;
			case 'a': {
				estado = JUEGO;
				break;
			}
			case 'r': {
				estado = INICIO; // se puede crear otro estado reiniciar para borrarlo todo y volver a iniciar todo despues de haberlo borrado.
				mundo.inicializa();
				mundo.reset();
				turno = BLANCAS;
				break;
			}
			default:
				break;
			}
		}
		
		
		
		
}
	
}

void CoordinadorAjedrez::mueve()
{
	//if (estado == JUEGAN_BLANCAS) {
		
	//}
	//else mundo.mueve(NEGRA);
}

void CoordinadorAjedrez::dibuja()
{
	


	if (estado == INICIO)
	{//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("AJEDREZ AJEZ", -7, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR EL JUEGO CLASICO ", -10, 7);
		ETSIDI::printxy("PULSE LA TECLA -W- PARA EMPEZAR EL JUEGO INTERGALACTICO ", -10, 6);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -10, 5);
		ETSIDI::printxy("CESAR Y DELA", 2, 1);
	}
	else if (estado == JUEGO)
		mundo.dibuja();
	else if (estado == JUEGOSW)
		mundo.dibujaSW();

	 if (estado == PAUSA) { // SE PUEDE CREAR UN MIEMBRO DE MUNDO PARA HACER ESTA VENTANA.
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS

		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PANTALLA DE PAUSA", -7, 8);
		ETSIDI::setTextColor(56, 200, 111);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -A- PARA SEGUIR", -7, 7);
		ETSIDI::printxy("PULSE LA TECLA -R- PARA REINICIAR LA PARTIDA", -7, 6);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -7, 5);
		ETSIDI::printxy("CESAR Y DELA", 2, 1);
	}
	 if (estado == JUEGO) {
			if (turno == BLANCAS) {// se pinta una frase que indica a que jugador le toca jugar. 
		 ETSIDI::setTextColor(200, 10, 40);
		 ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		 ETSIDI::printxy("JUEGAN BLANCAS ", 0, 10, 3);
		 ETSIDI::printxy("JUEGAN BLANCAS ", 0, 9, 3);
		 ETSIDI::printxy("JUEGAN BLANCAS ", 0, 11, 3);
	 }
			 else if (turno == NEGRAS)
	 {
		 ETSIDI::setTextColor(200, 10, 40);
		 ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		 ETSIDI::printxy("JUEGAN NEGRAS ", 0, 10, 3);
		 ETSIDI::printxy("JUEGAN NEGRAS ", 0, 9, 3);
		 ETSIDI::printxy("JUEGAN NEGRAS ", 0, 11, 3);
	 }
		
	 }
	 else if (estado == JUEGOSW)
	 {
		 if (turno == BLANCAS) {// se pinta una frase que indica a que jugador le toca jugar. 
			 ETSIDI::setTextColor(200, 10, 40);
			 ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			 ETSIDI::printxy("JUEGA LA RESISTENCIA", 0, 9, 3);
		 }
		 else if (turno == NEGRAS)
		 {
			 ETSIDI::setTextColor(200, 10, 40);
			 ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			 ETSIDI::printxy("JUEGA EL LADO OSCURO", 0, 9, 3);
		 }


		 if (partida==JAQUEB) {// se pinta una frase que indica a que jugador le toca jugar. 
			 ETSIDI::setTextColor(200, 10, 40);
			 ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			 ETSIDI::printxy("JAQUE BLANCAS", 5, 9, 3);
		 }
		 else if (partida==JAQUEN)
		 {
			 ETSIDI::setTextColor(200, 10, 40);
			 ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			 ETSIDI::printxy("JAQUE NEGRAS", 0, 9, 3);
		 }



}







	 }


