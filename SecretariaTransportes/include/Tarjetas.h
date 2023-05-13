#ifndef TARJETAS_H
#define TARJETAS_H


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


};

#endif // TARJETAS_H
