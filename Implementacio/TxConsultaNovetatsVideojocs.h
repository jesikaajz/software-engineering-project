#pragma once
#include "Transaccio.h"
#include "PassarelaVideojoc.h"

class TxConsultaNovetatsVideojocs : public Transaccio {
public:
    TxConsultaNovetatsVideojocs();

    void executar(string dataM);
    vector<string> obteVideojocs();

private:
    vector<string> resultat;
};