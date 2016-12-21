/** Función recursiva para calcular todas las permutaciones posibles en una cadena dada
  * @author Mer Alba
  */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/** Función auxiliar para calcular las permutaciones.
  * @param c caracter que se va a introducir en cada posición del string s
  * @param s cadena en la que se va a introducir el caracter
  * @param salida almacena las permutaciones calculadas aquí
  */
void merge(char c, string s, vector<string>& salida){
    string cadena(s.length()+1,' ');    //Cadena en la que se va a ir almacenando las posibles permutaciones en cada iteración. Esta tiene tamaño tamaño de s + 1
    int cont=0; //Contador para guardar el índice por el que vamos actualizando la cadena de la permutación
    for(int i=0; i<cadena.length(); i++){   //Controla en que lugar almacenamos el carácter en cada iteración. Por cada iteración de esto sale una cadena distinta
        for(int j=0; j<cadena.length(); j++){   //Controla que elemento de la cadena s toca en cada iteración
            if(i==j){
                cadena[cont]=c;
            }
            else if(i<j){
                cadena[cont]=s[j-1]; 
            }
            else{
                cadena[cont]=s[j];
            }
            cont++;
        }
        salida.push_back(cadena);   //La cadena se almacena en el vector salida
        cont=0; //Se pone el contador a 0
    }
            
                
}

/** Función recursiva que calcula las permutaciones posibles en una cadena
  * @param cadena string al que se le van a calcular las permutaciones
  * @return salida vector de string con las cadenas permutadas
  */
vector<string> permutacion(string cadena){
    vector<string> salida;  //Se inicializan variables
    int tam=cadena.length();
    if(tam==1){     //Caso base: si la cadena tiene tamaño 1 se introduce en el vector de salida la cadena tal cuál
        salida.push_back(cadena);
    }
    else{       // Si no es caso base
        string aux;     //Variable auxiliar para almacenar los tam-1 primeros elementos de la cadena
        aux.assign (cadena, 0, tam-1);  
        vector<string> p = permutacion(aux);    //Va a contener las permutaciones posibles de la subcadena auxiliar
        for(int i=0; i<p.size(); i++){      //Por cada permutación de la cadena auxiliar
            merge(cadena[tam-1],p[i],salida);       //Se llama a merge con el último carácter y la subcadena. En salida se almacena el resultado de las permutaciones
        }
    }
    return salida;
}


int main()
{
    string s="abcd";
    
    vector<string> v=permutacion(s);
    cout << v.size() << " permutaciones" << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
}
