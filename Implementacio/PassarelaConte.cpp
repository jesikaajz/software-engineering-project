#include "PassarelaConte.h"

PassarelaConte::PassarelaConte(string paquetC, string videojocC)
{
    paquet = paquetC;
    videojoc = videojocC;
}

PassarelaConte::PassarelaConte(pqxx::row row)
{
    paquet = row[0].c_str();
    videojoc = row[1].c_str();
}

PassarelaConte::PassarelaConte() {}


string PassarelaConte::obtePaquet()
{
    return paquet;
}
string PassarelaConte::obteVideojoc()
{
    return videojoc;
}
