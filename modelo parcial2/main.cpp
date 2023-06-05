#include <iostream>
#include <cstring>
using namespace std;
#include "parcial1.h"
/*
a) Generar un archivo con la cantidad de tareas para cada uno de los proyectos
Cada registro debe tener
Código de proyecto, nombre y cantidad de tareas
b) Generar un archivo con el tiempo trabajado por cada empleado en el mes de mayo.
Cada registro debe tener el siguiente formato
número de empleado,nombre y cantidad de horas

c) Informar para cada uno de los empleados la cantidad total de tareas realizadas de cada categoría (5 categorias)
d) Para cada origen, informar la cantidad de componentes de cada tipo. (hay 6 origenes)
e) Dar de baja a todos los componentes de origen europeo (5)
f) Listar el archivo del punto a usando asignación dinámica de memoria

*/

class CpuntoA{
    private:
        char codigoProyecto[5];
        char nombre[30];
        int cantTareas;
        bool activo;

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

        void mostrar(){
            cout<<"------------------------"<<endl;
            cout<<"Codigo Proy: "<<this->codigoProyecto<<endl;
            cout<<"Nombre: "<<this->nombre<<endl;
            cout<<"Cant Tareas: "<<this->cantTareas<<endl;
            cout<<"------------------------"<<endl;
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

void puntoD(){
    ArchivoComponente AC("componentes.dat");
    int tamComp = AC.contarRegistros();
    int cantCompxOrig [6] = {};
    for(int i = 0;i<tamComp;i++){
        Componente comp;
        comp = AC.leerRegistro(i);
        int pos = comp.getOrigen()-1;
        cantCompxOrig[pos]++;
    }
    for(int i = 0;i<6;i++){
        cout<<cantCompxOrig[i]<<endl;
    }
}

bool modificarComponente(Componente comp, int pos){
    FILE* p = fopen("componentes.dat", "rb+");
    if (p == NULL) {
        return false;
    }
    fseek(p, pos * sizeof(Componente), SEEK_SET);
    bool ok = fwrite(&comp, sizeof(Componente), 1, p);
    fclose(p);
    return ok;
}

void puntoE(){
    ArchivoComponente AC("componentes.dat");
    int tamComp = AC.contarRegistros();
    for(int i = 0;i<tamComp;i++){
        Componente comp;
        comp = AC.leerRegistro(i);
        if(comp.getOrigen()==5){
            comp.setActivo(false);
            modificarComponente(comp,i);
        }
    }
}

int contarRegistrosPA(){
    FILE *p;
    p=fopen("puntoA.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(CpuntoA);
}

void puntoF(){
    int tam = contarRegistrosPA();
    CpuntoA* pA = new CpuntoA[tam];
    for(int i = 0;i<tam;i++){
        pA[i] = pA[i].leerRegistro(i);
    }
    for(int i = 0;i<tam;i++){
        pA[i].mostrar();
    }
    delete[] pA;
}



int main()
{
    puntoA();
    puntoB();
    puntoC();
    puntoD();
    puntoE();
    puntoF();
    return 0;
}
