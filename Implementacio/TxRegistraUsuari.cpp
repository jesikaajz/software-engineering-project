#include "TxRegistraUsuari.h"

TxRegistraUsuari::TxRegistraUsuari(string nU, string sU, string cU, string ceU, string dnU)
{
	if (nU == "" or sU == "" or cU == "" or ceU == "" or dnU == "")throw(string("Algun camp esta buit"));
	else
	{
		nomU = nU;
		sobrenomU = sU;
		contrasenyaU = cU;
		correuElectronicU = ceU;
		DataNaixamentU = dnU;
	}
}

void TxRegistraUsuari::executar()
{
	PassarelaUsuari l1 = PassarelaUsuari(nomU, sobrenomU, contrasenyaU, correuElectronicU, DataNaixamentU);
	l1.insereix();
	
}