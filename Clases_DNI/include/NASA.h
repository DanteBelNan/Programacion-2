#ifndef NASA_H
#define NASA_H


class NASA
{
        private:
        int numeroMision;
        char nombreMision [30];
        char nombreAstronauta[30];
        Fecha inicio;
        Fecha fin;
        float presupuesto;

    public:
        NASA(const char* nombreMision="nada",const char* nombreAstronauta="nada") {
            strcpy(this->nombreMision,nombreMision);
            strcpy(this->nombreAstronauta,nombreAstronauta);
        }

        int getNumeroMision() { return numeroMision; }
        const char* getNombreMision() { return nombreMision; }
        const char* getNombreAstronauta() { return nombreAstronauta; }
        float getPresupuesto() { return presupuesto; }


        void setNumeroMision(int val) { numeroMision = val; }
        void setNombreMision(const char* nombreMision) { strcpy(this->nombreMision,nombreMision); }
        void setnombreAstronauta(const char* nombreAstronauta) { strcpy(this->nombreAstronauta,nombreAstronauta); }
        void setPresupuesto(float val) { presupuesto = val; }


    protected:


};

#endif // NASA_H
