#include<iostream>
#include<string>
#include "utilities.h"
using namespace std;
int main(int argc, char **argv){

    if(argc<2){
        cout<<"Ingrese el texto a Scanear";
    }else{
       
           Tokenizer tokenizer(argv[1]);
            while(tokenizer.hasNextToken()){
                Token token= tokenizer.nextToken();
                cout<<token.type<<"\t"<<token.value<<endl;

             }
    }
    return 0;
}