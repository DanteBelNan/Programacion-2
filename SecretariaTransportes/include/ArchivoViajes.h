#ifndef ARCHIVOVIAJES_H
#define ARCHIVOVIAJES_H


class ArchivoViajes
{
    private:
        FILE* p;

    public:
        ArchivoViajes() {}
        Viajes leerRegistro(int pos){
            Viajes viaje;
            viaje.setNumViaje(-1);
            p=fopen("viajes.dat", "rb");
            if(p==NULL) return viaje;
            fseek(p,sizeof(viaje)*pos,0);
            fread(&viaje, sizeof(viaje),1,p);
            fclose(p);
            return viaje;
        }
        int contarRegistros(){
            p=fopen("viajes.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Viajes);
        }
        int guardarRegistro(Viajes viaje){
            p = fopen("viajes.dat","ab");
            if(p == NULL) return -1;
            int resultado = fwrite(&viaje,sizeof(viaje),1,p);
            fclose(p);
            return resultado;
        }
        int modificarRegistros(int pos, Viajes viaje){
            if(pos>contarRegistros()) return -1;
            p = fopen("viajes.dat","rb+");
            if(p == NULL) return -2;
            int resultado = fwrite(&viaje,sizeof(viaje),1,p);
            fclose(p);
            return resultado;
        }
        int buscarNumero(int num){
            for(int i = 0;i<contarRegistros();i++){
                Viajes viaje;
                viaje = leerRegistro(i);
                if(viaje.getNumTarjeta() == num){
                    return i;
                }
            }
            cout<<"Viaje no encontrado..."<<endl;
            return -1;
        }
};

#endif // ARCHIVOVIAJES_H
