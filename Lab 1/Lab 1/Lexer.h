#ifndef Lexer_h
#define Lexer_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

#include "Tokenizer.h"

using namespace std;


/*
 [x]reads the string.
 
 [x]Tokenizer object is made in the Lexer.
 
 [in progress]tokenizer.getNextToken();
 
 store the tokens from tokenizer in a vector.
 
 function that returns all the tokens in the vector, to main.
 */

class Lexer {
public:

    Lexer(string inFile, ofstream &outFile);
    
private:
    vector <Token*> tokens;
};










#endif
