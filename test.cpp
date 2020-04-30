#include<iostream>
#include<string>
#include<fstream>
#include "utilities.h"
using namespace std;
void readReservedWords(string,string[]);
bool isReservedWord(string,string*);
int main(int argc, char **argv){
    if(argc<2){
        cout<<"Ingrese el texto a Scanear";
        return -1;
    }
    fstream input(argv[1],ios::in);
    string words[100];
    readReservedWords("Resources/wordsReserved.txt",words);
    if(input.is_open()){
         string line;
         while(getline(input,line)){
             Tokenizer tokenizer(line);
                while(tokenizer.hasNextToken()){
                    Token token= tokenizer.nextToken();
                    if(token.type=="ID"){
                        if(isReservedWord(token.value,words)) token.type="PR";
                    }
                    cout<<token.type<<"\t"<<token.value<<endl;
                }
         }
         input.close();
    }else{
        cout<<"No se puede acceder al archivo epecificado --argv[1]"<<endl;
    }
    return 0;
}

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
bool isReservedWord(string value,string * data){
    for(int i=0;data!=NULL;i++){
        if(data[i]==value) return true;
    }
    return false;
}