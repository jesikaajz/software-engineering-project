#include "TxInfoCompra.h"

TxInfoCompra::TxInfoCompra(){}
void TxInfoCompra::executar(string nomCompra)
{
	PassarelaElemCompra ec = compraelem1.cercaElement(nomCompra);
	if (ec.obteTipus() == "paquet")
	{
		vector<string> videojocs = contiene.cercaPaquet(nomCompra);
		for (int i = 0; i < videojocs.size(); i++)
		{
			PassarelaElemCompra ec2 = compraelem1.cercaElement(videojocs[i]);
			videojocs_paquet.push_back(videojocs[i]);
			videojocs_paquet.push_back(ec2.obteDescripcio());	
		}

	}
	Videoconsola& videoconsola = Videoconsola::getInstance();
	PassarelaUsuari us = videoconsola.obteUsuari();
	string usuari = us.obteSobrenom();
	PassarelaCompra c1 = Compra1.cercaCompra_element(nomCompra,usuari);
	resultat.push_back(c1.obteData());
	resultat.push_back(c1.obteElementCompra());
	resultat.push_back(ec.obteDescripcio());
	resultat.push_back(to_string(c1.obtePreuPagat()));
	

}
vector<string> TxInfoCompra::obteResultat()
{
	return resultat;
}

vector<string> TxInfoCompra::obteVideojocs_paquet()
{
	return videojocs_paquet;
}