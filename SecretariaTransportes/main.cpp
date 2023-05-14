#include <iostream>
#include <cstring>
using namespace std;
#include "Fecha.h"
#include "functions.h"
#include "Tarjetas.h"
#include "Viajes.h"
#include "ArchivoTarjetas.h"
#include "ArchivoViajes.h"

void punto1()
{
    ArchivoTarjetas AT;
    ArchivoViajes AV;
    int numTarj;
    cout<<"INGRESE EL NUMERO DE TARJETA A BUSCAR SU CANT DE VIAJES: ";
    cin>>numTarj;
    int existe = AT.buscarNumero(numTarj);
    if(existe){
        int medioTransporte[3] {};
        for(int i = 0;i<AV.contarRegistros();i++){
            Viajes viaje;
            viaje = AV.leerRegistro(i);
            if(viaje.getNumTarjeta() == numTarj){
                int transporte = viaje.getMedioTransporte() - 1;
                medioTransporte[transporte]++;
            }
        }
        cout<<"COLECTIVO: "medioTransporte[0]<<endl;
        cout<<"SUBTE: "medioTransporte[1]<<endl;
        cout<<"TREN: "medioTransporte[2]<<endl;

    }
}

void punto2(){
    ArchivoViajes AV;
    int numMin = 0;
    Viajes minViaje;
    minViaje = AV.leerRegistro(0);
    for(int i = 1;i< AV.contarRegistros();i++){
        Viajes viaje;
        viaje = AV.leerRegistro(i);
        if(viaje.getImporte()< minViaje.getImporte()){
            minViaje = AV.leerRegistro(i);
            numMin = i;
        }
    }
    minViaje.mostrar();
}


int main()
{

    return 0;
}
