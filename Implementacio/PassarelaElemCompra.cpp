#include "PassarelaElemCompra.h"

PassarelaElemCompra::PassarelaElemCompra(string nomP, string descripcioP, float preuP, string tipusP)
{
    nom = nomP;
    descripcio = descripcioP;
    preu = preuP;
    tipus = tipusP;
}

PassarelaElemCompra::PassarelaElemCompra(pqxx::row row)
{
    nom = row[0].c_str();
    descripcio = row[1].c_str();
    preu = row[2].as<float>();
    tipus = row[3].c_str();
}

PassarelaElemCompra::PassarelaElemCompra() {}

string PassarelaElemCompra::obteNom(){
    return nom;
}

string PassarelaElemCompra::obteTipus() {
    return tipus;
}

string PassarelaElemCompra::obteDescripcio()
{
    return descripcio;
}
float PassarelaElemCompra::obtePreu()
{
    return preu;
}


