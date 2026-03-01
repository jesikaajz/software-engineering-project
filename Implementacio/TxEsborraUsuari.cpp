#include "TxEsborraUsuari.h"

TxEsborraUsuari::TxEsborraUsuari(string cU)
{
	contraU = cU;
}
void TxEsborraUsuari::executar()
{
	Videoconsola& videoconsola = Videoconsola::getInstance();
    PassarelaUsuari p1 = videoconsola.obteUsuari();
	if (p1.obteContrasenya() != contraU) 
        throw(ErrorCont);
	else
        p1.esborra();
}
