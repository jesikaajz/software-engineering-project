#include "CtrlModificaUsuari.h"


CtrlModificaUsuari::CtrlModificaUsuari() {}

vector<string>  CtrlModificaUsuari::consultaUsuari()
{
	TxConsultaUsuari tx2 = TxConsultaUsuari();
	tx2.executar();
	vector<string>  infoUsu = tx2.obteResultat();
	usuari = tx2.obteUsuari();
	return infoUsu;
}
void CtrlModificaUsuari::modificarUsuari(string nomU, string contraU, string correU, string neixU)
{
	if (!nomU.empty()) usuari.posaNom(nomU);
	if (!contraU.empty()) usuari.posaContrasenya(contraU);
	if (!correU.empty()) usuari.posaCorreuElectronic(correU);
	if (!neixU.empty()) usuari.posaDataNaixament(neixU);
	if(!nomU.empty() or !contraU.empty() or !correU.empty() or !neixU.empty())usuari.modifica();
	
}
