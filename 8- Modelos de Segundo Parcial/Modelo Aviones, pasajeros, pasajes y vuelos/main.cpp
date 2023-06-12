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
int main()
{
    punto3();
    return 0;
}
