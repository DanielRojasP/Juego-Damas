#include "pch.h"
#include "Tablero.h"


Tablero::Tablero()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
			Tab[i][j] = ' ';
	}
}
Tablero::~Tablero()
{
}
void Tablero::tableroVacio(char ta[][8])
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
			ta[i][j] = ' ';
	}
}
void Tablero::tableroInicializado(char ta[][8])
{
	ta[0][1] = 'X'; ta[0][3] = 'X'; ta[0][5] = 'X'; ta[0][7] = 'X';
	ta[1][0] = 'X'; ta[1][2] = 'X'; ta[1][4] = 'X'; ta[1][6] = 'X';
	ta[2][1] = 'X'; ta[2][3] = 'X'; ta[2][5] = 'X'; ta[2][7] = 'X';

	ta[0][2] = '-'; ta[0][4] = '-'; ta[0][6] = '-'; ta[1][1] = '-';
	ta[1][3] = '-'; ta[1][5] = '-'; ta[1][7] = '-'; ta[2][2] = '-';
	ta[2][4] = '-'; ta[2][6] = '-'; ta[3][1] = '-'; ta[3][3] = '-';
	ta[0][0] = '-'; ta[2][0] = '-'; ta[4][0] = '-'; ta[4][2] = '-';
	ta[3][5] = '-'; ta[3][7] = '-'; ta[4][4] = '-'; ta[4][6] = '-';

	ta[5][0] = 'O'; ta[5][2] = 'O'; ta[5][4] = 'O'; ta[5][6] = 'O';
	ta[6][1] = 'O'; ta[6][3] = 'O'; ta[6][5] = 'O'; ta[6][7] = 'O';
	ta[7][0] = 'O'; ta[7][2] = 'O'; ta[7][4] = 'O'; ta[7][6] = 'O';

	ta[5][1] = '-'; ta[5][3] = '-'; ta[5][5] = '-'; ta[5][7] = '-';
	ta[6][0] = '-'; ta[6][2] = '-'; ta[6][4] = '-'; ta[6][6] = '-';
	ta[7][1] = '-'; ta[7][3] = '-'; ta[7][5] = '-'; ta[7][7] = '-';

}
void Tablero::mostrarTablero(char ta[][8])
{
	for (int i = 7; i >= 0; i--)
	{
		cout << "  ---------------------------------" << endl;
		cout << i + 1 << " | " << ta[i][0] << " | " << ta[i][1] << " | " << ta[i][2] << " | " << ta[i][3] << " | " << ta[i][4] << " | " << ta[i][5] << " | " << ta[i][6] << " | " << ta[i][7] << " |" << endl;
	}
	cout << "  ---------------------------------" << endl;
	cout << "    1   2   3   4   5   6   7   8  " << endl;
}
bool Tablero::juegoTerminado(char tb[][8])
{
	int contador = 0;
	int contador2 = 0;
	for (int i=0; i<8; i++) 
	{
		for (int j=0; j<8; j++) 
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
	if(contador == 0) { return true; }
	if(contador2 == 0){ return true; }
	      else        { return false; }
}
void Tablero::guardar_p(string nom, char ta[][8])
{
	cout << "Ingrese el nombre del jugador" << endl;
	cin.ignore();
	getline(cin, nom);
	nom += ".txt";
	ofstream t(nom.c_str());
	if (t)
	{
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (ta[i][j] == ' ')
				{
					ta[i][j] = char(176);
					t << ta[i][j];
				}
				else
				{
					t << ta[i][j];
				}
			}
		}
		cout << "La partida ha sido guardada" << endl;
		t.close();
	}
	else  cout << "Error de apertura del archivo." << endl;

	t.close();
}

void Tablero::cargar_p(string nom, char ta[][8])
{
	
	//cin.ignore();
	//getline(cin, nom);
	nom += ".txt";
	ifstream t(nom.c_str());
	tableroVacio(ta);

	if (t)
	{
		cout << "El archivo se abrio correctamente " << endl;
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				t >> ta[i][j];
			}
			cout << endl;
		}
		mostrarTablero(ta);

		system("pause");
	}
	if (!t)
	{
		cout << "Error abriendo el fichero" << endl;
	}

	t.close();
	cin.get();
} 
