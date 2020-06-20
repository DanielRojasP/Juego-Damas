#include "pch.h"
#include "EstrategiaMedia.h"

EstrategiaMedia::EstrategiaMedia()
{
}

EstrategiaMedia::~EstrategiaMedia()
{
}

int EstrategiaMedia::getEstado()
{
	return estado;
}

void EstrategiaMedia::setEstado(int a)
{
	this->estado = a;
}

void EstrategiaMedia::ModoDeJuego(char tb[][8])
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j != 6 and j != 7 and tb[i][j] == 'O' and (tb[i - 1][j + 1] == 'X' or tb[i - 1][j + 1] == 'B') and j < 8 and j>0 and (tb[i - 2][j + 2] == ' ' or tb[i - 2][j + 2] == char(176)))
			{
				if ((i - 2 == 0 and j + 2 == 1) or (i - 2 == 0 and j + 2 == 3) or (i - 2 == 0 and j + 2 == 5) or (i - 2 == 0 and j + 2 == 7))
				{
					tb[i][j] = ' ';
					tb[i - 1][j + 1] = ' ';
					tb[i - 2][j + 2] = 'N';
					cout << "La maquina se corono" << endl;
					cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
					goto final;
				}
				else
				{
					tb[i][j] = ' ';
					tb[i - 1][j + 1] = ' ';
					tb[i - 2][j + 2] = 'O';
					cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
					goto final;
				}
			}
			else if (j != 6 and j != 7 and tb[i][j] == 'N' and (tb[i - 1][j + 1] == 'X' or tb[i - 1][j + 1] == 'B') and j < 8 and j>0 and (tb[i - 2][j + 2] == ' ' or tb[i - 2][j + 2] == char(176)))
			{
				tb[i][j] = ' ';
				tb[i - 1][j + 1] = ' ';
				tb[i - 2][j + 2] = 'N';
				cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
				goto final;
			}
			if (j != 7 and tb[i][j] == 'O' and (tb[i - 1][j + 1] == ' ' or tb[i - 1][j + 1] == char(176)) and j < 8 and j>0)
			{
				if ((i - 1 == 0 and j + 1 == 1) or (i - 1 == 0 and j + 1 == 3) or (i - 1 == 0 and j + 1 == 5) or (i - 1 == 0 and j + 1 == 7))
				{
					tb[i][j] = ' ';
					tb[i - 1][j + 1] = 'N';
					cout << "La maquina se corono" << endl;
					cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
					goto final;
				}
				else
				{
					tb[i][j] = ' ';
					tb[i - 1][j + 1] = 'O';
					cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
					goto final;
				}
			}
			else if (j != 7 and tb[i][j] == 'N' and (tb[i - 1][j + 1] == ' ' or tb[i - 1][j + 1] == char(176)) and j < 8 and j>0)
			{
				tb[i][j] = ' ';
				tb[i - 1][j + 1] = 'N';
				cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
				goto final;
			}
			if (j != 0 and j != 1 and tb[i][j] == 'O' and (tb[i - 1][j - 1] == 'X' or tb[i - 1][j - 1] == 'B') and j > 0 and j < 8 and (tb[i - 2][j - 2] == ' ' or tb[i - 2][j - 2] == char(176)))
			{
				if ((i - 2 == 0 and j - 2 == 1) or (i - 2 == 0 and j - 2 == 3) or (i - 2 == 0 and j - 2 == 5) or (i - 2 == 0 and j - 2 == 7))
				{
					tb[i][j] = ' ';
					tb[i - 1][j - 1] = ' ';
					tb[i - 2][j - 2] = 'N';
					cout << "La maquina se corono" << endl;
					cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
					goto final;
				}
				else
				{
					tb[i][j] = ' ';
					tb[i - 1][j - 1] = ' ';
					tb[i - 2][j - 2] = 'O';
					cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
					goto final;
				}
			}
			else if (j != 0 and j != 1 and tb[i][j] == 'N' and (tb[i - 1][j - 1] == 'X' or tb[i - 1][j - 1] == 'B') and j > 0 and j < 8 and (tb[i - 2][j - 2] == ' ' or tb[i - 2][j - 2] == char(176)))
			{
				tb[i][j] = ' ';
				tb[i - 1][j - 1] = ' ';
				tb[i - 2][j - 2] = 'N';
				cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
				goto final;
			}
			if (j != 0 and tb[i][j] == 'O' and (tb[i - 1][j - 1] == ' ' or tb[i - 1][j - 1] == char(176)) and j > 0 and j < 8) //Diagonal
			{
				if ((i - 1 == 0 and j - 1 == 1) or (i - 1 == 0 and j - 1 == 3) or (i - 1 == 0 and j - 1 == 5) or (i - 1 == 0 and j - 1 == 7))
				{
					tb[i][j] = ' ';
					tb[i - 1][j - 1] = 'N';
					cout << "La maquina se corono" << endl;
					cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
					goto final;
				}
				else
				{
					tb[i][j] = ' ';
					tb[i - 1][j - 1] = 'O';
					cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
					goto final;
				}
			}
			else if (j != 0 and tb[i][j] == 'N' and (tb[i - 1][j - 1] == ' ' or tb[i - 1][j - 1] == char(176)) and j > 0 and j < 8)
			{
				tb[i][j] = ' ';
				tb[i - 1][j - 1] = 'N';
				cout << "Ficha que movio la maquina: " << i + 1 << j + 1 << endl;
				goto final;
			}
		}
	}


	final:

	cout << endl;
}
