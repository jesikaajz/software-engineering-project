#pragma once
#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "Contenedor_linea.h"

using namespace std;


class PassarelaConte
{
public:
    PassarelaConte(pqxx::row row);
    PassarelaConte();
    PassarelaConte(string paquetC,string videojocC);
    string obtePaquet();
    string obteVideojoc();

private:
    string paquet;
    string videojoc;
    
};
