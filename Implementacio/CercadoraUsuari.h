#pragma once
#include "PassarelaUsuari.h"
#include <string>
#include <iostream>
#include <pqxx/pqxx>

using namespace std;

const string UsuariNoExisteix = "Hi ha hagut un error amb el sobrenom o la contrasenya";

class CercadoraUsuari
{
public:
	PassarelaUsuari cercaUsuari(string sobrenomU);
	CercadoraUsuari();
private:
};
