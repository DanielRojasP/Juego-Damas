#pragma once
#include "Tablero.h"
#include "Estrategia.h"
#include "Interfaz.h"
class Ficha: public Tablero
{
public:
	Ficha();
	Ficha(int, int);
	~Ficha();
	void movimientoFicha( Estrategia *, char[][8]);

private:
	int fila;
	int columna;
};

