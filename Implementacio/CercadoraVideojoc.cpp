#include "CercadoraVideojoc.h"

PassarelaVideojoc CercadoraVideojoc::cercaVideojoc(string nomV)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM videojoc WHERE nom='" + nomV + "'");
	txn.commit();
	if (result.size() == 0) throw(VideojocNoExisteix);
	PassarelaVideojoc l1 = PassarelaVideojoc(result[0]);
	return l1;
}
CercadoraVideojoc::CercadoraVideojoc(){}

vector<PassarelaVideojoc> CercadoraVideojoc::cercaVideojocs()
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM videojoc ORDER BY data_llansament DESC");
	txn.commit();
	vector<PassarelaVideojoc> videjocsL;
	for (int i = 0; i < result.size(); i++)
	{
		videjocsL.push_back(PassarelaVideojoc(result[i]));
	}
	return videjocsL;
}

vector<PassarelaVideojoc> CercadoraVideojoc::cercaVideojocsEdat(int edatM)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM videojoc WHERE qualificacio_edat <= '"+ to_string(edatM) + "' ORDER BY qualificacio_edat DESC, data_llansament DESC");
	txn.commit();
	vector<PassarelaVideojoc> videjocsL;
	for (int i = 0; i < result.size(); i++)
	{
		videjocsL.push_back(PassarelaVideojoc(result[i]));
	}
	return videjocsL;
}

vector<PassarelaVideojoc> CercadoraVideojoc::cercaNovetats(string dataM)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM videojoc WHERE data_llansament >= '"+ dataM + "' ORDER BY data_llansament DESC");
	txn.commit();
	vector<PassarelaVideojoc> videjocsL;
	for (int i = 0; i < result.size(); i++)
	{
		videjocsL.push_back(PassarelaVideojoc(result[i]));
	}
	return videjocsL;
}