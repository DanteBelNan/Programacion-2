#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void cargarCadena(char *pal, int tam) {
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++) {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

#endif // FUNCTIONS_H_INCLUDED
