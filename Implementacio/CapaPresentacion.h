#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "TxIniciaSessio.h"
#include "TxRegistraUsuari.h"
#include "TxTancaSessio.h"
#include "TxEsborraUsuari.h"
#include "CtrlModificaUsuari.h"
#include "TxConsultaUsuari.h"
#include "TxInfoCompres.h"
#include "TxConsultaVideojoc.h"
#include "TxConsultaVideojocs.h"
#include "TxConsultaVideojocsEdat.h"
#include "TxConsultaNovetatsVideojocs.h"
#include "TxConsultaPaquet.h"
#include "TxConsultaPaquets.h"
#include "TxCompraVideojoc.h"
#include "TxInfoCompra.h"
#include "TxComprarPaquet.h"
#include <string>
#include <ctime>
#include "conio.h"
#include <iostream>




using namespace std;

const string notancarsessio = "N";
const string nocomprar = "L'usuari no confirma la compra";

class CapaPresentacion
{
public:
	void iniciSessio();
	void registrarUsuari();
	void consultaUsuari();
	void modificaUsuari();
	void esborraUsuari();
	void comprarVideojoc();
	void consultaVideojoc();
	void consultaVideojocs();
	void consultaVideojocsEdat();
	void consultaNovetatsVideojocs();
	void consultarpaquet();
	void consultarpaquets();
	void tancarSessio();
	void consultarcompres();
	void comprarPaquet();
private:
};
