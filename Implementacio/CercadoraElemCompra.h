#pragma once
#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "PassarelaElemCompra.h"
#include<vector>

using namespace std;


class CercadoraElemCompra
{
public:
	PassarelaElemCompra cercaElement(string elem);
	CercadoraElemCompra();
private:
};

