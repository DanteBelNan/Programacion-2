#include <iostream>

using namespace std;

class CpuntoA{
    private:
        int codigoCereal;
        char nombre[30];
        int cantToneladas;

    public:
        CpuntoA(){
            cantToneladas = 0;
        }



};

class ApuntoA{
    public:

        int guardarRegistro(CpuntoA reg){
        FILE *p = fopen("puntoa.dat", "ab");
        
        if (p == NULL)
        {
            return -1;
        }
    
    int resultado = fwrite(&reg, sizeof(CpuntoA), 1, p);
    fclose(p);
    return resultado;
    }

    CpuntoA leerRegistro(int pos){
        CpuntoA reg;
        FILE *p;
        p=fopen("archivo.dat", "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(CpuntoA)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

};
int main()
{
    
    return 0;
}
