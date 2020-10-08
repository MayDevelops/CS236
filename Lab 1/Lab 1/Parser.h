#ifndef Parser_h
#define Parser_h

#include "Token.h"

#include <stdio.h>
#include <vector>

class Parser {
public:
    Parser(vector <Token> tokensIn);
    bool Parse();
    bool SchemeList(int &index);
    bool FactList(int &index);
    bool RuleList(int &index);
    bool QueryList(int &index);
    bool Scheme(int &index);
    bool Fact(int &index);
    bool Rule(int &index);
    bool Query(int &index);
    bool HeadPredicate(int &index);
    bool Predicate(int &index);
    bool PredicateList(int &index);
    bool ParameterList(int &index);
    bool StringList(int &index);
    bool IDList(int &index);
    bool Parameter(int &index);
    bool Expression(int &index);
    bool Operator(int &index);

private:
    vector <Token> tokens;
};

#endif
