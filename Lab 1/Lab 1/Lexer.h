#ifndef Lexer_h
#define Lexer_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Tokenizer.h"

using namespace std;

class Lexer {
public:
    
    Lexer(string inFile, ofstream &outFile);
    vector <Token> GetTokens();
    
private:
    vector <Token> tokens;
};

#endif
