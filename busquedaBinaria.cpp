/** Función secuencial para la busqueda binaria de un elemento en un vector
  * @author Mer Alba
  */
#include <iostream>

using namespace std;
/** Devuelve el índice en el que se encuentra el elemento a buscar. Si devuelve -1 es que dicho elemento
 * no se encuentra en el vector
 * @pre El vector tiene que estar ordenado de menor a mayor
 * @param n Vector en el que se va a buscar
 * @param tam Tamaño del vector
 * @param dato Dato que se va a buscar en el vector
 * @return indice Indice dónde se ha encontrado el elemento buscado
 **/
int busquedaBinaria(int *n, int tam, int dato){
    bool encontrado=false;  //Variable que controla si el elemento ha sido encontrado o no (vale con la variable indice) 
    int centro;     //Elemento pivote. Siempre será el centro del vector
    int inf=0;      //Elemento inferior del intervalo inspeccionado
    int sup=tam-1;  //Elemento superior del intervalo inspeccionado
    int indice=-1;  
    while(inf<=sup && !encontrado){     // indice==-1
        centro=((sup-inf)/2)+inf;   //Cálculo del centro del intervalo
        if(n[centro]==dato){    //Si el elemnto pivote es el mismo que el elemento buscado se devuelve el índice de este
            indice=centro;
            encontrado=true;
        }
        else{       //Si no se modifican los límites para la próxima iteración
            if(dato<n[centro]){     //Si el dato es menor al elemento pivote
                sup=centro-1;       //El límite superior se pone a la izquierda del pivote
            }
            else{           //Si no
                inf=centro+1;       //El limite inferior se situa al lado derecho del pivote 
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
