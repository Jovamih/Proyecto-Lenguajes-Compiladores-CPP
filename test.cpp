#include<iostream>
#include<fstream>
#include<string>
#include "utilities.h"
using namespace std;
int main(int argc, char **argv){

    if(argc<2){
        cout<<"Ingrese la ruta del archivo";
    }else{
        string line;
        ifstream data(argv[1]);
        while(getline(data,line)){
            Tokenizer tokenizer(line);
            while(tokenizer.hasNextToken()){
                Token token= tokenizer.nextToken();
                cout<<token.type<<"\t"<<token.value<<endl;
            }
            
        }

    }

    return 0;
}