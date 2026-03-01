#pragma once
#include "Transaccio.h"
#include "PassarelaVideojoc.h"

class TxConsultaVideojocsEdat : public Transaccio {
public:
    TxConsultaVideojocsEdat();

    void executar(int edatM);
    vector<string> obteVideojocs();

private:
    vector<string> resultat;
};