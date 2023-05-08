#include <iostream>
#include "functions.h"
#include "Tarjetas.h"
#include "Viajes.h"

using namespace std;

int main()
{
    for(int i = 0;i<4;i++){
        Tarjetas tarj;
        tarj.cargarRegistro(i);
        tarj.mostrar();
    }
    return 0;
}
