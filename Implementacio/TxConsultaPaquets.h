#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"


using namespace std;

class TxConsultaPaquets : public Transaccio {
public:
    TxConsultaPaquets();
    void executar();
    vector<string> obtePaquets();
private:
    vector<string> resultat;
   
};
