#include <iostream>
#include "functions.h"
#include "Tarjetas.h"
#include "Viajes.h"

using namespace std;

int main()
{
    Tarjetas tarj;

    int idBuscar;
    cout<<"Ingrese el id de la tarjeta a buscar: ";
    cin>>idBuscar;

    if(tarj.buscarID(idBuscar)>0){
        tarj.cargarRegistro(idBuscar);
        tarj.mostrar();
    }else{
        cout<<"Id inexistente..."<<endl;
    }
    return 0;
}
