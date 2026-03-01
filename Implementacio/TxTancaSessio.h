#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"
#include "Videoconsola.h"

using namespace std;

class TxTancaSessio : public Transaccio
{
public:
	TxTancaSessio();
	void executar();

private:
};