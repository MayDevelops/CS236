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
    Tokenizer(string inFile);
    ~Tokenizer();
    void ParseFileInput(string inFile);
    string PrintChars(vector <char> chars);
    bool CheckCharApproval(char c);
    vector <Token*> GetTokens();
    
private:
    vector <Token*> tokens;
};

#endif
