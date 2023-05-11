#include <iostream>
#include <cstring>
using namespace std;

#include "parcialm1.h"

class punto1{

    private:
        int codigoMaterial;
        char nombre[30];
        char marca[30];

    public:
        punto1(){}

        void cargar(Material material){
            codigoMaterial = material.getCodigoMaterial();
            strcpy(nombre,material.getNombre());
            strcpy(marca,material.getMarca());
        }
        int guardarRegistro(){
            FILE *p;
            p = fopen("punto1.dat", "ab");

            if(p==NULL){
                return -1;
            }
            int resultado = fwrite(this, sizeof(*this),1,p);
            fclose(p);
            return resultado;

        }

};

void Punto1(){
    ArchivoMaterial obj("materiales.dat");
    int tam = obj.contarRegistros();

    for(int i = 0;i<tam;i++){
        Material material;
        material = obj.leerRegistro(i);
        int tipo = material.getTipo();
        bool activo = material.getActivo();
        if(tipo == 6 && activo){
            punto1 p1;
            p1.cargar(material);
            p1.guardarRegistro();
        }
    }
}

void Punto2(){
    int cantEjecu[5] = {};
    ArchivoObras obj("obras.dat");
    int tam = obj.contarRegistros();

    for(int i = 0;i<tam;i++){
        Obra obra;
        obra = obj.leerRegistro(i);
        int esEj = obra.getEstadoEjecucion() -1;
        cantEjecu[esEj]++;
    }
    int numMax = 0;
    for(int i = 1; i < 5; i++){
        if(cantEjecu[i] > cantEjecu[numMax]){
            numMax = i;
        }
    }
    cout<<" EL ESTADO DE EJECUCIÓN DE OBRAS CON MAS OBRAS ES EL N°"<<numMax+1<<" CON "<<cantEjecu[numMax]<<" OBRAS"<<endl;
}

int main()
{
    punto1();
    punto2();
    return 0;
}
