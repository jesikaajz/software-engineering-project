#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"
#include "Videoconsola.h"

using namespace std;

const string ErrorCont = "La contrasenya no es correcta, l'usuari no s'ha esborrat";

class TxEsborraUsuari : public Transaccio
{
public:
	TxEsborraUsuari(string cU);
	void executar();

private:
	string contraU;
};
