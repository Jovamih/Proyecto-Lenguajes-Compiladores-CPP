#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

struct Token{
    string type="";
    string value="";
};

class Tokenizer{
    private:
        int currentIndex=0;
        string possibleTokens="";
    public:
        Tokenizer(string);
        bool hasNextToken();
        Token nextToken();
};
Tokenizer:: Tokenizer(string token){
    possibleTokens=token;
   // cout<<token<<endl;
}
Token Tokenizer:: nextToken(){
    Token token;

    while(possibleTokens[currentIndex]==' ') currentIndex++; //anulamos los espacios en blanco
    char character=possibleTokens[currentIndex];
    if(character=='/'&&possibleTokens[currentIndex+1]=='/') currentIndex=possibleTokens.length();
    else
    if(isalpha(character)){
        while(isalpha(character) || isdigit(character) ){
            token.value+=character;
            currentIndex++;
            character=possibleTokens[currentIndex];
        }
        token.type="ID";
    }else if(isdigit(character)){
        while(isdigit(character)){
            token.value+=character;
            currentIndex++;
            character=possibleTokens[currentIndex];
        }
        token.type="NUM";
    }else if(string("{},;!%&/()=?*+-|<>").find(character)!=-1){
         token.value+=character;
         currentIndex++;
         char nextChar=possibleTokens.length()>currentIndex? possibleTokens[currentIndex]:'0';
         
         if((character=='+'&&(nextChar=='+' || nextChar=='=')) ||
           (character=='-' &&(nextChar=='-' || nextChar=='=')) ||
           (character=='='&&nextChar=='=') ||
           (character=='*'&&(nextChar=='*' || nextChar=='=')) ||
           (character=='/'&&nextChar=='=') ){
            
            token.value+=nextChar;
            currentIndex++;        
        }
        token.type="OP";
        //si existe un caracter que no se encuentra entre os valors verficados no se cuenta(Por ahora) 
    }else currentIndex++;
    return token;
} 
bool Tokenizer:: hasNextToken(){
    return possibleTokens.length()>currentIndex;
    //return currentIndex<0
}
