#ifndef VIAJES_H
#define VIAJES_H



class Viajes
{
    private:        int numViaje;
        int numTarjeta;
        int medioTransporte;
        Fecha viaje;
        float importeViaje;

    public:
        Viajes() {}

        bool setNumViaje(int numViaje){
            if(numViaje>0){
                this->numViaje = numViaje;
                return true;
            }
            return false;
        }
        bool setNumTarjeta(int numTarjeta){
            if(numTarjeta>0){
                this->numTarjeta = numTarjeta;
                return true;
            }
            return false;
        }


};

#endif // VIAJES_H
