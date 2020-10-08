#ifndef Tokenizer_h
#define Tokenizer_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Token.h"

using namespace std;

class Tokenizer {
public:
    
    Tokenizer();
    Tokenizer(string inFile, ofstream &outFile);
    ~Tokenizer();
    void ParseFileInput(string inFile, ofstream &outFile);
    string PrintChars(vector <char> chars);
    bool CheckCharApproval(char c);
    vector <Token*> GetTokens();
    
private:
    vector <Token*> tokens;
};

#endif
