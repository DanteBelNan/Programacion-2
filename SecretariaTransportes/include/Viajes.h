#ifndef VIAJES_H
#define VIAJES_H



class Viajes
{
    private:        int numViaje;
        int numTarjeta;
        int medioTransporte;
        Fecha viaje;
        float importe;

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
        bool setMedioTransporte(int medioTransporte){
            if(medioTransporte>0 && medioTransporte<=3){
                this->medioTransporte = medioTransporte;
                return true;
            }
            return false;
        }
        void setImporte(int importe){
            this->importe = importe;
        }

        int getNumViaje(){return numViaje;}
        int getNumTarjeta(){return numTarjeta;}
        int getMedioTransporte(){return medioTransporte;}
        int getImporte(){return importe;}


};

#endif // VIAJES_H
