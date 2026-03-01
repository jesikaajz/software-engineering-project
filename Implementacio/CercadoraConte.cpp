#include "CercadoraConte.h"

vector<PassarelaConte> CercadoraConte::cercaVideojoc(string nomV)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM conte WHERE videojoc='" + nomV + "'");
	vector<PassarelaConte> l1;
	for (int i = 0; i < result.size(); i++)
	{
		l1.push_back(PassarelaConte(result[i]));
	}
	return l1;
}
CercadoraConte::CercadoraConte() {}

vector<string> CercadoraConte::cercaPaquet(string nomP)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM conte WHERE paquet='" + nomP + "'");
	vector<string> l1;
	for (int i = 0; i < result.size(); i++)
	{
		l1.push_back(PassarelaConte(result[i]).obteVideojoc());
	}
	return l1;
}

