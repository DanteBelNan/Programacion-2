#ifndef ARCHIVOTARJETAS_H
#define ARCHIVOTARJETAS_H


class ArchivoTarjetas
{
    private:        FILE* p;

    public:
        ArchivoTarjetas() {}
        Tarjetas leerRegistro(int pos){
            Tarjetas tarj;
            tarj.setDni(-1);
            p=fopen("tarjetas.dat", "rb");
            if(p==NULL) return tarj;
            fseek(p,sizeof(Tarjetas)*pos,0);
            fread(&tarj, sizeof(tarj),1,p);
            fclose(p);
            return tarj;
        }
        int contarRegistros(){
            p=fopen("tarjetas.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Tarjetas);
        }
        int guardarRegistro(Tarjetas tarj){
            p = fopen("tarjetas.dat","ab");
            if(p == NULL) return -1;
            int resultado = fwrite(&tarj,sizeof(tarj),1,p);
            fclose(p);
            return resultado;
        }
        int modificarRegistros(int pos, Tarjetas tarj){
            if(pos>contarRegistros()) return -1;
            p = fopen("tarjetas.dat","rb+");
            if(p == NULL) return -2;
            int resultado = fwrite(&tarj,sizeof(tarj),1,p);
            fclose(p);
            return resultado;
        }

};

#endif // ARCHIVOTARJETAS_H
