#include "pch.h"
#include "Ficha.h"

Ficha::Ficha()
{
	fila = 0;
	columna = 0;
}
Ficha::Ficha(int f, int c)
{
	fila = f;
	columna = c;
}
Ficha::~Ficha()
{
}
void Ficha::movimientoFicha(Estrategia* a, char tb[][8])
{

	Estrategia* EstFacil = new EstrategiaFacil();
	Estrategia* EstMedia = new EstrategiaMedia();
	Estrategia* EstDificil = new EstrategiaDificil();
	Interfaz in;
	int col = 0;
	int par;
	int se;
	int fi = 0;
	int contador = 0;
	int contador2 = 0;
	char pos[2];
	char casilla[1];
	string nombre;
	int cont = 0;
	int opc;
	tableroVacio(tb);
	tableroInicializado(tb);
	if (a->getEstado() == 4) {
		cargar_p("Prueba", tb);
	}
	else {
		cout << "Desea cargar una partida?" << endl;
		cout << "1-Si" << "\n" << "2-No" << endl;
		cin >> par;
		if (par == 1)
		{
			cout << "Digite el nombre de la partida" << endl;
			cin >> nombre;
			cargar_p(nombre, tb);
		}
		else {}
	}

	do
	{
	ficha:
		if (juegoTerminado(tb) == true)
		{
			goto final;
		}
		else {}


		system("cls");
		mostrarTablero(tb);
		if (cont > 0)
		{
			cout << "¿Desea guardar la partida?" << endl;
			cout << "1-si" << "\n" << "2-No" << endl;
			cin >> opc;
			system("pause");
			system("cls");
			if (opc == 1)
			{

				guardar_p(nombre, tb);  //revisa de donde se manda la matriz al metodo mostrar
			}
			mostrarTablero(tb);
		}
		if (cont > 0)
		{
			cout << "Desea seguir jugando?" << endl;
			cout << "1-si" << "\n" << "2-No" << endl;
			cin >> se;

			if (se == 1)
			{
			}
			if (se == 2)
			{
				goto aqui;
			}
		}


		cout << "Dig la posicion de la ficha a mover: (Ej: 32)" << endl;
		cin >> pos;

		switch (pos[0])
		{
		case '1': {fila = 0; break; }
		case '2': {fila = 1; break; }
		case '3': {fila = 2; break; }
		case '4': {fila = 3; break; }
		case '5': {fila = 4; break; }
		case '6': {fila = 5; break; }
		case '7': {fila = 6; break; }
		case '8': {fila = 7; break; }
		default: {fila = 9; break; }
		}

		if (fila < 8 and fila + 1 > 0)
		{
			switch (pos[1])
			{
			case '1': {columna = 0; break; }
			case '2': {columna = 1; break; }
			case '3': {columna = 2; break; }
			case '4': {columna = 3; break; }
			case '5': {columna = 4; break; }
			case '6': {columna = 5; break; }
			case '7': {columna = 6; break; }
			case '8': {columna = 7; break; }
			default: {columna = 9; break; }
			}

			if (columna < 8 and columna + 1 > 0)
			{
				if (tb[fila][columna] == 'X')  // si en esa posicion hay una ficha
				{
					cout << "Dig la posicion a la que desea mover la ficha: (Ej: 43)" << endl;
					cin >> casilla;

					switch (casilla[0])
					{
					case '1': {fi = 0; break; }
					case '2': {fi = 1; break; }
					case '3': {fi = 2; break; }
					case '4': {fi = 3; break; }
					case '5': {fi = 4; break; }
					case '6': {fi = 5; break; }
					case '7': {fi = 6; break; }
					case '8': {fi = 7; break; }
					default: {fi = 9; break; }
					}
					if (fi < 8 and fi + 1 > 0)
					{
						switch (casilla[1])
						{
						case '1': {col = 0; break; }
						case '2': {col = 1; break; }
						case '3': {col = 2; break; }
						case '4': {col = 3; break; }
						case '5': {col = 4; break; }
						case '6': {col = 5; break; }
						case '7': {col = 6; break; }
						case '8': {col = 7; break; }
						default: {col = 9; break; }
						}
						if (col < 8 and col + 1 > 0)
						{
							if (fi == fila + 1 and col == columna + 1) //Si solo se mueve una posicion a la diagonal superior derecha
							{
								if (tb[fi][col] == ' ' or tb[fi][col] == char(176)) // Si está vacia
								{
									if ((fi == 7 and col == 0) or (fi == 7 and col == 2) or (fi == 7 and col == 4) or (fi == 7 and col == 6))
									{
										tb[fi - 1][col - 1] = ' ';
										tb[fi][col] = 'B';
										cout << "Se corono " << endl;
										goto maquina;
									}
									else
									{
										tb[fi - 1][col - 1] = ' ';
										tb[fi][col] = 'X';
										goto maquina;
									}
								}
								if (columna == 7 or tb[fi][col] == 'X' or tb[fi][col] == 'O' or tb[fi][col] == 'B' or tb[fi][col] == 'N') //movimiento invalido
								{
									cout << "Movimiento de Ficha invalido" << endl;
									system("pause");
									goto ficha;
								}
							}
							if ((fi == fila + 1 and col == columna - 1)) //Diagonal superior izquierda
							{
								if (tb[fi][col] == ' ' or tb[fi][col] == char(176)) // Si está vacia
								{
									if ((fi == 7 and col == 0) or (fi == 7 and col == 2) or (fi == 7 and col == 4) or (fi == 7 and col == 6))
									{
										tb[fi - 1][col + 1] = ' ';
										tb[fi][col] = 'B';
										cout << "Ha sido coronado " << endl;
										goto maquina;
									}
									else
									{
										tb[fi - 1][col + 1] = ' ';
										tb[fi][col] = 'X';
										goto maquina;
									}

								}
								if (columna == 0 or tb[fi][col] == 'X' or tb[fi][col] == 'O' or tb[fi][col] == 'B' or tb[fi][col] == 'N') //movimiento invalido
								{
									cout << "Movimiento de Ficha invalido" << endl;
									system("pause");
									goto ficha;
								}
							}
							if (fi > fila + 1 and col > columna + 1 and (tb[fi - 1][col - 1] == 'O' or tb[fi - 1][col - 1] == 'N')) //movimiento mas de 1 casilla DSD
							{
								if ((tb[fila + 1][columna + 1] == 'O' or tb[fila + 1][columna + 1] == 'N') and (tb[fila + 2][columna + 2] == ' ' or tb[fila + 2][columna + 2] == char(176))) // puede comer la ficha de la diagonal
								{
									if ((fila + 2 == 7 and columna + 2 == 0) or (fila + 2 == 7 and columna + 2 == 2) or (fila + 2 == 7 and columna + 2 == 4) or (fila + 2 == 7 and columna + 2 == 6))
									{
										do		//dsd
										{
											tb[fila][columna] = ' ';
											tb[fila + 1][columna + 1] = ' ';
											tb[fila + 2][columna + 2] = 'B';
											fila = fila + 2;
											columna = columna + 2;
										} while (fila != fi and columna != col);
										{
											cout << "Se corono" << endl;
											goto maquina;
										}
									}
									else
									{
										do		//dsd
										{
											tb[fila][columna] = ' ';
											tb[fila + 1][columna + 1] = ' ';
											tb[fila + 2][columna + 2] = 'X';
											fila = fila + 2;
											columna = columna + 2;
										} while (fila != fi and columna != col);
										{
											goto maquina;
										}
									}
								}

							}
							if (fi > fila + 1 and col < columna - 1 and (tb[fi - 1][col + 1] == 'O' or tb[fi - 1][col + 1] == 'N'))
							{
								if ((tb[fila + 1][columna - 1] == 'O' or tb[fila + 1][columna - 1] == 'N') and (tb[fila + 2][columna - 2] == ' ' or tb[fila + 2][columna - 2] == char(176))) // puede comer la ficha de la diagonal
								{
									if ((fila + 2 == 7 and columna - 2 == 0) or (fila + 2 == 7 and columna - 2 == 2) or (fila + 2 == 7 and columna - 2 == 4) or (fila + 2 == 7 and columna - 2 == 6))
									{
										do		//dsi
										{
											tb[fila][columna] = ' ';
											tb[fila + 1][columna - 1] = ' ';
											tb[fila + 2][columna - 2] = 'B';
											fila = fila + 2;
											columna = columna - 2;
										} while (fila != fi and columna != col);
										{
											cout << "Se corono" << endl;
											goto maquina;
										}
									}
									else
									{
										do		//dsi
										{
											tb[fila][columna] = ' ';
											tb[fila + 1][columna - 1] = ' ';
											tb[fila + 2][columna - 2] = 'X';
											fila = fila + 2;
											columna = columna - 2;
										} while (fila != fi and columna != col);
										{
											goto maquina;
										}
									}
								}

							}
							else
							{
								cout << "Movimiento de Ficha invalido" << endl;
								cout << "No es una reina" << endl;
								system("pause");
								goto ficha;
							}

						}
						else { cout << "Columna invalida" << endl; }
					}
					else { cout << "Fila invalida" << endl; }


				}
				if (tb[fila][columna] == 'B') // Si es reina
				{
					cout << "Dig la posicion a la que desea mover la ficha: (Ej: 43)" << endl;
					cin >> casilla;

					switch (casilla[0])
					{
					case '1': {fi = 0; break; }
					case '2': {fi = 1; break; }
					case '3': {fi = 2; break; }
					case '4': {fi = 3; break; }
					case '5': {fi = 4; break; }
					case '6': {fi = 5; break; }
					case '7': {fi = 6; break; }
					case '8': {fi = 7; break; }
					default: {fi = 9; break; }
					}
					if (fi < 8 and fi + 1 > 0)
					{
						switch (casilla[1])
						{
						case '1': {col = 0; break; }
						case '2': {col = 1; break; }
						case '3': {col = 2; break; }
						case '4': {col = 3; break; }
						case '5': {col = 4; break; }
						case '6': {col = 5; break; }
						case '7': {col = 6; break; }
						case '8': {col = 7; break; }
						default: {col = 9; break; }
						}
						if (col < 8 and col + 1 > 0)
						{
							if (fi == fila + 1 and col == columna + 1) //diagonal superior derecha
							{
								if (tb[fi][col] == ' ' or tb[fi][col] == char(176)) // Si está vacia
								{
									tb[fi - 1][col - 1] = ' ';
									tb[fi][col] = 'B';
									goto maquina;
								}
								if (columna == 7 or tb[fi][col] == 'X' or tb[fi][col] == 'B' or tb[fi][col] == 'O' or tb[fi][col] == 'N') //movimiento invalido
								{
									cout << "Movimiento de Ficha invalido" << endl;
									system("pause");
									goto ficha;
								}
							}
							if ((fi == fila + 1 and col == columna - 1)) //Diagonal superior izquierda
							{
								if (tb[fi][col] == ' ' or tb[fi][col] == char(176)) // Si está vacia
								{
									tb[fi - 1][col + 1] = ' ';
									tb[fi][col] = 'B';
									goto maquina;
								}
								if (columna == 0 or tb[fi][col] == 'B' or tb[fi][col] == 'X' or tb[fi][col] == 'O' or tb[fi][col] == 'N') //movimiento invalido
								{
									cout << "Movimiento de Ficha invalido" << endl;
									system("pause");
									goto ficha;
								}
							}
							if (fi == fila - 1 and col == columna + 1) //Diagonal inferior derecha
							{
								if (tb[fi][col] == ' ' or tb[fi][col] == char(176)) // Si está vacia
								{
									tb[fi + 1][col - 1] = ' ';
									tb[fi][col] = 'B';
									goto maquina;
								}
								if (columna == 7 or tb[fi][col] == 'X' or tb[fi][col] == 'B' or tb[fi][col] == 'O' or tb[fi][col] == 'N') //movimiento invalido
								{
									cout << "Movimiento de Ficha invalido" << endl;
									system("pause");
									goto ficha;
								}
							}
							if ((fi == fila - 1 and col == columna - 1)) //Diagonal inferior izquierda
							{
								if (tb[fi][col] == ' ' or tb[fi][col] == char(176)) // Si está vacia
								{
									tb[fi - 1][col - 2] = ' ';
									tb[fi][col] = 'B';
									goto maquina;
								}
								if (columna == 0 or tb[fi][col] == 'B' or tb[fi][col] == 'X' or tb[fi][col] == 'O' or tb[fi][col] == 'N') //movimiento invalido
								{
									cout << "Movimiento de Ficha invalido" << endl;
									system("pause");
									goto ficha;
								}
							}

							if (fi > fila + 1 and col > columna + 1 and (tb[fi - 1][col - 1] == 'O' or tb[fi - 1][col - 1] == 'N')) //movimiento mas de 1 casilla Dsd
							{
								if ((tb[fila + 1][columna + 1] == 'O' or tb[fila + 1][columna + 1] == 'N') and (tb[fila + 2][columna + 2] == ' ' or tb[fila + 2][columna + 2] == char(176))) // puede comer la ficha de la diagonal
								{
									do		//dsd
									{
										tb[fila][columna] = ' ';
										tb[fila + 1][columna + 1] = ' ';
										tb[fila + 2][columna + 2] = 'B';
										fila = fila + 2;
										columna = columna + 2;
									} while (fila != fi and columna != col);
									{
										goto maquina;
									}
								}

							}
							if (fi > fila + 1 and col < columna - 1 and (tb[fi - 1][col + 1] == 'O' or tb[fi - 1][col + 1] == 'N'))
							{
								if ((tb[fila + 1][columna - 1] == 'O' or tb[fila + 1][columna - 1] == 'N') and (tb[fila + 2][columna - 2] == ' ' or tb[fila + 2][columna - 2] == char(176))) // puede comer la ficha de la diagonal
								{
									do		//dsi
									{
										tb[fila][columna] = ' ';
										tb[fila + 1][columna - 1] = ' ';
										tb[fila + 2][columna - 2] = 'B';
										fila = fila + 2;
										columna = columna - 2;
									} while (fila != fi and columna != col);
									{
										goto maquina;
									}
								}

							}
							else
							{
								cout << "Movimiento de Ficha invalido" << endl;
								cout << "No es una reina" << endl;
								system("pause");
								goto ficha;
							}

						}
						else { cout << "Columna invalida" << endl; }
					}
					else { cout << "Fila invalida" << endl; }
				}
				else
				{
					cout << "Posicion invalida" << endl;
					system("pause");
					goto ficha;
				}
			}
			else
			{
				cout << "Columna invalida" << endl;
				system("pause");
				system("cls");
				goto ficha;
			}
		}
		else
		{
			cout << "Fila invalida" << endl;
			system("pause");
			system("cls");
			goto ficha;
		}
	maquina:
		system("pause");
		system("cls");
		mostrarTablero(tb);
		cout << "Turno de la maquina" << endl;
		cout << "Pensando jugada..." << endl;
		Sleep(800);
		if (a->getEstado() == 1)
		{
			EstMedia->ModoDeJuego(tb);
		}
		if (a->getEstado() == 2)
		{
			EstFacil->ModoDeJuego(tb); ///Modo aleatorio	
		}
		if (a->getEstado() == 3)
		{
			EstDificil->ModoDeJuego(tb);
		}
		system("pause");
		cont++;
		goto ficha;
		final:
		cout << endl;
	} while (juegoTerminado(tb) != true);
	{
		system("cls");
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (tb[i][j] == 'O' or tb[i][j] == 'N')
				{
					contador++;
				}
				else if (tb[i][j] == 'X' or tb[i][j] == 'B')
				{
					contador2++;
				}
			}
		}
		if (contador == 0)
		{
			cout << "----------------------------------" << endl;
			cout << "|          Juego terminado       |" << endl;
			cout << "|           ¡Has ganado!         |" << endl;
			cout << "----------------------------------" << endl;
			system("pause");
			system("cls");
		}
		if (contador2 == 0)
		{
			cout << "----------------------------------" << endl;
			cout << "|        Juego terminado         |" << endl;
			cout << "|         ¡Has perdido!          |" << endl;
			cout << "----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	aqui:
		in.menu();
	}


}