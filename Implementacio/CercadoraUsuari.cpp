#include "CercadoraUsuari.h"

PassarelaUsuari CercadoraUsuari::cercaUsuari(string sobrenomU)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM usuari WHERE sobrenom='" + sobrenomU + "'");
	txn.commit();
	if (result.size() == 0) throw(UsuariNoExisteix);
	PassarelaUsuari l1 = PassarelaUsuari(result[0]);
	return l1;
}
CercadoraUsuari::CercadoraUsuari(){}