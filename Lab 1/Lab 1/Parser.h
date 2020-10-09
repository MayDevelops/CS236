#ifndef Parser_h
#define Parser_h

#include "Token.h"
#include "DatalogProgram.h"
#include "Predicate.h"

#include <stdio.h>
#include <vector>

class Parser {
public:
    Parser(vector <Token> tokensIn, DatalogProgram &datalogProgram);
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
    bool Predicates(int &index);
    bool PredicateList(int &index);
    bool ParameterList(int &index);
    bool StringList(int &index);
    bool IDList(int &index);
    bool Parameter(int &index);
    bool Expression(int &index);
    bool Operator(int &index);
    
    void ReturnFailure(ofstream &outFile);
    
private:
    vector <Token> tokens;
    int index = 0;
    vector <Predicate*> predicateContainer;
    DatalogProgram *dlp = NULL;
    Predicate* tempHeadPred = NULL;
    bool headPred;
};

#endif
