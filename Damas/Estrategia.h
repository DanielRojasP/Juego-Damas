#pragma once
#include "Tablero.h"
#include <iostream>
using namespace std;
class Estrategia: public Tablero
{
public:
	Estrategia();
	~Estrategia();
	void modoFacil(char[][8]);
	void modoDificil(char[][8]);
	void modoAleatorio(char[][8]);
	int getEstado();
	void setEstado(int);
private:
	int estado;
};

