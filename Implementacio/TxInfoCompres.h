#pragma once
#include "Transaccio.h"
#include "CercadoraCompres.h"
#include "CercadoraElemCompra.h"
#include "PassarelaCompra.h"
#include "PassarelaElemCompra.h"
#include "Videoconsola.h"

using namespace std;


class TxInfoCompres : public Transaccio
{
public:

	TxInfoCompres();
	void executar();
	vector<float> obteResultat();
	vector<string> obtecompres();

private:
	vector<float> resultat = {0,0,0};
	vector<string> compres;

};

