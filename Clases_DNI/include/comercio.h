#ifndef COMERCIO_H
#define COMERCIO_H

#include "Fecha.h"

class comercio
{
    private:
    int numCompra;
    Fecha fechaCompra;
    char nombre[30];
    int tipo;
    int formaPago;
    int cantidad;
    int total;

    public:
        comercio(int numCompra=0,int tipo=0,int formaPago=0,int cantidad=0,int total=0) {
            this->numCompra = numCompra;
            this->tipo = tipo;
            this->formaPago = formaPago;
            this->cantidad = cantidad;
            this->total = total;
        }
        ~comercio() {}

        void setNumCompra(int numCompra){this->numCompra = numCompra;}
        void setNombre(const char* nombre){strcpy(this->nombre,nombre);}
        bool setTipo(int tipo){
            if(tipo >=1 && tipo<=15){
                this->tipo = tipo;
                return true;
            }
            cout<<"EL NUMERO DE TIPO DE PRODUCTO ES INCORRECTO, INGRESE UN VALOR ENTRE 1 Y 15: ";
            return false;
        }
        bool setFormaPago(int formaPago){
            if(formaPago>=1 && formaPago<=5){
                this->formaPago = formaPago;
                return true;
            }
            cout<<"EL NUMERO DE FORMA DE PAGO ES INCORRECTO, INGRESE UN VALOR ENTRE 1 Y 5: ";
            return false;
        }
        void setCantidad(int cantidad){
            this->cantidad = cantidad;
        }
        void setImporteTotal(int total){
            this->total = total;
        }

        int getNumCompra(){return numCompra;}
        const char* getNombre(){return nombre;}
        Fecha getFecha(){return fechaCompra;}
        int getTipoProducto(){return tipo;}
        int getFormaPago(){return formaPago;}
        int getCantidad(){return cantidad;}
        int getImporteTotal(){return total;}

    protected:

};

#endif // COMERCIO_H
