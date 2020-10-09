#ifndef Rule_h
#define Rule_h

#include <stdio.h>
#include <vector>
#include <sstream>
#include "Predicate.h"

class Rules {
public:
    
    Rules(Predicate *head, vector <Predicate*> inBody);
    string ToString();
    
    
private:
    Predicate *headPred;
    vector <Predicate*> body;
    stringstream buildS;
    
};

#endif
