#include "pch.h"
#include "Interfaz.h"



void Interfaz::menu()
{
	int opc;
	int opcion = 0;
	Ficha fc;
	Estrategia* EstFacil = new EstrategiaFacil();
	Estrategia* EstMedia = new EstrategiaMedia();
	Estrategia* EstDificil = new EstrategiaDificil();
	Tablero a;
	string nombre;
	char tb[8][8];
	a.tableroVacio(tb);

	while (opcion != 3)
	{
		cout << "         Digite la opcion que desea:          " << endl;
		cout << "1-Jugar " << "\n" << "2-Modo de Prueba" <<"\n"<<"3-Salir" << endl;
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
				EstMedia->setEstado(1);
				fc.movimientoFicha(EstMedia, tb);

				break;
			case 2:
				EstFacil->setEstado(2);
				fc.movimientoFicha(EstFacil, tb);
				break;
			case 3:
				cout << "Para utilizar el modo de prueba, cargue la partida con el nombre de partida 'Prueba'" << endl;
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
			cout << "Modo de Prueba" << endl;
			EstFacil->setEstado(4);
			fc.movimientoFicha(EstFacil, tb);
			break;
		}
		case 3:
			cout << "Saliendo del sistema" << endl;
			exit(0);
				
			break;

		default:
			cout << "Opcion erronea " << endl;
			break;
		}
	}
	



}

void Interfaz::Presentacion()
{
	int contador = 0;
	char blanco = 178;
	char negro = 177;
	cout << "\t\t\t   Bienvenido a Damas Chinas" << endl << endl;
	for (int i = 0; i < 8; i++) {
		cout << endl;
		contador--;
		cout << "\t\t\t  ";
		for (int j = 0; j < 8; j++) {
			contador++;
			if (contador % 2 != 0) {
				cout << blanco << blanco << blanco << blanco;
			}
			if (contador % 2 == 0) {
				cout << negro << negro << negro << negro;
			}
		}
	}
	cout << "\n\n";
	cout << "Integrantes: \nGonzalo Umana Cespedes <---> Daniel Rojas Porras <---> Sergio Alfaro Araya" << endl << endl;
	cout << "Proyecto II Programacion II" << endl;
	cout << "Universidad Nacional de Costa Rica" << endl;
	system("pause");
	system("CLS");
}
