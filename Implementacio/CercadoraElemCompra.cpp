#include "CercadoraElemCompra.h"


PassarelaElemCompra CercadoraElemCompra::cercaElement(string elem)
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM element_compra WHERE nom='" + elem + "'");
	txn.commit();
	PassarelaElemCompra l1 = PassarelaElemCompra(result[0]);
	return l1; 
}

CercadoraElemCompra::CercadoraElemCompra(){
}


