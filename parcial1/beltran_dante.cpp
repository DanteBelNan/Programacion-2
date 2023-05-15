#include <iostream>
#include <cstring>
using namespace std;

#include "parcial1.h"

class Punto1{
    private:
        int codigo;
        char nombre[30];
        Fecha fechaUltimaCompra;

    public:
        void cargar(Componente comp){
            codigo = comp.getCodigo();
            strcpy(nombre,comp.getNombre());
            fechaUltimaCompra = comp.getFecha();
        }
        int guardarRegistro(){
            FILE * p;
            p = fopen("punto1.dat", "ab");
            if(p == NULL){
                return -1;
            }
            int resultado = fwrite(this, sizeof(*this),1,p);
            fclose(p);
            return resultado;
        }
};

void punto1(){
    ArchivoComponente obj("componentes.dat");
    int tam = obj.contarRegistros();
    for(int i = 0;i<tam;i++)
    {
        Componente comp;
        comp = obj.leerRegistro(i);
        if(comp.getTipo() == 2 && comp.getPU()> 50000){
            Punto1 p1;
            p1.cargar(comp);
            p1.guardarRegistro();
            p1.mostrar();
        }
    }
}

void punto2(){
    ArchivoProyecto obj("proyectos.dat");
    int tam = obj.contarRegistros();
    cout<<"ESTADOS DE DESARROLLO DE PROYECTOS CON UN PRESUPUESTO MAYOR A $50.000..."<<endl;
    for(int i = 0;i<tam;i++){
        Proyecto proy;
        proy = obj.leerRegistro(i);
        if(proy.getPresupuesto()>50000){
            cout<<"+------------------------------+"<<endl;
            cout<<proy.getEstadoDesarrollo()<<endl;
        }
    }
}

int main()
{
    punto1();
    punto2();
    return 0;
}

