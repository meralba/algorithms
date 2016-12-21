// Example program
#include <iostream>

using namespace std;

int busquedaSecuencial(int *n, int tam, int dato){
    bool encontrado=false;
    int indice=-1;
    for(int i=0; i<tam && !encontrado; i++){
        if(n[i]==dato){
            encontrado=true;
            indice=i;
        }
    }
    return indice;
}


int main()
{
    int *n;
    int tam=10;
    int dato=5;
    
    n=new int[tam];
    n[0]=3;
    n[1]=4;
    n[2]=1;
    n[3]=5;
    n[4]=6;
    n[5]=8;
    n[6]=2;
    n[7]=0;
    n[8]=7;
    n[9]=10;
    
    int indice=busquedaSecuencial(n,tam,dato);
    
    cout << "Encontrado elemento " << dato << " en la posicion " << indice;
    
}