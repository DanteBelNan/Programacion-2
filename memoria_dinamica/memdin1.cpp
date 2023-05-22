///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

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

int main(){
    int *v;
    int tam;
    cout<<"INGRESE LA CANTIDAD DE ELEMENTOS QUE NECESITA PARA EL VECTOR ";
    cin>>tam;
    v=new int[tam];
    if(v==NULL){
        cout<<"ERROR DE ASIGANCION DE MEMORIA"<<endl;
        return -1;
    }
    cargarVector(v,tam);
    mostrarVector(v,tam);
    delete v;///delete []v
    cout<<"INGRESE EL NUEVO TAMANIO PARA EL VECTOR ";
    cin>>tam;
    v=new int[tam];
    if(v==NULL){
        cout<<"ERROR DE ASIGANCION DE MEMORIA"<<endl;
        return -1;
    }
    cargarVector(v,tam);
    mostrarVector(v,tam);
    delete v;
	cout<<endl;
	system("pause");
	return 0;
}
