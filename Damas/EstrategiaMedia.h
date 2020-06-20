#pragma once
#include "Estrategia.h"

class EstrategiaMedia : public Estrategia
{
private:
	int estado;

public:
	EstrategiaMedia();
	~EstrategiaMedia();
	int getEstado();
	void setEstado(int);
	void ModoDeJuego(char tb[][8]);

};;

