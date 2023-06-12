#include <iostream>
#include <cstring>
using namespace std;
#include "parcial2.h"

class CpuntoA{
    private:
        int numeroCosecha;
        char codigoEmpresa[6];
        int codigoCereal;
        float tonCosechadas;
        Fecha fecha;


    public:
        void cargar(Cosecha cos){
            this->numeroCosecha = cos.getNumeroCosecha();
            strcpy(this->codigoEmpresa, cos.getCodigoEmpresa());
            this->codigoCereal = cos.getCodigoCereal();
            this->tonCosechadas = cos.getToneladasCosechadas();
            this->fecha = cos.getFecha();
        }

        void operator =(Cosecha cos){
            this->numeroCosecha = cos.getNumeroCosecha();
            strcpy(this->codigoEmpresa, cos.getCodigoEmpresa());
            this->codigoCereal = cos.getCodigoCereal();
            this->tonCosechadas = cos.getToneladasCosechadas();
            this->fecha = cos.getFecha();
        }
};

class FpuntoA{
    private:
    FILE *p;
    public:
        int modificarRegistro(CpuntoA reg, int pos){
          p = fopen("puntoA.dat", "rb+");
          if (p == NULL){
            return -1;
          }
          fseek(p, pos * sizeof(CpuntoA), SEEK_SET);
          int resultado = fwrite(&reg, sizeof(CpuntoA), 1, p);
          fclose(p);
          return resultado;
        }

        int guardarRegistro(CpuntoA reg){
          p = fopen("puntoA.dat", "ab");

          if (p == NULL){
            return -1;
          }
          int resultado = fwrite(&reg, sizeof(CpuntoA), 1, p);
          fclose(p);
          return resultado;
        }

        CpuntoA leerRegistro(int pos){
            CpuntoA reg;
            FILE *p;
            p=fopen("puntoA.dat", "rb");
            if(p==NULL) return reg;
            fseek(p, sizeof(CpuntoA)*pos,0);
            fread(&reg, sizeof reg,1, p);
            fclose(p);
            return reg;
        }


};

void puntoA(){
    ArchivoCosecha AC;
    FpuntoA FA;
    int tamC = AC.contarRegistros();

    for(int i = 0;i<tamC;i++){
        Cosecha cos;
        cos = AC.leerRegistro(i);
        CpuntoA obj;
        obj.cargar(cos);
        FA.guardarRegistro(obj);
    }


}

void puntoB(){
    ArchivoCosecha AC;
    int tamC = AC.contarRegistros();

    float cantCosexMes [12] {};

    for(int i = 0;i<tamC;i++){
        Cosecha cos;
        cos = AC.leerRegistro(i);
        int mes = cos.getFecha().getMes()-1;
        cantCosexMes[mes]+= cos.getToneladasCosechadas();
    }

    int numMax = 0;
    for(int i = 1; i < 12; i++){
        if(cantCosexMes[i] > cantCosexMes[numMax]){
            numMax = i;
        }
    }

    cout<<"el mes con mas toneladas cosechadas es el N "<<numMax+1;
}

void puntoC(){
    ArchivoCosecha AC;
    FpuntoA FA;
    int tamC = AC.contarRegistros();
    Cosecha* vCos = new Cosecha[tamC];

    for(int i = 0;i<tamC;i++){
        vCos[i] = AC.leerRegistro(i);
    }
    for(int i = 0;i<tamC;i++){
        CpuntoA obj;
        obj.cargar(vCos[i]);
        FA.guardarRegistro(obj);
    }


}

int modificarCosecha(Cosecha reg, int pos)
{
  FILE *p = fopen("cosecha.dat", "rb+");

  if (p == NULL)
  {
    return -1;
  }

  fseek(p, pos * sizeof(Cosecha), SEEK_SET);
  int resultado = fwrite(&reg, sizeof(Cosecha), 1, p);
  fclose(p);
  return resultado;
}

void puntoD(){
    ArchivoCosecha AC;
    FpuntoA FA;
    int tamC = AC.contarRegistros();
    Cosecha* vCos = new Cosecha[tamC];

    for(int i = 0;i<tamC;i++){
        vCos[i] = AC.leerRegistro(i);
    }
    for(int i = 0;i<tamC;i++){
        float kgCosechados = vCos[i].getToneladasCosechadas() * 1000;
        vCos[i].setToneladasCosechadas(kgCosechados);
        modificarCosecha(vCos[i],i);
    }

}

int main()
{

    return 0;
}
