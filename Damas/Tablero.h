#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include <windows.h>

using namespace std;

class Tablero
{
public:
	Tablero();
	~Tablero();
	void tableroVacio(char[][8]);
	void tableroInicializado(char[][8]);
	void mostrarTablero(char[][8]);
	bool juegoTerminado(char[][8]);
	void guardar_p(string, char[][8]);
	void cargar_p(string, char[][8]);
private:
	char Tab[8][8];
	
};

