#pragma once
#include "PassarelaConte.h"
#include <string>
#include <iostream>
#include <pqxx/pqxx>

using namespace std;



class CercadoraConte
{
public:
	CercadoraConte();
	vector<string>  cercaPaquet(string nomP);
	vector<PassarelaConte> cercaVideojoc(string nomV);
private:
};