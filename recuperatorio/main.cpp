#include <iostream>
#include <cstring>
using namespace std;

#include "clasesr.h"

class Cpunto1{
    private:
        int codigo;
        char descripcion[40];
        int cantAsignaciones;

    public:
        Cpunto1(){
            cantAsignaciones = 0;
        }

        Cpunto1(Asignacion asig){
            this->codigo = asig.getCodigoProyecto();
        }

        void cargar(Proyecto proy){
            this->codigo = proy.getCodigo();
            strcpy(this->descripcion, proy.getDescripcion());
        }

        void sumaAsignacion(){
            cantAsignaciones++;
        }

        int getCodigo(){return this->codigo;}
        int getcantAsig(){return this->cantAsignaciones;}
        bool operator != (int value){
            return (this->codigo != value);
        }
};

class Apunto1{
    private:

    public:
        int guardarRegistro(Cpunto1 reg){
            FILE *p = fopen("punto1.dat", "ab");

            if (p == NULL){
                return -1;
            }

            int resultado = fwrite(&reg, sizeof(Cpunto1), 1, p);
            fclose(p);
            return resultado;
        }

        Cpunto1 leerRegistro(int pos){
            Cpunto1 reg;
            FILE *p;
            p=fopen("punto1.dat", "rb");
            if(p==NULL) return reg;
            fseek(p, sizeof(Cpunto1)*pos,0);
            fread(&reg, sizeof reg,1, p);
            fclose(p);
            return reg;
        }

        int contarRegistros(){
            FILE *p;
            p=fopen("punto1.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Cpunto1);
        }
};

void punto1(){
    ArchivoProyecto AP("Proyectos.dat");
    ArchivoAsignacion AA("Asignaciones.dat");
    Apunto1 AP1;

    int tamAP = AP.contarRegistros();
    int tamAA = AA.contarRegistros();


    for(int i = 0;i<tamAP;i++){
        Proyecto proy;
        proy = AP.leerRegistro(i);
        if(proy.getEstado() == true){
            Cpunto1 obj;
            obj.cargar(proy);
            for(int i2 = 0;i2<tamAA;i2++){
                Asignacion asig;
                asig = AA.leerRegistro(i);
                if(asig.getEstado() == true){
                    if(asig.getCodigoProyecto() == obj.getCodigo()){
                        obj.sumaAsignacion();
                    }
                }
            }

            AP1.guardarRegistro(obj);

        }
    }


}

int modificarProyecto(Proyecto proy, int pos){
    FILE* p = fopen("Proyectos.dat", "rb+");
    if(p == NULL){
        return -1;
    }
    fseek(p, pos * sizeof(Proyecto), SEEK_SET);
    int resultado = fwrite(&proy, sizeof(Proyecto),1,p);
    fclose(p);
    return resultado;
}

void punto2(){
    ArchivoProyecto AP("Proyectos.dat");
    int tamAP = AP.contarRegistros();

    for(int i = 0;i<tamAP;i++){
        Proyecto proy;
        proy = AP.leerRegistro(i);
        if(proy.getCategoria() == 7){
            proy.setEstado(false);
        }
        modificarProyecto(proy,i);
    }

    for(int i = 0;i<tamAP;i++){
        Proyecto proy;
        proy = AP.leerRegistro(i);
        if(proy.getEstado() == true){
            proy.Mostrar();
        }
    }
}

void punto5(){
    ArchivoProyecto AP("Proyectos.dat");
    int tamAP = AP.contarRegistros();

    Proyecto* vProy = new Proyecto[tamAP];
    for(int i = 0;i<tamAP;i++){
        vProy[i] = AP.leerRegistro(i);
    }

    for(int i = 0;i<tamAP;i++){
        if(vProy[i].getEstado() == true){
            vProy[i].Mostrar();
        }
    }


    delete[] vProy;
}

int main()
{
    punto1();
    punto2();
    punto5();
    return 0;
}
