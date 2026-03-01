#include "PassarelaUsuari.h"

PassarelaUsuari::PassarelaUsuari(string nomP, string sobrenomP, string contrasenyaP, string correuElectronicP, string dataNaixamentP)
{
    nom = nomP;
    sobrenom = sobrenomP;
    contrasenya = contrasenyaP;
    correuElectronic = correuElectronicP;
    dataNaixament = dataNaixamentP;
}

PassarelaUsuari::PassarelaUsuari(pqxx::row row)
{
  sobrenom = row[0].c_str();
  nom = row[1].c_str();
  contrasenya = row[2].c_str();
  correuElectronic = row[3].c_str();
  dataNaixament = row[4].c_str();
}

PassarelaUsuari::PassarelaUsuari(){}

string PassarelaUsuari::obteNom(){
    return nom;
}

string PassarelaUsuari::obteSobrenom(){
    return sobrenom;
}

string PassarelaUsuari::obteContrasenya()
{
    return contrasenya;
}

string PassarelaUsuari::obteCorreuElectronic(){
    return correuElectronic;
}

string PassarelaUsuari::obteDataNaixement(){
    return dataNaixament;
}

void PassarelaUsuari::posaNom(string nomU)
{
    nom = nomU;
}
void PassarelaUsuari::posaContrasenya(string contraU)
{
    contrasenya = contraU;
}
void PassarelaUsuari::posaCorreuElectronic(string correU)
{
    correuElectronic = correU;
}
void PassarelaUsuari::posaDataNaixament(string neixU)
{
    dataNaixament = neixU;
}

void PassarelaUsuari::insereix()
{
	pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT * FROM usuari WHERE sobrenom='" + sobrenom + "'");
    if (result.size() != 0) throw(SobrenomExisteix);
    result= txn.exec("SELECT * FROM usuari WHERE correu_electronic='" + correuElectronic + "'");
    if (result.size() != 0) throw(CorreuExisteix);
    result = txn.exec("INSERT INTO usuari (sobrenom, nom, contrasenya, correu_electronic, data_naixament) VALUES('" + sobrenom + "', '" + nom + "', '" + contrasenya + "', '" + correuElectronic + "', '" + dataNaixament + "');");
	txn.commit();
}

void PassarelaUsuari::esborra()
{
    pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
	pqxx::work txn(conn);
    pqxx::result result = txn.exec("DELETE FROM usuari WHERE sobrenom = '" + sobrenom +"';");
	txn.commit();
}

void PassarelaUsuari::modifica()
{
    pqxx::connection conn(Contenedor_linea::linea);
	if(!conn.is_open())
		throw(string("Error al obrir Base de dades"));
    pqxx::work txn(conn); 
    pqxx::result result = txn.exec("SELECT * FROM usuari WHERE correu_electronic='" + correuElectronic + "'");
    if (result.size() != 0)  if (PassarelaUsuari(result[0]).obteSobrenom() != sobrenom) throw(CorreuExisteix);
    result = txn.exec("UPDATE usuari set nom = '" + nom + "'"",contrasenya = '" + contrasenya + "'"",correu_electronic = '" + correuElectronic + "'"",data_naixament = '" + dataNaixament + "'""WHERE sobrenom ='" + sobrenom +"';");
    txn.commit();
}
