#include<iostream>
#include<string>
#include<fstream>
#include "utilities.h"
using namespace std;
void readTokenLine(string);
int main(int argc, char **argv){
    if(argc<2){
        cout<<"Ingrese el texto a Scanear";
        return -1;
    }
    fstream input(argv[1],ios::in);
    if(input.is_open()){
         string line;
         while(getline(input,line)){
             readTokenLine(line);
         }
    }else{
        cout<<"No se puede acceder al archivo epecificado --argv[1]"<<endl;
    }
    return 0;
}
void readTokenLine(string token){
    Tokenizer tokenizer(token);
        while(tokenizer.hasNextToken()){
            Token token= tokenizer.nextToken();
            cout<<token.type<<"\t"<<token.value<<endl;
         }  
}