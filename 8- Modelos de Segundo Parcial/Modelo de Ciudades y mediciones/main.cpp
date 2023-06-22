#include <iostream>
#include <cstring>
using namespace std;

#include "parcial2.h"

class CpuntoA{
    private:
    int codigoCiudad;
    char nombreCiudad[30];
    int cantMediciones; //moderada o buena visibilidad

    public:
    CpuntoA(Ciudades ciu){
        this->codigoCiudad = ciu.getCodigoCiudad();
        strcpy(this->nombreCiudad,ciu.getNombre());
        this->cantMediciones = 0;
    }

    void Mostrar(){
        cout<<this->codigoCiudad<<endl<<this->nombreCiudad<<endl<<this->cantMediciones<<endl;
    }

    void sumaMedicion(Mediciones med){
        if(med.getCiudad() == this->codigoCiudad){
            if(med.getVisibilidad()>4000){
                this->cantMediciones++;
            }
        }
    }
};

class ApuntoA{
    private:

    public:
    int guardarRegistro(CpuntoA reg){
        FILE *p = fopen("puntoa.dat", "ab");
        
        if (p == NULL)
        {
            return -1;
        }
        
        int resultado = fwrite(&reg, sizeof(CpuntoA), 1, p);
        fclose(p);
        return resultado;
    }
};


void puntoA(){
    ArchivoCiudades AC;
    ArchivoMediciones AM;

    int tamAC = AC.contarRegistros();
    int tamAM = AM.contarRegistros();

    for(int i = 0;i<tamAC;i++){
        Ciudades ciudad;
        ciudad = AC.leerRegistro(i);
        CpuntoA obj(ciudad);
        for(int i2 = 0;i2<tamAM;i2++){
            Mediciones med;
            med = AM.leerRegistro(i2);
            if(ciudad.getCodigoCiudad() == med.getCiudad()){
                obj.sumaMedicion(med);
            }
        }
        ApuntoA Aobj;
        Aobj.guardarRegistro(obj);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
