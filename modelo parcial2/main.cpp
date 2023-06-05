#include <iostream>
#include <cstring>
using namespace std;
#include "parcial1.h"
/*
Generar un archivo con la cantidad de tareas para cada uno de los proyectos
Cada registro debe tener
a) Código de proyecto, nombre y cantidad de tareas
b) Generar un archivo con el tiempo trabajado por cada empleado en el mes de mayo.
Cada registro debe tener el siguiente formato
número de empleado,nombre y cantidad de horas

c) Informar para cada uno de los empleados la cantidad total de tareas realizadas de cada categoría
d) Para cada origen, informar la cantidad de componentes de cada tipo.
e) Dar de baja a todos los componentes de origen europeo
f) Listar el archivo del punto a usando asignación dinámica de memoria

*/

class CpuntoA{
    private:
        char codigoProyecto[5];
        char nombre[30];
        int cantTareas;

    public:
        puntoA(){
            cantTareas = 0;
        }
        void cargar(Proyecto proy){
            strcpy(this->codigoProyecto, proy.getCodigoProyecto());
            strcpy(this->nombre, proy.getNombre());
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
    ArchivoProyecto AP;
    ArchivoTarea AT;

    int tamProy = AP.contarRegistros();
    int tamTar = AT.contarRegistros();

    for(int i = 0;i<tamProy;i++){
        Proyecto proy;
        proy = AP.leerRegistro(i);
        CpuntoA obj;
        obj.cargar(proy);
        for(int i2 = 0;i2<tamTar;i2++){
            Tarea tarea;
            tarea = AT.leerRegistro(i2);
            if(!strcmp(proy.getCodigoProyecto(), tarea.getCodigoProyecto())){
                obj.sumTarea();
            }
        }
        obj.guardarRegistro();
    }
}
int main()
{
    return 0;
}
