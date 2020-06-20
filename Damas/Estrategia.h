#pragma once
#include "Tablero.h"
#include <iostream>
using namespace std;
class Estrategia : public Tablero
{
public:

	virtual void ModoDeJuego(char tb[][8]) = 0;

	virtual int getEstado() = 0;
	virtual void setEstado(int a) = 0;
private:
	int estado;
};
