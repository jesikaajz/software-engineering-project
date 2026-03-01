#pragma once
#include "Transaccio.h"
#include "PassarelaVideojoc.h"

class TxConsultaVideojocs : public Transaccio {
public:
    TxConsultaVideojocs();

    void executar();
    vector<string> obteVideojocs();

private:
    vector<string> resultat;
};
