#include "TxIniciaSessio.h"

TxIniciSessio::TxIniciSessio(string sU, string cU)
{
	sobrenomU = sU;
	contrasenyaU = cU;
}
void TxIniciSessio::executar()
{
	PassarelaUsuari p1 = c1.cercaUsuari(sobrenomU);
	if (p1.obteContrasenya() != contrasenyaU) throw(ErrorContranseya);
	Videoconsola& videoconsola = Videoconsola::getInstance();
	videoconsola.iniciaSessio(p1);
}
