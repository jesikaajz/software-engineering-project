#pragma once
#include "Transaccio.h"
#include "PassarelaPaquet.h"
#include "PassarelaElemCompra.h"

class TxConsultaPaquet : public Transaccio{
public:
    TxConsultaPaquet();
    void executar(string nomP);
    void infoEC(string nomV);
    vector<string> obteResultat();
    vector<string> obteLlistavideojocs();
    vector<string> obteInfoEC();
    float obtepreuJocs();
private:
    vector<string> resultat;
    vector<string> llista_videojocs;
    vector<string> info = { "","" };
    float preuJocs;
};