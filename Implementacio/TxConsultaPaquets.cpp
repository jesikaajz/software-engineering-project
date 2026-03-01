#include "TxConsultaPaquets.h"


TxConsultaPaquets::TxConsultaPaquets(){}

void TxConsultaPaquets::executar()
{
	resultat = p1.cercaPaquets();	
}

vector<string> TxConsultaPaquets::obtePaquets()
{
	return resultat;
}
