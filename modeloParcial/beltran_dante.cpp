#include <iostream>
#include <cstring>
using namespace std;
#include "parcialm1.h"

class Punto1{
    private:
        char codigoObra[5];
        char direccion[30];
        int provincia;
    public:
        Punto1(){}
        void cargar(Obra obra){
            if(obra.getEstadoEjecucion() == 3){
                strcpy(codigoObra, obra.getCodigoObra());
                strcpy(direccion, obra.getDireccion());
                provincia = obra.getProvincia();
            }
        }

        int guardarRegistro(){
            FILE * pFILE;
            pFILE = fopen("punto1.dat","ab");
            if(pFILE == NULL){
                return -1;
            }
            int resultado = fwrite(this, sizeof(*this),1,pFILE);
            fclose(pFILE);
            return resultado;
        }
};

void punto1(){
    ArchivoObras obj("obras.dat");
    int tam = obj.contarRegistros();
    for(int i = 0;i<tam;i++){
        Obra obra;
        obra = obj.leerRegistro(i);
        if(obra.getEstadoEjecucion()==3){
            Punto1 p1;
            p1.cargar(obra);
            p1.guardarRegistro();
        }
    }
}

void punto2(){
    int contProv [24] = {};

    ArchivoProveedor obj("proovedores.dat");
    int tam = obj.contarRegistros();

    for(int i = 0;i<tam;i++){
        Proveedor prov;
        prov = obj.leerRegistro(i);
        contProv[prov.getProvincia()-1]+=1;
    }
    int numMax = 0;
    for(int i = 1; i < 24; i++){
        if(contProv[i] > contProv[numMax]){
            numMax = i;
        }
    }
    cout<<"LA PROVINCIA CON MAS PROOVEDORES ES LA N°"<<numMax+1<<" CON "<<contProv[numMax]<<" PROOVEDORES"<<endl;

}

int main()
{

    return 0;
}
