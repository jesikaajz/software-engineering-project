#include "TxConsultaPaquet.h"

TxConsultaPaquet::TxConsultaPaquet(){}

void TxConsultaPaquet::executar(string nomP){
    PassarelaPaquet p = p1.cercaPaquet(nomP);
    PassarelaElemCompra ec = compraelem1.cercaElement(nomP);
    
    resultat.push_back(p.obtePaquetNom());
    resultat.push_back(ec.obteDescripcio());
    resultat.push_back(to_string(ec.obtePreu()));
    llista_videojocs = contiene.cercaPaquet(nomP);   

    pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
    pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT paquet_videojoc.nom AS nom_paquet, sum(element_compra.preu) AS preu_jocs FROM conte, paquet_videojoc, element_compra WHERE conte.paquet = paquet_videojoc.nom AND conte.videojoc = element_compra.nom GROUP BY paquet_videojoc.nom; ");
    txn.commit();
    pqxx::row row = result[0];
    preuJocs = row[1].as<float>();
}

vector<string>  TxConsultaPaquet::obteResultat(){
    return resultat;
}

vector<string>  TxConsultaPaquet::obteLlistavideojocs() {
    return llista_videojocs;
}


void TxConsultaPaquet::infoEC(string nomV)
{
    PassarelaElemCompra ec = compraelem1.cercaElement(nomV);
    info[0] = ec.obteDescripcio();
    info[1] = (to_string(ec.obtePreu()));

}

vector<string> TxConsultaPaquet::obteInfoEC()
{
    return info;
}
float TxConsultaPaquet::obtepreuJocs()
{
    return preuJocs;
}