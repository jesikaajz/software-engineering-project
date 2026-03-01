#pragma once

#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "Contenedor_linea.h"

using namespace std;


class PassarelaPaquet
{
public:
    PassarelaPaquet(pqxx::row row);
    PassarelaPaquet();
    PassarelaPaquet(string nomP);
    string obtePaquetNom();
private:
    string nom;
};
