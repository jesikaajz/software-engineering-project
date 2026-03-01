#include "TxConsultaVideojoc.h"

TxConsultaVideojoc::TxConsultaVideojoc(){}

void TxConsultaVideojoc::executar(string nomV){
    PassarelaVideojoc v = v1.cercaVideojoc(nomV);
    videojoc = v;

    PassarelaElemCompra ec = compraelem1.cercaElement(nomV);

    resultat.push_back(v.obteNom());
    resultat.push_back(ec.obteDescripcio());
    resultat.push_back(v.obteGenere());
    resultat.push_back(to_string(v.obteQualificacio()));
    resultat.push_back(v.obteDataLlancament());
    resultat.push_back(to_string(ec.obtePreu()));
    if(v.obtemins_estimat() > 0)resultat.push_back(to_string(v.obtemins_estimat()));

    vector<PassarelaConte> paquetsC = contiene.cercaVideojoc(nomV);
    for (int i = 0; i < paquetsC.size(); i++)
    {
        paquets.push_back(paquetsC[i].obtePaquet());
    }
}

vector<string>  TxConsultaVideojoc::obteResultat(){
    return resultat;
}

PassarelaVideojoc TxConsultaVideojoc::obteVideojoc(){
    return videojoc;    
}

vector<string> TxConsultaVideojoc::obtePaquets()
{
    return paquets;
}