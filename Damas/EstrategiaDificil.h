#pragma once
#include "Estrategia.h"

class EstrategiaDificil : public Estrategia
{
private:
	int estado;

public:
	EstrategiaDificil();
	~EstrategiaDificil();
	int getEstado();
	void setEstado(int);
	void ModoDeJuego(char tb[][8]);

};
