#include <iostream>
#include"HistoricoJugador.h"
#include"archivos.h"
#include"Jugador.h"
#include "Equipo.h"
#include "ArchivoEquipo.h"
#include "Grupo.h"
#include "Partido.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    Equipo e1("Sweden","Swedish Football Association","UEFA","random boi",2,'B');
    e1.print();
    for(int n=0;n<26;n++){
        e1.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
        e1.printJugador(n);
        actualizarArchivo(e1.getJugador(n).gethistorico(),n,e1.getPais());
    }
    Equipo e3("Argentina","Swedish Football Association","UEFA","random boi",2,'B');
    e3.print();
    for(int n=0;n<26;n++){
        e3.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
        e3.printJugador(n);
        actualizarArchivo(e3.getJugador(n).gethistorico(),n,e3.getPais());
    }
    Equipo e4("Colombia","Swedish Football Association","UEFA","random boi",2,'B');
    e4.print();
    for(int n=0;n<26;n++){
        e4.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
        e4.printJugador(n);
        actualizarArchivo(e4.getJugador(n).gethistorico(),n,e4.getPais());
    }
    Equipo e5("USA","Swedish Football Association","UEFA","random boi",2,'B');
    e5.print();
    for(int n=0;n<26;n++){
        e5.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
        e5.printJugador(n);
        actualizarArchivo(e5.getJugador(n).gethistorico(),n,e5.getPais());
    }
    Equipo e6("Morocco","Swedish Football Association","UEFA","random boi",2,'B');
    e6.print();
    for(int n=0;n<26;n++){
        e6.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
        e6.printJugador(n);
        actualizarArchivo(e6.getJugador(n).gethistorico(),n,e6.getPais());
    }
    Equipo e7("Croatia","Swedish Football Association","UEFA","random boi",2,'B');
    e7.print();
    for(int n=0;n<26;n++){
        e7.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
        e7.printJugador(n);
        actualizarArchivo(e7.getJugador(n).gethistorico(),n,e7.getPais());
    }
    Equipo e8("Peru","Swedish Football Association","UEFA","random boi",2,'B');
    e8.print();
    for(int n=0;n<26;n++){
        e8.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
        e8.printJugador(n);
        actualizarArchivo(e8.getJugador(n).gethistorico(),n,e8.getPais());
    }

    Equipo e9("Holanda","Swedish Football Association","UEFA","random boi",2,'B');
    e9.print();
    for(int n=0;n<26;n++){
        e9.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
        e9.printJugador(n);
        actualizarArchivo(e9.getJugador(n).gethistorico(),n,e9.getPais());
    }
    Equipo e10("Germany","Swedish Football Association","UEFA","random boi",2,'B');
    e10.print();
    for(int n=0;n<26;n++){
        e10.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
        e10.printJugador(n);
        actualizarArchivo(e10.getJugador(n).gethistorico(),n,e10.getPais());
    }
    Equipo e11("Uruguay","Swedish Football Association","UEFA","random boi",2,'B');
    e11.print();
    for(int n=0;n<26;n++){
        e11.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
        e11.printJugador(n);
        actualizarArchivo(e11.getJugador(n).gethistorico(),n,e11.getPais());
    }
    Equipo e2;
    cargarEquipoDesdeArchivo(e2, "selecciones_clasificadas_mundial.csv", "France");

    e2.print();

    e2.actualizarHistoricoEquipo(2, 1, 1, 0, 4);

    actualizarHistoricoEquipoArchivo(e2, "Historico_equipos.csv");

    e2.print();

    // Equipo e10;
    // cargarEquipoDesdeArchivo(e3, "selecciones_clasificadas_mundial.csv", "Spain");
    // e3.print();
    // for(int n=0;n<10;n++){
    //     e3.setHistoricoJugador(n,n+1,n*2,n+2,n*2,n+3);
    //     e3.printJugador(n);
    //     actualizarArchivo(e3.getJugador(n).gethistorico(),n,e3.getPais());
    // }

    cout << "\n=========== PRUEBA GRUPO ===========\n";

    Grupo grupoA('A');

    if(grupoA.agregarEquipo(e2)){
        cout << "\nSe agrego " << e2.getPais() << " al grupo." << endl;
    }
    else{
        cout << "\nNo se pudo agregar " << e2.getPais() << " al grupo." << endl;
    }

    Equipo ePrueba("Colombia","FCF","CONMEBOL","Lorenzo",12,'B');

    if(grupoA.agregarEquipo(ePrueba)){
        cout << "\nSe agrego " << ePrueba.getPais() << " al grupo." << endl;
    }
    else{
        cout << "\nNo se pudo agregar " << ePrueba.getPais() << " al grupo." << endl;
    }

    grupoA.print();

    cout << "\n=========== PRUEBA PARTIDO ===========\n";

    Partido p1(e2, ePrueba, "20/06/2026", "Sede 1",
               "Arbitro 1", "Arbitro 2", "Arbitro 3");

    cout << "\nAntes del partido:" << endl;
    e2.print();
    ePrueba.print();

    p1.simularPartido();

    p1.print();

    cout << "\nDespues del partido:" << endl;
    e2.print();
    ePrueba.print();

    actualizarHistoricoEquipoArchivo(e2, "Historico_equipos.csv");
    actualizarHistoricoEquipoArchivo(ePrueba, "Historico_equipos.csv");
    return 0;

}


