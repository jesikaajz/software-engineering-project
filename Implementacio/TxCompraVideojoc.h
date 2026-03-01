#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Transaccio.h"
#include "CercadoraCompres.h"
#include "CercadoraConte.h"
#include "PassarelaConte.h"
#include "PassarelaCompra.h"
#include "Videoconsola.h"
#include <ctime>

const string ErrorQualificacio = "L'usuari no compleix els requeriments d'edat minims";

class TxCompraVideojoc : public Transaccio
{
public:
	TxCompraVideojoc();
	void executar(string nomV);
	vector<string> obteResult();
private:
	vector<string> result;
};