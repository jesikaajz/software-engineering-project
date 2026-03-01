#include "PassarelaVideojoc.h"

PassarelaVideojoc::PassarelaVideojoc(string nomV, string generoV, int qualV, string dataLlV, int minsU)
{
    nom = nomV;
    genere = generoV;
    qualEdat = qualV;
    dataLlancament = dataLlV;
    mins_estimat = minsU;
}

PassarelaVideojoc::PassarelaVideojoc(pqxx::row row)
{
    nom = row[0].c_str();
    genere = row[1].c_str();
    qualEdat = row[2].as<int>();
    dataLlancament = row[3].c_str();
    if(row[4].size() != 0) mins_estimat = row[4].as<int>();

}

PassarelaVideojoc::PassarelaVideojoc(){}

string PassarelaVideojoc::obteNom(){
    return nom;
}

int PassarelaVideojoc::obteQualificacio()
{
    return qualEdat;
}

string PassarelaVideojoc::obteGenere(){
    return genere;
}

string PassarelaVideojoc::obteDataLlancament(){
    return dataLlancament;
}

int PassarelaVideojoc::obtemins_estimat(){
    return mins_estimat;
}