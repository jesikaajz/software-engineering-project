#include "TxComprarPaquet.h"


TxComprarPaquet::TxComprarPaquet(string usuariC,string elementC,string dataC,float preu_pagatC)
{

	usuari = usuariC;
	element = elementC;
	data = dataC;
	preu_pagat = preu_pagatC;
}
void TxComprarPaquet::executar()
{
	PassarelaCompra l1 = PassarelaCompra(usuari,element,data,preu_pagat);
	l1.insereix();
}