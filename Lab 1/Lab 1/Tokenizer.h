#ifndef Tokenizer_h
#define Tokenizer_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <sstream>

#include "Token.h"


using namespace std;

class Tokenizer {
public:
    
    Tokenizer();
    
    //FIXME::not sure what arguments this needs yet
    Tokenizer(string inFile, ofstream &outFile);
    
    //FIXME:: not sure what return type this is yet
    void GetNextToken();
    
    void ParseFileInput(string inFile, ofstream &outFile);
    string PrintChars(vector <char> chars);
    bool CheckCharApproval(char c);
    
    
private:
    vector <Token*> tokens;
};





#endif /* Tokenizer_hpp */



/*
[x]send in the string from the lexer.
 
 [in progress]check the string to see if it makes a token.
 
 This is where the token objects are made, this will be done in getNextToken(); 
 
 keep track of line number and index of next char.
 
 
 
 
 
 */
