#include "TxConsultaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari(){}

void TxConsultaUsuari::executar(){
    Videoconsola& videoconsola = Videoconsola::getInstance();
    PassarelaUsuari u = videoconsola.obteUsuari();
    usuari = u;

    resultat[0] = u.obteNom();
    resultat[1] = u.obteSobrenom();
    resultat[2] = u.obteCorreuElectronic();
    resultat[3] = u.obteDataNaixement();
}

vector<string>  TxConsultaUsuari::obteResultat(){
    return resultat;
}

PassarelaUsuari TxConsultaUsuari::obteUsuari(){
    return usuari;    
}