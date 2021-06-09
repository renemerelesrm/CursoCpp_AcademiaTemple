#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <string_view>
using namespace System;
using namespace std;

//Inicia Clase MoverAuto
class MoverAuto
{

private:
	int x, y;
	int pesoMaximo;

public:
	MoverAuto(int n)
	{
		_sleep(3);
		Random P;
		pesoMaximo = P.Next(3, 6);
		x = 10;
		y = n * 3;
	}

	void SetX(int n)
	{
		x = n;
	}
	void SetY(int n)
	{
		y = n;
	}

	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}

	void Borrar()
	{
		
		Console::SetCursorPosition(x + 10, y + 10);
		cout << " ";


	}
	void Mover()
	{
		x++;
	}


	void Mostrar()
	{
	
		Console::SetCursorPosition(x + 10, y + 10);
		
		Console::ForegroundColor = ConsoleColor::DarkGreen;
		
	//	cout << (char)186;///la cabeza del auto
		Console::SetCursorPosition(x, y + 0); cout <<"   /------\\";
		Console::SetCursorPosition(x, y + 1); cout << " <(********)> ";
		//Console::SetCursorPosition(x, y + 2); cout << "   ";
		//Console::SetCursorPosition(x, y + 3); cout << "               ";
	}


};

//Fin de la clase Mover Auto

//Inicio Clase PesoAuto
class PesoAuto
{
private:
int x, y;
	
};


// Fin de la clase PesoAuto
// 
//Iinicio Clase Auto
class Auto
{
private:

	MoverAuto* elAuto;
	PesoAuto** chasis;
	int velocidad;

public:
	Auto(int n)
	{
		_sleep(3);
		Random Peso;
		elAuto = new MoverAuto(n);
		velocidad = 0;
		VelocidadMax(Peso.Next(2, 8), n);
	}
	~Auto()
	{
		delete elAuto;
	}

	void VelocidadMax(int n, int nt)
	{
		for (int i = 0; i < n; i++)
		{
			PesoAuto** aux = new PesoAuto* [velocidad + 1];

			for (int i = 0; i < velocidad; i++)
				aux[i] = chasis[i];

			velocidad++;
			chasis = aux;
		}
	}


	void Borrar()
	{
		elAuto->Borrar();
		for (int i = 0; i < velocidad; i++)
			chasis[i];
	}

	void Mover(int n)
	{
		if (n % velocidad == 0)
		{
			elAuto->Mover();
			for (int i = 0; i < velocidad; i++)
				chasis[i];
		}
	}
	void Mostrar()
	{
		elAuto->Mostrar();
		
	}

	MoverAuto* GetElAuto()
	{
		return elAuto;
	}
};

//Fin de la clase Auto


//Inicio de la clase Juego
class Juego
{
private:
	Auto**autos;
	int cant;
public:
	Juego(int n)
	{
		cant = 0;
		
		AgregarAuto(n);
		
	}

	~Juego()
	{
		for (int i = 0; i < cant; i++)
			delete autos[i];
	}

	void AgregarAuto(int n)
	{
		for (int w = 0; w < n; w++)
		{
			Auto** aux = new Auto * [cant + 1];

			for (int i = 0; i < cant; i++)
				aux[i] = autos[i];

			aux[cant] = new Auto(w);

			cant++;
			autos = aux;
		}
	}


	void Carrera()
	{
		for (int m = 0; true; m++)
		{
			for (int i = 0; i < cant; i++)
			{
				autos[i]->Borrar();
				autos[i]->Mover(m);
				autos[i]->Mostrar();

				if (autos[i]->GetElAuto()->GetX() == 91)
				{
					Console::ForegroundColor = ConsoleColor::Red;
					cout << " Ganador  ";
					return;

				}
			}

			if (m == 100) m = 0;

			_sleep(15);
		} 
	}
};
//Fin de la clase Juego
