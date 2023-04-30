#include <iostream>
#include "DNI.h"
#include "investigadores.h"

using namespace std;



int main()
{

    investigadores inv;
    inv.cargar();
    inv.mostrar();
    inv.setCategoria(5);
    cout<<inv.getCategoria();

    return 0;
}
