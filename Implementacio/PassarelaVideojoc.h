#pragma once
#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "Contenedor_linea.h"

using namespace std;

const string VideojocObtingut = "No es pot comprar el mateix videojoc més d'un cop!";

class PassarelaVideojoc
{
public:
    PassarelaVideojoc(pqxx::row row);
    PassarelaVideojoc();
    PassarelaVideojoc(string nomV, string generoV, int qualV, string dataLlV, int minsU);

    string obteNom();
    int obteQualificacio();
    string obteGenere();
    string obteDataLlancament();
    int obtemins_estimat();
   
private:
    string nom;
    string genere;
    int qualEdat;
    string dataLlancament;
    int mins_estimat;
    
};
