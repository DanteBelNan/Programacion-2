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
            if(med.getVisibilidad()>4){
                this->cantMediciones++;
            }
        }
    }

    void operator == (Ciudades ciu){
        this->codigoCiudad = ciu.getCodigoCiudad();
        strcpy(this->nombreCiudad,ciu.getNombre());
        this->cantMediciones = 0;
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


void puntoB(){
    ArchivoCiudades AC;
    ArchivoMediciones AM;

    int tamAC = AC.contarRegistros();
    int tamAM = AM.contarRegistros();

    int minDiasNiebla = 0;
    char nombreCiudad[30];
    Ciudades firstCity;
    firstCity = AC.leerRegistro(0);
    strcpy(nombreCiudad, firstCity.getNombre());
    for(int i =0;i<tamAM;i++){
        Mediciones med;
        med = AM.leerRegistro(i);
        if(med.getCiudad() == firstCity.getCodigoCiudad()){
            if(med.getVisibilidad() != 3){
                minDiasNiebla++;
            }
        }
    }

    for(int i = 0;i<tamAC;i++){
        Ciudades ciudad;
        ciudad = AC.leerRegistro(i);
        int newminDiasNiebla = 0;
        for(int i2 = 0;i2<tamAM;i2++){
            Mediciones med;
            med = AM.leerRegistro(i2);
            if(ciudad.getCodigoCiudad() == med.getCiudad()){
                if(med.getVisibilidad() != 3 && med.getVisibilidad() != 2){
                    newminDiasNiebla++;
                }
            }
        }

        if(newminDiasNiebla < minDiasNiebla){
            minDiasNiebla = newminDiasNiebla;
            strcpy(nombreCiudad,ciudad.getNombre());
        }
    }

    cout<<"La ciudad con menos dias de niebla y neblina es "<<nombreCiudad<<endl;
}

void puntoC(){
    ArchivoCiudades AC;
    int tam = AC.contarRegistros();
    Ciudades* vCiudades = new Ciudades[tam];

    if(vCiudades == nullptr){
        return;
    }

    for(int i = 0;i<tam;i++){
        vCiudades[i] = AC.leerRegistro(i);
    }

    int codigoDeseado = 5; //hardcodeado para no meter inputs

    for(int i = 0;i<tam;i++){
        if(vCiudades[i].getCodigoCiudad() == codigoDeseado){
            vCiudades[i].Mostrar();
        }
    }

    delete[] vCiudades;
}

int main()
{
    
    return 0;
}
