#include <iostream>

using namespace std;


/*
A partir del cpp anterior, crear un vector dinámico con los valores pares del vector original,
 y otro vector dinámico con los valores impares

*/


    void cargarVector(int *v, int tam){
        int i;
        for(i=0;i<tam;i++){
            cout<<"INGRESE UN NUMERO: ";
            cin>>v[i];
        }
    }

    void mostrarVector(int *v, int tam){
        int i;
        for(i=0;i<tam;i++){
            cout<<v[i]<<endl;
        }
    }

int main()
{
    int *v;
    int tam = 10;
    v = new int[tam];



    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    v[5] = 6;
    v[6] = 7;
    v[7] = 8;
    v[8] = 9;
    v[9] = 10;

    int Tampares = 0;
    int Tamimpares = 0;

    for(int i = 0;i<tam;i++){
        if(v[i]%2==0){
            Tampares++;
        }else{
        Tamimpares++;
        }
    }


    int *vPares;
    int *vImpares;

    vPares = new int[Tampares];
    vImpares = new int[Tamimpares];

    for(int i = 0;i<tam;i++){
        int iPares = 0;
        int iImpares = 0;
        if(v[i]%2==0){
            vPares[iPares] = v[i];
            iPares++;

        }else{
            vImpares[iImpares] = v[i];
            iPares++;
        }

    }






    delete[]v;
    delete[]vPares;
    delete[]vImpares;
    return 0;
}
