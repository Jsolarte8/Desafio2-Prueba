#include "Partido.h"

Partido::Partido()
{
    equipo1=NULL;
    equipo2=NULL;
    fecha="";
    sede="";
    arbitro1="";
    arbitro2="";
    arbitro3="";
    golesEquipo1=0;
    golesEquipo2=0;
    jugado=false;
}

Partido::Partido(Equipo &e1, Equipo &e2, string f, string s,
                 string a1, string a2, string a3)
{
    equipo1=&e1;
    equipo2=&e2;
    fecha=f;
    sede=s;
    arbitro1=a1;
    arbitro2=a2;
    arbitro3=a3;
    golesEquipo1=0;
    golesEquipo2=0;
    jugado=false;
}

Partido::Partido(const Partido &copiaPartido)
{
    equipo1=copiaPartido.equipo1;
    equipo2=copiaPartido.equipo2;
    fecha=copiaPartido.fecha;
    sede=copiaPartido.sede;
    arbitro1=copiaPartido.arbitro1;
    arbitro2=copiaPartido.arbitro2;
    arbitro3=copiaPartido.arbitro3;
    golesEquipo1=copiaPartido.golesEquipo1;
    golesEquipo2=copiaPartido.golesEquipo2;
    jugado=copiaPartido.jugado;
}

Equipo* Partido::getEquipo1() const
{
    return equipo1;
}

Equipo* Partido::getEquipo2() const
{
    return equipo2;
}

string Partido::getFecha() const
{
    return fecha;
}

string Partido::getSede() const
{
    return sede;
}

unsigned short int Partido::getGolesEquipo1() const
{
    return golesEquipo1;
}

unsigned short int Partido::getGolesEquipo2() const
{
    return golesEquipo2;
}

bool Partido::getJugado() const
{
    return jugado;
}

void Partido::setFecha(string f)
{
    fecha=f;
}

void Partido::setSede(string s)
{
    sede=s;
}

void Partido::setArbitros(string a1, string a2, string a3)
{
    arbitro1=a1;
    arbitro2=a2;
    arbitro3=a3;
}

void Partido::simularPartido()
{
    if(equipo1==NULL || equipo2==NULL){
        cout<<"\n No se puede simular el partido porque falta un equipo."<<endl;
        return;
    }

    if(jugado){
        cout<<"\n Este partido ya fue simulado."<<endl;
        return;
    }

    golesEquipo1 = rand() % 5;
    golesEquipo2 = rand() % 5;

    equipo1->actualizarHistoricoEquipo(golesEquipo1, golesEquipo2, 0, 0, 0);
    equipo2->actualizarHistoricoEquipo(golesEquipo2, golesEquipo1, 0, 0, 0);

    jugado=true;
}

void Partido::print() const
{
    cout<<"\n Partido:{";
    cout<<"\n Fecha: "<<fecha;
    cout<<"\n Sede: "<<sede;
    cout<<"\n Arbitros: "<<arbitro1<<", "<<arbitro2<<", "<<arbitro3;

    if(equipo1!=NULL && equipo2!=NULL){
        cout<<"\n Equipo 1: "<<equipo1->getPais();
        cout<<"\n Equipo 2: "<<equipo2->getPais();
    }

    if(jugado){
        cout<<"\n Resultado: "<<golesEquipo1<<" - "<<golesEquipo2;
    }
    else{
        cout<<"\n Resultado: partido no jugado";
    }

    cout<<"\n }"<<endl;
}

Partido::~Partido()
{
}