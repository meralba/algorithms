// Example program
#include <iostream>

using namespace std;
/** Devuelve el índice en el que se encuentra el elemento a buscar. Si devuelve -1 es que dicho elemento
 * no se encuentra en el vector
 * @pre El vector tiene que estar ordenado de menor a mayor
 * @param n
 * @param tam
 * @param dato
 **/
int busquedaBinaria(int *n, int tam, int dato){
    bool encontrado=false;
    int centro;
    int inf=0;
    int sup=tam-1;
    int indice=-1;
    while(inf<=sup && !encontrado){
        centro=((sup-inf)/2)+inf;
        if(n[centro]==dato){
            indice=centro;
            encontrado=true;
        }
        else{
            if(dato<n[centro]){
                sup=centro-1;
            }
            else{
                inf=centro+1;
            }
        }
    }
    
    return indice;
}


int main()
{
    int *n;
    int tam=10;
    int dato=8;
    
    n=new int[tam];
    n[0]=1;
    n[1]=2;
    n[2]=3;
    n[3]=4;
    n[4]=5;
    n[5]=6;
    n[6]=8;
    n[7]=9;
    n[8]=10;
    n[9]=11;
    
    int indice=busquedaBinaria(n,tam,dato);
    
    cout << "Encontrado elemento " << dato << " en la posicion " << indice;
    
}