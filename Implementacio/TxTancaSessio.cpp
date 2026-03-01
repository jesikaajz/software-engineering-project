#include "TxTancaSessio.h"

TxTancaSessio::TxTancaSessio(){}

void TxTancaSessio::executar()
{
	Videoconsola& videoconsola = Videoconsola::getInstance();
	videoconsola.tancaSessio();
}