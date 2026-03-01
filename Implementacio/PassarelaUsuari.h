#pragma once
#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "Contenedor_linea.h"

using namespace std;

const string SobrenomExisteix = "Ja existeix un usuari amb aquest sobrenom";

const string CorreuExisteix = "Ja existeix un usuari amb aquest correu electronic";

class PassarelaUsuari
{
public:
    PassarelaUsuari(pqxx::row row);
    PassarelaUsuari();
    PassarelaUsuari(string nom, string sobrenom, string contrasenya, string correuElectronic, string dataNaixament);

    void insereix();
    void esborra();
    void modifica();
    void posaNom(string nomU);
    void posaContrasenya(string contraU);
    void posaCorreuElectronic(string correuU);
    void posaDataNaixament(string neixU);

    string obteNom();
    string obteSobrenom();
    string obteContrasenya();
    string obteCorreuElectronic();
    string obteDataNaixement();
   
private:
    string nom;
    string sobrenom;
    string contrasenya;
    string correuElectronic;
    string dataNaixament;
    
};
