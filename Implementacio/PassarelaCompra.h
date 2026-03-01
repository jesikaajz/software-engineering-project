#pragma once
#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "Contenedor_linea.h"

using namespace std;

const string ErrorObtingut = "L'usuari ja ha comprat el videojoc/paquet amb anterioritat";

class PassarelaCompra
{
public:
    PassarelaCompra(pqxx::row row);
    PassarelaCompra();
    PassarelaCompra(string usuari, string element, string data, float PreuPagat);
    void insereix();
    string obteElementCompra();
    float obtePreuPagat();
    string obteData();

private:
    string usuari;
    string element;
    string data;
    float PreuPagat;
};