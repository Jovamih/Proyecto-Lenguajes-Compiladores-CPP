#include<iostream>
#include<string>
#include<fstream>
#include "utilities.h"

#define WORDS_SIZE 100
using namespace std;
void readReservedWords(string,string[]);
bool isReservedWord(string,string*);
int main(int argc, char **argv){
    if(argc<2){
        cout<<"Ingrese la ruta del programa fuente";
        return -1;
    }
    //1ero: leemos la ruta del archivo que tenemos que inspecionar
    fstream input(argv[1],ios::in);
    //preparamos las palabras reservadas que se encuentran en otro archivo txt
    string words[100]; //array de tokens leidos
    readReservedWords("Resources/wordsReserved.txt",words);
    //verificamos si se abrio correctamente
    if(input.is_open()){
         string line;
         //comenzamos a leer LINEA por LINEA
         while(getline(input,line,'\n')){
             //cada linea es asignada a una clase Token QUE SE ENCARAGRA DE PROESARLA Y DETERMINAR
             //cuantos Token  posee
             Tokenizer tokenizer(line);
                //mientras haya un Token disponile
                while(tokenizer.hasNextToken()){
                    //leemos el token
                    Token token= tokenizer.nextToken();
                    //SI el token devuelto no esta vacio, se procede a inspeccionar, en otro caso se ignora
                   if(!token.value.empty()){
                       //ademas si el token es de tipo 'ID' verficamos si perrtenece a una palabra reservada, y si no, pues lo omitimos
                        if(token.type=="ID"){
                            //si pertenece a una palabra reservada le cambiamos de tipo por un 'PR'
                          if(isReservedWord(token.value,words)) token.type="PR";
                    } 
                    cout<<token.type<<"\t"<<token.value<<endl; //mostramos los datos
                    }
                 }
                    
         }
         input.close();  
    }else{
        cout<<"No se puede acceder al archivo epecificado --argv[1]"<<endl;
    }
    return 0;
}
//Funcion que lee el archivo de palabras reservada y nos devuelve un array de String's
void readReservedWords(string pathDirectory,string data[]){
    fstream input(pathDirectory,ios::in);
    if(input.is_open()){
        string line;
        int currentIndex=0;
        while(getline(input,line,',')){
            data[currentIndex++]=line;
        }
        input.close();
    }else{
        cout<<"No se encuentra el archivo de palabras reservadas --> wordsReserved.txt";
    }
}
//Funcion que verifica si un determinado valor de Token es una Palabra reservada
bool isReservedWord(string value,string data[]){
    for(int i=0;i<WORDS_SIZE;i++){
        if(data[i]==value) return true;
    }
    return false;
}