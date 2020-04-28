#include<iostream>
#include<string.h>
#include<cstdio>
#include<fstream>
#include<map>
#include<ctype.h>

using namespace std;

map<string,string> readTableOfSysmbols(string path){
    ifstream file(path);
    string line;
    map<string,string> tabla; //usamos un diccionario
    //file.open(path);
    if(file.is_open()){
       while(getline(file,line)){
           if(!line.empty()){
               string tipo=line.substr(0,line.find(":"));
               string valor=line.substr(line.find(":")+1,-1);
            tabla[tipo]=valor;
           }
       }
    }else{
        cout<<"No se encuentra el archivo de la tabla de simbolos";
    }
   // tabla.
    return tabla;
}

struct Token{
    string type;
    string value;
};

class Tokenizer{
    private:
        int currentIndex=0;
        string possibleTokens;
    public:
        Tokenizer(string);
        bool hasNextToken();
        Token nextToken();
};
Tokenizer:: Tokenizer(string token){
    possibleTokens=token;
}
Token Tokenizer:: nextToken(){
    Token token;
    char character=possibleTokens[currentIndex];
    if(isalpha(character)){
        while(isalpha(character) || isdigit(character) ){
            token.value+=character;
            character=possibleTokens[currentIndex];
            currentIndex++;
        }
        token.type="IDENTIFIER";
    }else if(isdigit(character)){
        while(isdigit(character)){
            token.value+=character;
            character=possibleTokens[currentIndex];
            currentIndex++;
        }
        token.type="NUMBER";
    }else if("");


    return ;
} 
bool Tokenizer:: hasNextToken(){
    if(possibleTokens.length()>currentIndex) return false;
    else return true;
    //return currentIndex<0
}
