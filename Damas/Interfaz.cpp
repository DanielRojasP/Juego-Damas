#include "pch.h"
#include "Interfaz.h"



void Interfaz::menu()
{
	int opc;
	int opcion;
	Ficha fc;
	Estrategia* EstFacil = new EstrategiaFacil();
	Estrategia* EstMedia = new EstrategiaMedia();
	Estrategia* EstDificil = new EstrategiaDificil();
	Tablero a;
	string nombre;
	char tb[8][8];
	a.tableroVacio(tb);
	do
	{
		cout << "------------------Bienvenido------------------" << endl;
		cout << "         Digite la opcion que desea:          " << endl;
		cout << "1-Jugar " << "\n" << "2-Salir" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
		{
			cout << "Digite en que dificultad desea jugar" << endl;
			cout << "1-Facil" << "\n" << "2-Aleatorio" << "\n" << "3-Dificil" << endl;
			cin >> opc;
			switch (opc)
			{
			case 1:
				/*Ficha fc;*/
				EstFacil->setEstado(1);
				fc.movimientoFicha(EstFacil, tb);

				break;
			case 2:
				EstMedia->setEstado(2);
				fc.movimientoFicha(EstMedia, tb);
				break;
			case 3:
				EstDificil->setEstado(3);
				fc.movimientoFicha(EstDificil, tb);
				break;
			default:
				cout << "Eleccion incorrecta" << endl;
				break;
			}

			break;
		}
		case 2:
		{
			break;
		}

		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 2);
	{
		cout << "Saliendo del sistema" << endl;
	}



}
