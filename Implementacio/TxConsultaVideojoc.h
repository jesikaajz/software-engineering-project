#pragma once
#include "Transaccio.h"
#include "PassarelaVideojoc.h"
#include "PassarelaElemCompra.h"

class TxConsultaVideojoc : public Transaccio{
public:
    TxConsultaVideojoc();

    void executar(string nomV);
    vector<string> obteResultat();
    PassarelaVideojoc obteVideojoc();
    vector<string> obtePaquets();

private:
    vector<string> resultat;
    vector<string> paquets;
    PassarelaVideojoc videojoc;
};