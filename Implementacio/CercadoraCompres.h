#pragma once
#include "PassarelaCompra.h"
#include <string>
#include <iostream>
#include <pqxx/pqxx>

using namespace std;

const string CompraNoExisteix = "La compra no existeix";

class CercadoraCompres
{
public:
	vector<PassarelaCompra> cercaCompra(string sobrenomU);
	PassarelaCompra cercaCompra_element(string elementC,string sobrenomC);
	CercadoraCompres();
private:
};