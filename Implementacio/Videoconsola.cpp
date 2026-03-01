#include "Videoconsola.h"

void Videoconsola::iniciaSessio(PassarelaUsuari usuariS)
{
    usuari = usuariS;
}

void Videoconsola::tancaSessio(){
    usuari = PassarelaUsuari("", "", "", "", "");
}

PassarelaUsuari Videoconsola::obteUsuari(){
    return usuari;
}

void Videoconsola::refrescarUsuari(string sU)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
    pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT * FROM usuari WHERE sobrenom='" + sU + "'");
    PassarelaUsuari l1 = PassarelaUsuari(result[0]);
    usuari = l1;
    txn.commit();
}