#include "TxCompraVideojoc.h"

TxCompraVideojoc::TxCompraVideojoc(){}

void TxCompraVideojoc::executar(string nomV){
    PassarelaVideojoc v = v1.cercaVideojoc(nomV);
    Videoconsola& videoconsola = Videoconsola::getInstance();
    PassarelaUsuari u = videoconsola.obteUsuari();

    string dataNU = u.obteDataNaixement();
    dataNU = dataNU.substr(0, 4);
    int anyNU = stoi(dataNU);
    time_t now = time(0);
   	tm *ltm = localtime(&now);
	int anyNow = (1900 + ltm->tm_year);
    if(anyNow-anyNU < v.obteQualificacio())
        throw(ErrorQualificacio);
    
    PassarelaElemCompra ec = compraelem1.cercaElement(nomV);
    string dataAvui = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);     
    PassarelaCompra c = PassarelaCompra(u.obteSobrenom(), nomV, dataAvui, ec.obtePreu());
    c.insereix();
    result.push_back(dataAvui);

    vector<PassarelaConte> paquetsC = contiene.cercaVideojoc(nomV);
    for (int i = 0; i < paquetsC.size(); i++)
    {
        vector<string> videojocsC = contiene.cercaPaquet(paquetsC[i].obtePaquet());
        for(int j = 0; j < videojocsC.size(); j++){
            ec = compraelem1.cercaElement(videojocsC[j]);
            result.push_back(ec.obteNom() + "; " + ec.obteDescripcio() + "; " + to_string(ec.obtePreu()));
        }
    }
}

vector<string> TxCompraVideojoc::obteResult(){
    return result;
}