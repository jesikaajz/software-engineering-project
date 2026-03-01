#include "CercadoraCompres.h"

vector<PassarelaCompra> CercadoraCompres::cercaCompra(string sobrenomU)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM compra WHERE usuari='" + sobrenomU + "' ORDER BY data DESC");
	vector<PassarelaCompra> compresU;
	for (int i = 0; i < result.size(); i++)
	{
		compresU.push_back(PassarelaCompra(result[i]));
	}
	return compresU;
}
PassarelaCompra CercadoraCompres::cercaCompra_element(string elementC,string sobrenomC)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM compra WHERE element='" + elementC + "' AND usuari='" + sobrenomC +"'");
	return PassarelaCompra(result[0]);
}
CercadoraCompres:: CercadoraCompres() {}