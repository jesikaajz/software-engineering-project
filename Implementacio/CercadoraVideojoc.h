#pragma once
#include "PassarelaVideojoc.h"
#include <string>
#include <iostream>
#include <pqxx/pqxx>

using namespace std;

const string VideojocNoExisteix = "No existeix el videojoc desitjat";

class CercadoraVideojoc
{
public:
	PassarelaVideojoc cercaVideojoc(string nomV);
	vector<PassarelaVideojoc> cercaVideojocs();
	vector<PassarelaVideojoc> cercaVideojocsEdat(int edatM);
	vector<PassarelaVideojoc> cercaNovetats(string dataM);
	CercadoraVideojoc();
private:
};