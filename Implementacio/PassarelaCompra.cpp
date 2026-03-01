#include "PassarelaCompra.h"

PassarelaCompra::PassarelaCompra(string usuariP, string elementP, string dataP, float PreuPagatP)
{
    usuari = usuariP;
    element = elementP;
    data = dataP;
    PreuPagat = PreuPagatP;
}

PassarelaCompra::PassarelaCompra(pqxx::row row)
{
      usuari = row[0].c_str();
      element = row[1].c_str();
      data = row[2].c_str();
      PreuPagat = row[3].as<float>();
}

PassarelaCompra::PassarelaCompra(){}

void PassarelaCompra::insereix()
{
    
    pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
    pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT * FROM compra WHERE element='" + element + "' AND usuari='" + usuari +"';");
    if (result.size() != 0) throw(ErrorObtingut);
    result = txn.exec("INSERT INTO compra (usuari, element, data, preu_pagat) VALUES('" + usuari + "', '" + element + "', '" + data + "', '" + to_string(PreuPagat) + "');");
	txn.commit();
}

float PassarelaCompra::obtePreuPagat(){
    return PreuPagat;
}

string PassarelaCompra::obteElementCompra(){
    return element;
}

string PassarelaCompra::obteData()
{
    return data;
}
