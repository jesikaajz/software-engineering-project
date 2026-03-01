#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"
#include "Videoconsola.h"

using namespace std;

class TxConsultaUsuari : public Transaccio{
public:
    TxConsultaUsuari();

    void executar();
    vector<string> obteResultat();
    PassarelaUsuari obteUsuari();

private:
    vector<string> resultat = {"","","",""};
    PassarelaUsuari usuari;
};