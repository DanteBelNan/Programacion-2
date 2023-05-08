#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Fecha.h"
#include "direccion.h"

class inmobiliaria
{
    protected:
        direccion Direccion;
        Fecha ingreso;
        Fecha operacion;
        int superficie;
        int operacion;



    public:
        inmobiliaria() {}

};

#endif // INMOBILIARIA_H
