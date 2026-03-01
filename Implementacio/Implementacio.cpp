// Implementacio.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <list>
#include <set>
#include <cstdlib>
#include <fstream>
#include "CapaPresentacion.h"
#include "Contenedor_linea.h"
#include "conio.h"



using namespace std;


void menu_consultes_videojocs()
{
	bool repite = true;
	int opcion;
	do
	{
		std::cout << "\033[2J\033[1;1H";
		cout << "----------------------\n";
		cout << "  Consultes Videojocs\n";
		cout << "----------------------\n";
		cout << "1. Consultar videojoc\n";
		cout << "2. Consultar videojocs\n";
		cout << "3. Consultar videojocs per edat\n";
		cout << "4. Consultar novetats videojocs\n";
		cout << "5. Consultar paquet videojocs\n";
		cout << "6. Consultar paquets videojocs\n";
		cout << "7. Tornar\n";
		cout << "Opcio:" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			try {
				CapaPresentacion m1;
				m1.consultaVideojoc();
			}
			catch (string err) {
			}
			cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Videojocs";
			_getch();
			break;
		case 2:
			try
			{
				CapaPresentacion m2;
				m2.consultaVideojocs();
			}
			catch(string err)
			{

			}
			cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Videojocs";
			_getch();
			break;
		case 3:
			try
			{
				CapaPresentacion m3;
				m3.consultaVideojocsEdat();
			}
			catch (string err)
			{

			}
			cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Videojocs";
			_getch();
			std::cout << "\033[2J\033[1;1H";
			break;
		case 4:
			try
			{
				CapaPresentacion m4;
				m4.consultaNovetatsVideojocs();
			}
			catch(string err)
			{

			}
			cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Videojocs";
			_getch();
			break;
		case 5:
			try
			{
				CapaPresentacion m4;
				m4.consultarpaquet();
			}
			catch (string err)
			{

			}
			cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Videojocs";
			_getch();
			break;
		case 6:
			try
			{
				CapaPresentacion m5;
				m5.consultarpaquets();
			}
			catch (string err)
			{

			}
			cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Videojocs";
			_getch();
			break;
		case 7:
			repite = false;
			return;
			break;
		default:
			break;
		}
	} while (repite);
}
void menu_gestionar_compres()
{
	bool repite = true;
	int opcion;
	do
	{
		std::cout << "\033[2J\033[1;1H";
		cout << "----------------------\n";
		cout << "  Gestionar compres\n";
		cout << "----------------------\n";
		cout << "1. Comprar videojocs\n";
		cout << "2. Comprar paquet videojocs\n";
		cout << "3. Consultar compres\n";
		cout << "4. Tornar\n";
		cout << "Opcio:" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			try
			{
				CapaPresentacion m1;
				m1.comprarVideojoc();
			}
			catch (string err)
			{

			}
			cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Compres";
			_getch();
			break;
		case 2:
			try
			{
				CapaPresentacion m1;
				m1.comprarPaquet();
			}
			catch (string err)
			{
				std::cerr << err << std::endl;
			}
			cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Compres";
			_getch();
			break;
		case 3:
			try
			{
				CapaPresentacion m1;
				m1.consultarcompres();

			}
			catch (string err)
			{

			}
			cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Compres";
			_getch();
			break;
		case 4:
			repite = false;
			break;
		default:
			break;
		}
	} while (repite);
}
bool menu_gestionar_usuari()
{
	bool repite = true;
	int opcion;
	do
	{
		std::cout << "\033[2J\033[1;1H";
		cout << "----------------------\n";
		cout << "  Gestionar usuari\n";
		cout << "----------------------\n";
		cout << "1. Consultar usuari\n";
		cout << "2. Modificar usuari\n";
		cout << "3. Esborrar usuari\n";
		cout << "4. Tornar\n";
		cout << "Opcio:" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			try
			{
			CapaPresentacion m1;
			m1.consultaUsuari();
			}
			catch(string err)
			{
				
			}
			cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Usuari";
			_getch();
			break;
		case 2:
			try
			{
				CapaPresentacion m1;
				m1.modificaUsuari();
				cout << "Pulsa ENTER o qualsevol tecla per continuar";
			}
			catch (string err)
			{
				cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Usuari";
			}
			_getch();
			break;
		case 3:
			try
			{
				CapaPresentacion es1;
				es1.esborraUsuari();
				_getch();
				return repite;
			}
			catch (string err)
			{
				cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Gestio Usuari";
			}
			_getch();
			break;
		case 4:
			repite = false;
			break;
		default:
			break;
		}
	} while (repite);
	return repite;
	
}

void menu_usuari()
{
	bool repite = true;
	bool repite2;
	int opcion;
	do
	{
		std::cout << "\033[2J\033[1;1H";
		cout << "*******************\n";
		cout << "  Menu Principal\n";
		cout << "*******************\n";
		cout << "1. Gestionar usuari\n";
		cout << "2. Gestionar compres\n";
		cout << "3. Consultar Videojocs\n";
		cout << "4. Tancar sessio\n";
		cout << "5. Sortir\n";
		cout << "Opcio:" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			 repite2 = menu_gestionar_usuari();
			if (repite2 == true) return;
			break;
		case 2:
			menu_gestionar_compres();
			break;
		case 3:
			menu_consultes_videojocs();
			break;
		case 4:
			try{
				CapaPresentacion t1;
				t1.tancarSessio();
				repite = false;
			} catch(string e){}
			break;
		case 5:
			repite = false;
			exit(0);
			break;
		default:
			break;
		}
	} while (repite);
	return;
}

int main()
{
	string nombre_del_archivo = "C:/Users/Gerard/Desktop/Proyecto INEP/Conexion_externa.txt";
	ifstream archivo(nombre_del_archivo);
	if (archivo.is_open())
	{
		getline(archivo, Contenedor_linea::linea);
		archivo.close();
	}
	else
	{
		cout << "No s'ha pogut obrir el " << nombre_del_archivo << "\n";
		return 1;
	}
	bool repite = true;
	int opcion;
	do {
		std::cout << "\033[2J\033[1;1H";
		cout << "*******************\n";
		cout << "  Menu Principal\n";
		cout << "*******************\n";
		cout << "1. Iniciar Sessio\n";
		cout << "2. Registrar usuari\n";
		cout << "3. Sortir\n";
		cout << "Opcio:" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
		{
			try
			{
				CapaPresentacion i1;
				i1.iniciSessio();
				std::cout << "\033[2J\033[1;1H";
				cout << "Sessio iniciada correctament! Pulsa Enter o qualsevol tecla per accedir al Menu";
				_getch();
				menu_usuari();
			}
			catch (string err)
			{
				cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Sessio";	
			}
			_getch();
			break;
		}
		case 2:
		{
			try
			{
				CapaPresentacion r1;
				r1.registrarUsuari();
				_getch();
				menu_usuari();
			}
			catch(string err)
			{
				cout << "Pulsa ENTER o qualsevol tecla per tornar al Menu de Sessio";
			}
			_getch();
			break;
		}
		case 3:
		{
			repite = false;
			break; 
		}
		default:
		{
			break; 
		}
		}
	} while(repite);

}