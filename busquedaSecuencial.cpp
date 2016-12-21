/** Algoritmo de búsqueda secuencial
  * @author Mer Alba
  */
#include <iostream>

using namespace std;

/** Algoritmo de búsqueda secuencial de un elemento "dato" en un vector "n"
  * @param n puntero al vector en el que se busca
  * @param tam tamaño del vector
  * @param dato Elemento que vamos a buscar en el vector
  * @return indice Devuelve el índice dónde se ha encontrado "dato"
  */
int busquedaSecuencial(int *n, int tam, int dato){
    bool encontrado=false;
    int indice=-1;
    for(int i=0; i<tam && !encontrado; i++){    //Se recorre el vector hasta que se encuentra el elemento o hasta el final
        if(n[i]==dato){     // Si el elemento de esta iteración es el elemento que se está buscando 
            encontrado=true;    // Se pone a true la variable booleana que controla si se ha encontrado o no...
            indice=i;           // Se actualiza el índice
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
