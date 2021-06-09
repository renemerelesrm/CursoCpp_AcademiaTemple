#include <iostream>
#include "Autos.h"



void Meta()
{

		char* meta = new char;
		*meta = char(219);

		for (int filas = 0; filas < 25; filas++)
		{
			for (int columnas = 0; columnas < 8; columnas++)
			{
				Console::SetCursorPosition(columnas + 106, filas + 1);
				Console::ForegroundColor = ConsoleColor::White;
				cout << *meta;
			}

		}
}



int main()
{

	int maximo = 0;
	string minimoStr = "Conpetencia\nDe naves:\n\nMinimo 2 \nMaximo 6\n";
	cout << minimoStr;	
	cin >> maximo ;

	cout << "Compiten\n"<< maximo << " naves" << endl;


	if (maximo >1 && maximo <= 6)
	{
		char* meta = new char;
		*meta = char(219);

		for (int filas = 0; filas < 25; filas++)
		{
			for (int columnas  = 0; columnas < 1; columnas++)
			{
				Console::SetCursorPosition(columnas +105, filas + 1);
				Console::ForegroundColor = ConsoleColor::Red;
				cout << *meta;
			}

			//cout << endl;
		}

		Meta();
		Juego* juego = new Juego((maximo ));
		
		juego->Carrera();

		
		getch();

	}
	else
	{
		cout << "La cantidad para la carrera es invalida" << endl;

		system("pause");


		return 0;

	}
}