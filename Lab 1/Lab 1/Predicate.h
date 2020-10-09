#ifndef Predicate_h
#define Predicate_h

#include <stdio.h>
#include <sstream>

#include "Parameter.h"

class Predicate {
public:
    ~Predicate();
    Predicate();
    Predicate(string s);
    
    void AddParameter(string s);
    string ToString();
    void SetClassification(char classification);
    string GetID();
    string GetParameters();
private:
    string ID;
    vector <Parameter*> parameters;
    stringstream buildS;
    char tokenClassification = '\a';
};
#endif
