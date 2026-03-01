#include "PassarelaPaquet.h"


PassarelaPaquet::PassarelaPaquet(pqxx::row row)
{
	nom = row[0].c_str();
}
PassarelaPaquet::PassarelaPaquet(){}
PassarelaPaquet::PassarelaPaquet(string nomP)
{
	nom = nomP;
}

string PassarelaPaquet::obtePaquetNom()
{
	return nom;
}
