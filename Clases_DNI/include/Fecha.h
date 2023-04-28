#ifndef FECHA_H
#define FECHA_H

using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
        }
        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
        ///sets
        void setDia(int x){if(x>0 && x<32) dia=x;}
        void setMes(int x){if(x>0 && x<13)mes=x;}
        void setAnio(int x){anio=x;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

#endif // FECHA_H
