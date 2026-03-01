#include "TxConsultaVideojocsEdat.h"

TxConsultaVideojocsEdat::TxConsultaVideojocsEdat(){}

void TxConsultaVideojocsEdat::executar(int edatM)
{
    vector<PassarelaVideojoc> llista_videojocs = v1.cercaVideojocsEdat(edatM);
    for (int i = 0; i < llista_videojocs.size(); i++)
    {
        resultat.push_back(llista_videojocs[i].obteNom());
    }
}
vector<string> TxConsultaVideojocsEdat::obteVideojocs()
{
    return resultat;
}