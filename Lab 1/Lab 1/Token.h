#ifndef Token_h
#define Token_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

enum TokenType {COMMA = 0, PERIOD = 1, Q_MARK = 2, LEFT_PAREN = 3, RIGHT_PAREN = 4, COLON = 5, COLON_DASH = 6, MULTIPLY = 7, ADD = 8, SCHEMES = 9, FACTS = 10, RULES = 11, QUERIES = 12, ID = 13, STRING = 14, COMMENT = 15, UNDEFINED = 16, END = 17};

class Token {
public:
    
    Token();
    Token(int tokenID, string value, int line);
    
    void Print();
    void EnumToString(int enumValue);
    
    string GetID();
    string GetValue();
    int GetLine();
    void Get();
private:
    
    string stringValue = "";
    string enumString = "";
    int lineNumber = 0;
    
};

#endif
