#pragma once
#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "PassarelaPaquet.h"

using namespace std;

const string PaquetNoExisteix = "El paquete no existe en el sistema";

class CercadoraPaquet
{
public:
	CercadoraPaquet();
	vector<string>  cercaPaquets();
	PassarelaPaquet cercaPaquet(string nomP);
private:
};


