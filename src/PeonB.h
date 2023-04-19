#pragma once
#include "PiezaMovil.h"
#include "ETSIDI.h"

class PeonB : public PiezaMovil
{
public:
	//PeonB();
	
	PeonB(float px=0.0, float py=0.0);
	virtual ~PeonB();

	void dibuja();
	//void mueve()

};