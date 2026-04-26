#include "ArchivoEquipo.h"
#include "Equipo.h"
#include "HistoricoEquipo.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string crearLineaHistoricoEquipo(const Equipo &equipo)
{
    HistoricoEquipo h = equipo.historico;

    string linea = "";

    linea += equipo.pais + ";";
    linea += to_string(h.getGolesFavor()) + ";";
    linea += to_string(h.getGolesContra()) + ";";
    linea += to_string(h.getPartidosGanados()) + ";";
    linea += to_string(h.getPartidosEmpatados()) + ";";
    linea += to_string(h.getPartidosPerdidos()) + ";";
    linea += to_string(h.getTarjetasAmarillas()) + ";";
    linea += to_string(h.getTarjetasRojas()) + ";";
    linea += to_string(h.getFaltas());

    return linea;
}

void actualizarHistoricoEquipoArchivo(const Equipo &equipo, const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    const int filasMax = 100;
    string lineas[filasMax];
    string linea;
    int totalLineas = 0;

    if(archivo.is_open()){
        while(getline(archivo, linea) && totalLineas < filasMax){
            lineas[totalLineas] = linea;
            totalLineas++;
        }
        archivo.close();
    }

    bool encontrado = false;

    for(int i = 1; i < totalLineas; i++){
        string paisLeido = "";
        unsigned int j = 0;

        while(j < lineas[i].size() && lineas[i][j] != ';'){
            paisLeido += lineas[i][j];
            j++;
        }

        if(paisLeido == equipo.pais){
            lineas[i] = crearLineaHistoricoEquipo(equipo);
            encontrado = true;
            break;
        }
    }

    if(!encontrado){
        if(totalLineas == 0){
            lineas[totalLineas] = "Pais;GolesFavor;GolesContra;PartidosGanados;PartidosEmpatados;PartidosPerdidos;TarjetasAmarillas;TarjetasRojas;Faltas";
            totalLineas++;
        }

        if(totalLineas < filasMax){
            lineas[totalLineas] = crearLineaHistoricoEquipo(equipo);
            totalLineas++;
        }
    }

    ofstream salida(nombreArchivo, ios::trunc);

    for(int i = 0; i < totalLineas; i++){
        salida << lineas[i] << endl;
    }

    salida.close();
}
void leerHistoricoEquipo(Equipo &equipo, const string &lineaCSV)
{
    string dato = "";
    string columnas[15];
    int j = 0;

    for(unsigned int i = 0; i < lineaCSV.size(); i++){
        if(lineaCSV[i] == ';'){
            columnas[j] = dato;
            j++;
            dato = "";
        }
        else{
            dato += lineaCSV[i];
        }
    }
    columnas[j] = dato;

    equipo.setPais(columnas[1]);
    equipo.setFederacion(columnas[3]);
    equipo.setConfederacion(columnas[4]);
    equipo.setDirectorTecnico(columnas[2]);
    equipo.setRankingFIFA((unsigned short int)stoi(columnas[0]));

    HistoricoEquipo h;
    h.setGolesFavor((unsigned short int)stoi(columnas[5]));
    h.setGolesContra((unsigned short int)stoi(columnas[6]));
    h.setPartidosGanados((unsigned short int)stoi(columnas[7]));
    h.setPartidosEmpatados((unsigned short int)stoi(columnas[8]));
    h.setPartidosPerdidos((unsigned short int)stoi(columnas[9]));

    equipo.setHistorico(h);
}
void cargarEquipoDesdeArchivo(Equipo &equipo, const string &nombreArchivo, const string &paisBuscado)
{
    ifstream archivo(nombreArchivo);
    string linea;

    if(!archivo.is_open()){
        cout << "\n No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    getline(archivo, linea);
    getline(archivo, linea);

    while(getline(archivo, linea)){
        string dato = "";
        string columnas[10];
        int j = 0;

        for(unsigned int i = 0; i < linea.size(); i++){
            if(linea[i] == ';'){
                columnas[j] = dato;
                j++;
                dato = "";
            }
            else{
                dato += linea[i];
            }
        }
        columnas[j] = dato;

        if(columnas[1] == paisBuscado){
            leerHistoricoEquipo(equipo, linea);
            archivo.close();
            return;
        }
    }

    cout << "\n No se encontro el equipo " << paisBuscado << endl;
    archivo.close();
}