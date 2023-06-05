#include <iostream>
#include <cstring>
using namespace std;
#include "parcial1.h"
/*
a) Generar un archivo con la cantidad de tareas para cada uno de los proyectos
Cada registro debe tener
C�digo de proyecto, nombre y cantidad de tareas
b) Generar un archivo con el tiempo trabajado por cada empleado en el mes de mayo.
Cada registro debe tener el siguiente formato
n�mero de empleado,nombre y cantidad de horas

c) Informar para cada uno de los empleados la cantidad total de tareas realizadas de cada categor�a (5 categorias)
d) Para cada origen, informar la cantidad de componentes de cada tipo.
e) Dar de baja a todos los componentes de origen europeo
f) Listar el archivo del punto a usando asignaci�n din�mica de memoria

*/

class CpuntoA{
    private:
        char codigoProyecto[5];
        char nombre[30];
        int cantTareas;
        int activo;

    public:
        puntoA(){
            cantTareas = 0;
        }
        void cargar(Proyecto proy){
            strcpy(this->codigoProyecto, proy.getCodigoProyecto());
            strcpy(this->nombre, proy.getNombre());
            this->activo = proy.getActivo();
        }
        void sumTarea(){
            cantTareas++;
        }
        int guardarRegistro(){
            FILE * pFILE;
            pFILE = fopen("puntoA.dat","ab");
            if(pFILE == NULL){
                return -1;
            }
            int resultado = fwrite(this, sizeof(*this),1,pFILE);
            fclose(pFILE);
            return resultado;
        }

};

void puntoA(){
    ArchivoProyecto AP("proyectos.dat");
    ArchivoTarea AT("tareas.dat");

    int tamProy = AP.contarRegistros();
    int tamTar = AT.contarRegistros();

    for(int i = 0;i<tamProy;i++){
        Proyecto proy;
        proy = AP.leerRegistro(i);
        CpuntoA obj;
        obj.cargar(proy);
        if(proy.getActivo()){
            for(int i2 = 0;i2<tamTar;i2++){
                Tarea tarea;
                tarea = AT.leerRegistro(i2);
                if(tarea.getActivo()){
                    if(!strcmp(proy.getCodigoProyecto(), tarea.getCodigoProyecto())){
                        obj.sumTarea();
                    }
                }
            }
            obj.guardarRegistro();
        }
    }
}

class CpuntoB{
    private:
        int numeroEmpleado;
        char nombre[30];
        int cantHoras;
        bool activo;

    public:
        CpuntoB(){cantHoras = 0;}
        void cargar(Empleado obj){
            this->numeroEmpleado = obj.getNumero();
            strcpy(this->nombre,obj.getNombre());
            this-> activo = obj.getActivo();
        }
        void sumarHoras(int horas){
            this->cantHoras += horas;
        }
        int guardarRegistro(){
            FILE * pFILE;
            pFILE = fopen("puntoB.dat","ab");
            if(pFILE == NULL){
                return -1;
            }
            int resultado = fwrite(this, sizeof(*this),1,pFILE);
            fclose(pFILE);
            return resultado;
        }

};

void puntoB(){
    ArchivoEmpleado AE("empleados.dat");
    ArchivoTarea AT("tareas.dat");

    int tamEmp = AE.contarRegistros();
    int tamTar = AT.contarRegistros();

    for(int i = 0;i<tamEmp;i++){
        Empleado emp;
        emp = AE.leerRegistro(i);
        CpuntoB obj;
        obj.cargar(emp);
        if(emp.getActivo()){
            for(int i2 = 0; i2<tamTar;i2++){
                Tarea tar;
                tar = AT.leerRegistro(i2);
                if(tar.getActivo()){
                    if(emp.getNumero() == tar.getNumeroEmpleado()){
                        if(tar.getFechaTarea().getMes()==5){
                            obj.sumarHoras(tar.getTiempo());
                        }
                    }
                }
            }
            obj.guardarRegistro();
        }
    }
}

void puntoC(){
    ArchivoEmpleado AE("empleados.dat");
    ArchivoTarea AT("tareas.dat");

    int tamEmp = AE.contarRegistros();
    int tamTar = AT.contarRegistros();

    for(int i = 0;i<tamEmp;i++){
        Empleado emp;
        emp = AE.leerRegistro(i);
        if(emp.getActivo()){
            int cantTareasxCat[5] = {};
            for(int i2 = 0; i2<tamTar;i2++){
                Tarea tar;
                tar = AT.leerRegistro(i2);
                if(tar.getActivo()){
                    if(emp.getNumero() == tar.getNumeroEmpleado()){
                        int pos = tar.getCategoria() -1;
                        cantTareasxCat[pos]++;
                    }
                }
            }
            cout<<"----------------------------"<<endl;
            cout<<emp.getNombre()<<endl;
            for(int i = 0;i<5;i++){
                cout<<"categoria: "<<i+1<<": "<<cantTareasxCat[i]<<endl;
            }
            cout<<"----------------------------"<<endl;
        }
    }
}
int main()
{
    puntoA();
    puntoB();
    puntoC();
    return 0;
}