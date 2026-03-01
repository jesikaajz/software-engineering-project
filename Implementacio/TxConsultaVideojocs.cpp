#include "TxConsultaVideojocs.h"

TxConsultaVideojocs::TxConsultaVideojocs(){}

void TxConsultaVideojocs::executar()
{
    vector<PassarelaVideojoc> llista_videojocs = v1.cercaVideojocs();
    for (int i = 0; i < llista_videojocs.size(); i++)
    {
        resultat.push_back(llista_videojocs[i].obteNom());
    }
}
vector<string> TxConsultaVideojocs::obteVideojocs()
{
    return resultat;
}

