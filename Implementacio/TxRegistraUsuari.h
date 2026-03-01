#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"


using namespace std;



class TxRegistraUsuari : public Transaccio
{
public:
	TxRegistraUsuari(string nU, string sU,string cU,string ceU,string dnU);
	void executar();

private:
	string nomU;
	string sobrenomU;
	string contrasenyaU;
	string correuElectronicU;
	string DataNaixamentU;
};