int guardarRegistro(){
    FILE * pFILE;
    pFILE = fopen("archivo.dat","ab");
    if(pFILE == NULL){
        return -1;
    }
    int resultado = fwrite(this, sizeof(*this),1,pFILE);
    fclose(pFILE);
    return resultado;
}

Objeto leerRegistro(int pos){
    Objeto reg;
    FILE *p;
    p=fopen("archivo.dat", "rb");
    if(p==NULL) return reg;
    fseek(p, sizeof(Objeto)*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}

int modificarRegistro(int pos){
    FILE* p = fopen("archivo.dat", "rb+");
    if (p == NULL) {
        return -1;
    }
    fseek(p, pos * sizeof(Objeto), SEEK_SET);
    int resultado = fwrite(this, sizeof(Objto), 1, p);
    fclose(p);
    return resultado;
}