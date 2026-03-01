#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"
#include "CercadoraUsuari.h"
#include "Videoconsola.h"

using namespace std;

const string ErrorContranseya = "Hi ha hagut un error amb el sobrenom o la contrasenya";

class TxIniciSessio : public Transaccio
{
public:

	TxIniciSessio(string sU, string cU);
	void executar();

private:
	string sobrenomU;
	string contrasenyaU;
};
