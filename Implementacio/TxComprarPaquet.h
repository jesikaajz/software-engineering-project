#pragma once
#include "Transaccio.h"
#include "CercadoraCompres.h"
#include "PassarelaCompra.h"
#include "Videoconsola.h"




class TxComprarPaquet : public Transaccio
{
public:
	TxComprarPaquet(string usuariC,string elementC,string dataC,float preu_pagatC);
	void executar();

private:
	string usuari;
	string element;
	string data;
	float preu_pagat;
};
