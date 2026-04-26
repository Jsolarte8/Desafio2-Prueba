#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "Equipo.h"
using namespace std;

class Partido{
private:
    Equipo *equipo1;
    Equipo *equipo2;
    string fecha;
    string sede;
    string arbitro1;
    string arbitro2;
    string arbitro3;

    unsigned short int golesEquipo1;
    unsigned short int golesEquipo2;
    bool jugado;

public:
    Partido();
    Partido(Equipo &e1, Equipo &e2, string f, string s,
            string a1, string a2, string a3);
    Partido(const Partido &copiaPartido);

    Equipo* getEquipo1() const;
    Equipo* getEquipo2() const;
    string getFecha() const;
    string getSede() const;
    unsigned short int getGolesEquipo1() const;
    unsigned short int getGolesEquipo2() const;
    bool getJugado() const;

    void setFecha(string f);
    void setSede(string s);
    void setArbitros(string a1, string a2, string a3);

    void simularPartido();
    void print() const;

    ~Partido();
};

#endif // PARTIDO_H