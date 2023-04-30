#ifndef DNI_H
#define DNI_H
#include<cstdlib>
#include<cstring>
#include "Fecha.h"#include "functions.h"



class DNI
{
    protected:
        int dni;
        char nombre [24];
        char apellido [24];
        char email [24];
        char domicilio [24];
        Fecha nacimiento;
        int cargo;
        bool seCargo = false;



    public:
        DNI(int dni=-1){
            this->dni = dni;
        }

        int getDNI(){return dni;}
        const char* getNombre(){return nombre;}
        const char* getApellido(){return apellido;}
        const char* getEmail(){return email;}
        const char* getDomicilio(){return domicilio;}
        Fecha getNacimiento(){return nacimiento;}
        int getCargo(){return cargo;}

        void setDNI(int dni){this->dni = dni;}
        void setNombre(const char* nombre){strcpy(this->nombre,nombre);}
        void setApellido(const char* apellido){strcpy(this->apellido,apellido);}
        void setEmail(const char* email){strcpy(this->email,email);}
        void setDomicilio(const char* domicilio){strcpy(this->domicilio,domicilio);}
        void setNacimiento(){nacimiento.Cargar();}
        bool setCargo(int cargo){
                if(cargo >= 1 && cargo <= 10){

                    this->cargo = cargo;
                    return true;
                }else{
                    cout<<"EL NUMERO DE CARGO ES INCORRECTO, INGRESE UN VALOR ENTRE 1 Y 10: ";
                    return false;
                }
            }

        void cargar(){
            cout<<"DNI: ";
            cin>>dni;
            cout<<"Fecha Nacimiento: "<<endl;
            nacimiento.Cargar();
            cout<<"Nombre: ";
            cargarCadena(nombre, 24);
            cout<<"APELLIDO: ";
            cargarCadena(apellido,24);
            cout<<"EMAIL: ";
            cargarCadena(email, 24);
            cout<<"DOMICILIO: ";
            cargarCadena(domicilio,24);
            cout<<"CARGO (1 al 10): ";
            bool isValid;
            do{
                int cargo;
                cin>>cargo;
                isValid = setCargo(cargo);
            }while(!isValid);
            seCargo = true;
        }

        void mostrar(){
            if(seCargo){
                cout<<"----------------------------------------"<<endl;
                cout<<"DNI: "<<dni<<endl;
                cout<<"NOMBRE: "<<nombre<<" "<<apellido<<endl;
                cout<<"EMAIL: "<<email<<endl;
                cout<<"DOMICILIO: "<<domicilio<<endl;
                cout<<"NACIMIENTO: ";
                nacimiento.Mostrar();
                cout<<endl;
                cout<<"CARGO: "<<cargo<<endl;
                cout<<"----------------------------------------"<<endl;
            }else{
                cout<<"NO SE PUEDE MOSTRAR UN DNI SI NO SE CARGO PREVIAMENTE"<<endl;
            }
        }

};

#endif // DNI_H
