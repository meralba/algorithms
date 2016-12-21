// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(char c, string s, vector<string>& salida){
    string cadena(s.length()+1,' ');
    int cont=0;
    for(int i=0; i<cadena.length(); i++){
        for(int j=0; j<cadena.length(); j++){
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
        salida.push_back(cadena);
        cont=0;
    }
            
                
}

vector<string> permutacion(string cadena){
    vector<string> salida;
    int tam=cadena.length();
    if(tam==1){
        salida.push_back(cadena);
    }
    else{
        string aux;
        aux.assign (cadena, 0, tam-1);
        vector<string> p = permutacion(aux);
        for(int i=0; i<p.size(); i++){
            merge(cadena[tam-1],p[i],salida);
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