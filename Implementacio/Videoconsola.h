#pragma once
#include <string>
#include <iostream>
#include "PassarelaUsuari.h"
using namespace std;

class Videoconsola
{
public:
    void iniciaSessio(PassarelaUsuari usuariS);
    void tancaSessio();
    void refrescarUsuari(string sU);
    PassarelaUsuari obteUsuari();
    static Videoconsola& getInstance() {
        static Videoconsola instance;
        return instance;
    }
private:
    PassarelaUsuari usuari;
    Videoconsola() {}
};
