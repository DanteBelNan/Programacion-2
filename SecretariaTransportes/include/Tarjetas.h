#ifndef TARJETAS_H
#define TARJETAS_H

#include "Fecha.h"

class Tarjetas
{
    private:
        int numero;
        Fecha alta;
        int dni;
        float saldo;
        bool estado;

    public:
        Tarjetas() {
            saldo = 0;
            estado = true;
        }

        int getNumero(){return numero;}
        Fecha getAlta(){return alta;}
        int getDni(){return dni;}
        float getSaldo(){return saldo;}
        bool getEstado(){return estado;}

        bool setNumero(int numero){
            if(numero>0){
                this->numero = numero;
                return true;
            }
            return false;
        }
        void setAlta(){alta.Cargar();}
        bool setDni(int dni){
            if(dni>0){
                this->dni = dni;
                return true;
            }
            return false;
        }

        void cargar(){
            bool validated = false;
            while(!validated){
                cout<<"INGRESE EL NUMERO DE LA TARJETA: ";

                int numero;
                cin>>numero;
                validated = setNumero(numero);
                if(!validated){
                    cout<<"NUMERO DE TARJETA INCORRECTO..."<<endl;
                }
            }

            cout<<"FECHA DE ALTA: "<<endl;
            alta.Cargar();

            validated = false;
            while(!validated){
                cout<<"INGRESE EL DNI DEL PROPIETARIO: ";

                int dni;
                cin>>dni;
                validated = setDni(dni);
                if(!validated){
                    cout<<"NUMERO DE TARJETA INCORRECTO..."<<endl;
                }
            }
        }

        void mostrar(){
            cout<<"-----------------------------------------"<<endl;
            cout<<"NUMERO DE TARJETA: "<<numero<<endl;
            cout<<"FECHA DE ALTA: ";
            alta.Mostrar();
            cout<<"DNI DEL PROPIETARIO: "<<dni<<endl;
            cout<<"SALDO: "<<saldo<<endl;
            cout<<"ESTADO: ";
            estado ? cout<<"ACTIVA"<<endl : cout<<"DADA DE BAJA"<<endl;
        }

        void darBaja(bool confirmacion){
            if(confirmacion){
                estado = false;
            }
        }

        int tamArchivo(){
            FILE *pTarjetas;
            int tam;
            pTarjetas = fopen("Tarjetas.dat", "rb");
            if(pTarjetas == NULL){
                return -1;
            }
            fseek(pTarjetas, 0, SEEK_END);
            tam = ftell(pTarjetas)/sizeof(this);
            fclose(pTarjetas);
            return tam;
        }
        int buscarID(int id){
            Tarjetas container;
            FILE *pTarjetas;

            pTarjetas = fopen("Tarjetas.dat", "rb");
            if(pTarjetas==NULL){
                return -2;
            }
            for(int pos = 0;pos<tamArchivo();pos++){
                fread(&container, sizeof(this)*pos,1,pTarjetas);
                if(container.getNumero()==id){
                    fclose(pTarjetas);
                    return pos;
                }
            }
            fclose(pTarjetas);
            return -1;
        }

        int agregarRegistro(){
            FILE *pTarjetas;
            pTarjetas = fopen("Tarjetas.dat","ab");

            if(pTarjetas == NULL){
                return -1;
            }
            int resultado = fwrite(this, sizeof(*this),1,pTarjetas);
            fclose(pTarjetas);
            return resultado;
        }

        int guardarRegistro(){
            int pos = buscarID(numero);
            if(pos!=-1){
                FILE *pTarjetas;
                pTarjetas = fopen("Tarjetas.dat","rb+");
                if(pTarjetas == NULL){
                    return -1;
                }
                fseek(pTarjetas,pos*sizeof(this),0);
                int resultado = fwrite(this,sizeof(this),1,pTarjetas);
                fclose(pTarjetas);
                return resultado;
            }
            return -1;
        }

        int cargarRegistro(int numero){
            int pos = buscarID(numero);
            if(pos!=-1){
                FILE *pTarjetas;
                pTarjetas = fopen("Tarjetas.dat", "rb");
                if(pTarjetas==NULL){
                    return -1;
                }
                int resultado = fread(this, sizeof(this)*pos,1,pTarjetas);
                fclose(pTarjetas);
                return resultado;
            }
            return -1;

        }


};

#endif // TARJETAS_H
