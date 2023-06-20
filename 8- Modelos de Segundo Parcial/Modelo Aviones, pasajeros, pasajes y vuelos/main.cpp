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

class Cpunto3{
    private:
        int codigoAvion;
        char nombre[30];
        char marca[30];

    public:
        void cargar(Avion av){
            this->codigoAvion = av.getCodigoAvion();
            strcpy(this->nombre,av.getNombre());
            strcpy(this->marca,av.getMarca());
        }

        void mostrar(){
            cout<<this->codigoAvion<<endl;
            cout<<this->nombre<<endl;
            cout<<this->marca<<endl;
        }



        void operator =(Avion av){
            this->codigoAvion = av.getCodigoAvion();
            strcpy(this->nombre,av.getNombre());
            strcpy(this->marca,av.getMarca());
        }

};

void punto3(){
    ArchivoAvion AC;
    int tamAC = AC.contarRegistros();

    int tam = 0;
    for(int i = 0;i<tamAC;i++){
        Avion av;
        av = AC.leerRegistro(i);
        if(av.getTipo() == 1){
            tam++;

        }
    }

    Cpunto3* vObj = new Cpunto3[tam];
    int asgn = 0;
    for(int i = 0;i<tamAC;i++){
        Avion av;
        av = AC.leerRegistro(i);
        if(av.getTipo() == 1){
            //vObj[asgn].cargar(av);
            vObj[asgn] = av; //segun el punto 4
            vObj[asgn].mostrar();
            asgn++; //si comento esta linea pasan cosas locas
            cout<<"--------------------"<<endl;
        }
    }

    for(int i = 0;i<tam;i++){
        vObj[i].mostrar();
        cout<<"---------------------"<<endl;
    }

    delete[] vObj;

}


bool escribirRegistroP5(Pasajero reg){
    FILE *p;
    p=fopen("punto5.dat", "ab");
    if(p==NULL) return false;
    bool escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

void punto5(){
    int year = 2022;
    ArchivoPasajeros AP;
    ArchivoPasajes APs;
    int tamAP = AP.contarRegistros();
    int tamAPs = APs.contarRegistros();

    for(int i = 0;i<tamAP;i++){
        Pasajero pasajero;
        bool compro2023 = false;
        pasajero = AP.leerRegistro(i);
        for(int i2 = 0;i2<tamAPs;i2++){
            Pasaje pasaje;
            pasaje = APs.leerRegistro(i2);
            if(pasaje.getNumeroPasajero() == pasajero.getNumeroPasajero()){
                if(pasaje.getFechaCompra().getAnio() == year){
                    compro2023 = true;
                }
            }
        }
        if(compro2023){
            escribirRegistroP5(pasajero);
        }
    }

}

class Cpunto6{
    private:
        int codigoAvion;
        char nombre[30];
        int cantVuelos;

    public:
        Cpunto6(Avion av){
            cantVuelos = 0;
            this->codigoAvion = av.getCodigoAvion();
            strcpy(this->nombre,av.getNombre());
        }

        checkVuelo(Vuelo vu){
            if(this->codigoAvion == 1){
                cantVuelos++; //a la clase Vuelo le falta el miembro codigo avion, y sus setters+getters

            }
        }
};

class Apunto6{
    private:

    public:
        int guardarRegistro(Cpunto6 reg){
            FILE *p = fopen("punto6.dat", "ab");

            if (p == NULL)
            {
            return -1;
            }

            int resultado = fwrite(&reg, sizeof(Cpunto6), 1, p);
            fclose(p);
            return resultado;
        }
};

void punto6(){
    ArchivoAvion AA;
    ArchivoVuelo AV;
    Apunto6 AP6;

    int tamAA = AA.contarRegistros();
    int tamAV = AV.contarRegistros();

    for(int i = 0;i<tamAA;i++){
        Avion avion;
        avion = AA.leerRegistro(i);
        Cpunto6 obj(avion);
        for(int i2 = 0;i2<tamAV;i2++){
            Vuelo vuelo;
            vuelo = AV.leerRegistro(i2);

            obj.checkVuelo(vuelo);
        }
        AP6.guardarRegistro(obj);
    }
}

int main()
{
    punto6();
    return 0;
}
