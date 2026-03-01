#include "TxInfoCompres.h"

TxInfoCompres::TxInfoCompres(){}

void TxInfoCompres::executar()
{
	Videoconsola& videoconsola = Videoconsola::getInstance();
	PassarelaUsuari u = videoconsola.obteUsuari();
	vector<PassarelaCompra> compresU = Compra1.cercaCompra(u.obteSobrenom());
	for (int i = 0; i < compresU.size(); i++)
	{
		compres.push_back(compresU[i].obteElementCompra());
	}
	float totalVideojocs = 0, totalPaquets = 0;
	float totalEuros = 0;
	for (int i = 0; i < compresU.size(); i++)
	{
		float preuE = compresU[i].obtePreuPagat();
		string elem = compresU[i].obteElementCompra();
		PassarelaElemCompra ec = compraelem1.cercaElement(elem);
		string tipusE = ec.obteTipus();
		totalEuros += preuE;
		if (tipusE == "paquet") totalPaquets++;
		if(tipusE == "videojoc") 
			totalVideojocs++;
	}

	resultat[0] = totalVideojocs;
	resultat[1] = totalPaquets;
	resultat[2] = totalEuros;
}

vector<float> TxInfoCompres::obteResultat(){
	return resultat;
}

vector<string> TxInfoCompres::obtecompres()
{
	return compres;
}