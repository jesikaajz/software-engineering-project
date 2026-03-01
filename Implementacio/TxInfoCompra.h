#pragma once
#include "Transaccio.h"
#include "CercadoraCompres.h"
#include "CercadoraElemCompra.h"
#include "PassarelaCompra.h"
#include "PassarelaElemCompra.h"
#include "Videoconsola.h"

using namespace std;


class TxInfoCompra : public Transaccio
{
public:

	TxInfoCompra();
	void executar(string nomCompra);
	vector<string> obteResultat();
	vector<string> obteVideojocs_paquet();

private:
	vector<string> resultat;
	vector<string> videojocs_paquet;
};

