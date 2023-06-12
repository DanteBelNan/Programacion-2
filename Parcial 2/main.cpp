#include <iostream>
#include <cstring>
using namespace std;

#include "parcial2.h"

class Cpunto1{
    private:
        int codigoRestaurante;
        int DNI;
        Fecha fechaReserva;
    public:
        void setCodigoRestaurante(int codigoRestaurante){this->codigoRestaurante = codigoRestaurante;}
        void setDNI(int DNI){this->DNI = DNI;}
        void setFechaReserva(Venta ven){
            this->fechaReserva = ven.getFechaReserva();
        }

        int getCodigoRestaurante(){return this->codigoRestaurante;}
        int getDNI(){return this->DNI;}
        Fecha getFechaReserva(){return fechaReserva;}

        void mostrar(){
            cout<<"Codigo restaurante: "<<codigoRestaurante<<endl;
            cout<<"DNI: "<<DNI<<endl;
            fechaReserva.Mostrar();
            cout<<"---------------------------------"<<endl;
        }

        void operator == (Cpunto1 obj){
            this->codigoRestaurante = obj.getCodigoRestaurante();
            this->DNI = obj.getDNI();
            this->fechaReserva = obj.getFechaReserva();
        }

};

class Apunto1{
    private:

    public:
        int guardarRegistro(Cpunto1 reg)
        {
          FILE *p = fopen("punto1.dat", "ab");

          if (p == NULL)
          {
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
    cout<<"Nombre del restaurante elegido: ";
    char nombreRes[30];
    cargarCadena(nombreRes,30);

    ArchivoRestaurantes AR("restaurantes.dat");
    ArchivoVentas AV("ventas.dat");
    Apunto1 AP1;

    int tamAR = AR.contarRegistros();
    int tamAV = AV.contarRegistros();

    for(int i = 0;i<tamAR;i++){
        Restaurante res;
        res = AR.leerRegistro(i);

        if(res.getEstado()){
            if(!strcmp(nombreRes,res.getNombre())){ //entro al restaurante

                for(int i2 = 0; i2<tamAV;i2++){
                    Venta venta;
                    venta = AV.leerRegistro(i2);
                    if(venta.getEstado()){
                        if(res.getCodigoRestaurante() == venta.getCodigoRestaurante()){
                            Cpunto1 obj;
                            obj.setCodigoRestaurante(venta.getCodigoRestaurante());
                            obj.setFechaReserva(venta);
                            obj.setDNI(venta.getDNI());

                            AP1.guardarRegistro(obj);
                        }
                    }
                }
            }
        }
    }

    int tam = AP1.contarRegistros();
    for(int i = 0;i<tam;i++){
        Cpunto1 obj;
        obj = AP1.leerRegistro(i);
        cout<<i<<endl;
        obj.mostrar();
    }

}


void punto2(){
    int cantResxCat[4] = {};

    ArchivoRestaurantes AR("restaurantes.dat");
    int tam = AR.contarRegistros();

    for(int i = 0;i<tam;i++){
        Restaurante res;
        res = AR.leerRegistro(i);
        if(res.getEstado()){
            int pos = res.getCategoria()-1;
            cantResxCat[pos]++;
        }
    }

    int numMax = 0;
    for(int i = 1; i < 4; i++){
        if(cantResxCat[i] > cantResxCat[numMax]){
            numMax = i;
        }
    }

    cout<<"La categoria con mas restaurantes es la numero: "<<numMax+1<<endl;


}

void punto4(){
    Apunto1 AP1;
    int tam = AP1.contarRegistros();

    Cpunto1* vObj = new Cpunto1[tam];

    for(int i = 0;i<tam;i++){
        vObj[i] = AP1.leerRegistro(i);
    }

    for(int i = 0;i<tam;i++){
        vObj[i].mostrar();
    }

    delete[] vObj;
}


int main()
{

    punto1();
    punto2();
    punto4();



    return 0;
}
