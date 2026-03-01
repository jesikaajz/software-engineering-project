#include "TxConsultaNovetatsVideojocs.h"

TxConsultaNovetatsVideojocs::TxConsultaNovetatsVideojocs(){}

void TxConsultaNovetatsVideojocs::executar(string dataM)
{
    vector<PassarelaVideojoc> llista_videojocs = v1.cercaNovetats(dataM);
    for (int i = 0; i < llista_videojocs.size(); i++)
    {
        resultat.push_back(llista_videojocs[i].obteNom());
    }
}
vector<string> TxConsultaNovetatsVideojocs::obteVideojocs()
{
    return resultat;
}