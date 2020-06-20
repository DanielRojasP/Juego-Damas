#pragma once
#include <time.h>
#include <windows.h>
#include "Estrategia.h"

class EstrategiaFacil : public Estrategia
{
private:
	int estado;

public:
	EstrategiaFacil();
	~EstrategiaFacil();
	int getEstado();
	void setEstado(int);
	void ModoDeJuego(char tb[][8]);

};
