#include "CercadoraPaquet.h"


CercadoraPaquet::CercadoraPaquet(){}

vector<string>  CercadoraPaquet::cercaPaquets()
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM paquet_videojoc");
	txn.commit();
	vector<string> llista_paquets;
	for (int i = 0; i < result.size(); i++)
	{
		llista_paquets.push_back(PassarelaPaquet(result[i]).obtePaquetNom());
	}
	return llista_paquets;
}

PassarelaPaquet CercadoraPaquet::cercaPaquet(string nomP)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw("Error al obrir Base de dades");	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM paquet_videojoc WHERE nom='" + nomP + "'");
	txn.commit();
	if (result.size() == 0) throw(PaquetNoExisteix);
	PassarelaPaquet l1 = PassarelaPaquet(result[0]);
	return l1;
}
