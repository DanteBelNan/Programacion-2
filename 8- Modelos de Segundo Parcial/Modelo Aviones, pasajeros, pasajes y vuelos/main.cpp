#include <iostream>
#include <cstring>
using namespace std;
#include <string>
#include "parcial2.h"


int Apunto1(Pasajero reg){
    FILE *p = fopen("punto1.dat", "ab");

      if (p == NULL)
      {
        return -1;
      }

      int resultado = fwrite(&reg, sizeof(Pasajero), 1, p);
      fclose(p);
      return resultado;
}

void punto1(){
    ArchivoPasajeros AP;
    ArchivoPasajes APjes;

    int tamAP = AP.contarRegistros();
    int tamAPjes = APjes.contarRegistros();

    for(int i = 0;i<tamAP;i++){
        Pasajero pasajero;
        pasajero = AP.leerRegistro(i);
        bool compro2023 = false;
        for(int i2 = 0;i2<tamAPjes;i2++){
            Pasaje pasaje;
            pasaje = APjes.leerRegistro(i2);

            if(pasajero.getNumeroPasajero() == pasaje.getNumeroPasajero()){
                if(pasaje.getFechaCompra().getAnio() == 2023){
                    compro2023 = true;
                }
            }
        }

        if(!compro2023){
            Apunto1(pasajero);
        }


    }
}

int modificarAvion(Avion reg, int pos){
  FILE *p = fopen("aviones.dat", "rb+");

  if (p == NULL)
  {
    return -1;
  }

  fseek(p, pos * sizeof(Avion), SEEK_SET);
  int resultado = fwrite(&reg, sizeof(Avion), 1, p);
  fclose(p);
  return resultado;
}

void punto2(){
    ArchivoAvion AV;
    int tamAV = AV.contarRegistros();
    char marca[30] = "Boeing";

    for(int i = 0;i<tamAV;i++){
        Avion avion;
        avion = AV.leerRegistro(i);
        if(!strcmp(marca,avion.getMarca())){
            int seats = avion.getCantidadAsientos();
            seats *= 0.95;
            avion.setCantidadAsientos(seats);
            modificarAvion(avion,i);
        }
    }

}

void copiarAvion(Avion a1, Avion a2){
    a1.setActivo(a2.getActivo());
    a1.setCantidadAsientos(a2.getCantidadAsientos());
    a1.setCodigoAvion(a2.getCodigoAvion());
    a1.setMarca(a2.getMarca());
    a1.setNombre(a2.getNombre());
    a1.setTipo(a2.getTipo());
}

void punto3(){
    ArchivoAvion AC;
    int tamAC = AC.contarRegistros();

    int tam = 0;
    for(int i = 0;i<tamAC;i++){
        Avion avion;
        avion = AC.leerRegistro(i);
        if(avion.getTipo()==1){
            tam++;
        }
    }


    Avion* avionPropio = new Avion[tam];
    int assigned = 0;
    for(int i = 0;i<tamAC;i++){
        Avion avion;
        avion = AC.leerRegistro(i);
        if(avion.getTipo()==1){
            avion.Mostrar();
            copiarAvion(avionPropio[assigned], avion);
            assigned++;
        }
    }

    for(int i = 0;i<tam;i++){
        //avionPropio[i].Mostrar();
    }


}

int main()
{
    punto3();
    return 0;
}
