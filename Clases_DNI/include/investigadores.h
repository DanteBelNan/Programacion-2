#ifndef INVESTIGADORES_H
#define INVESTIGADORES_H

#include <DNI.h>


class investigadores : public DNI
{
    private:
        int unidadAcademica;
        int categoria;
        int especialidad;

    public:
        investigadores(int dni=0){
            this->dni = dni;
        }

        bool setUnidadAcademica(int unidadAcademica){
            if(unidadAcademica >=1 && unidadAcademica <=30){
                this->unidadAcademica = unidadAcademica;
                return true;
            }
            cout<<"EL NUMERO DE UNIDAD ACADEMICA ES INCORRECTO, INGRESE UN VALOR ENTRE 1 Y 30: ";
            return false;
        }
        bool setCategoria(int categoria){
            if(categoria >=1 && categoria <=5){
                this->categoria = categoria;
                cout<<"EL NUMERO DE CATEGORIA ES INCORRECTO, INGRESE UN VALOR ENTRE 1 Y 5: ";
                return true;
            }
            return false;
        }
        bool setEspecialidad(int especialidad){
            if(especialidad>=1 && especialidad<=10){
                this->especialidad = especialidad;
                return true;
            }
            cout<<"EL NUMERO DE ESPECIALIDAD ES INCORRECTO, INGRESE UN VALOR ENTRE 1 Y 10: ";
            return false;
        }

        int getUnidadAcademica(){return unidadAcademica;}
        int getCategoria(){return categoria;}
        int getEspecialidad(){ return especialidad;}



    protected:

};

#endif // INVESTIGADORES_H
