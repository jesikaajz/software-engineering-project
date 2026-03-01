#pragma once

#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "Contenedor_linea.h"

using namespace std;


class PassarelaElemCompra
{
public:
    PassarelaElemCompra(pqxx::row row);
    PassarelaElemCompra();
    PassarelaElemCompra(string nomP, string descripcioP, float preuP, string tipusP);
    string obteTipus();
    string obteDescripcio();
    float obtePreu();
    string obteNom();
 

private:
    string nom;
    string descripcio;
    float preu; 
    string tipus;
};