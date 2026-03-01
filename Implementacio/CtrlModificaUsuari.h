#pragma once
#include <string>
#include <iostream>
#include "PassarelaUsuari.h"
#include "TxConsultaUsuari.h"

using namespace std;


class CtrlModificaUsuari{
public:
	CtrlModificaUsuari();
	vector<string> consultaUsuari();
	void modificarUsuari(string nomU, string contraU, string correU, string neixU);

private:
	PassarelaUsuari usuari;
};


