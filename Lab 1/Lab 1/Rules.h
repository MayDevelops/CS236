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
    string RulesEvaluationToString() {
        buildS.str("");
        buildS << headPred->GetID();
        buildS << "(";
        buildS << headPred->GetParameters();
        buildS << ") :- ";
        for(unsigned int i = 0; i < body.size(); i++) {
            buildS << body[i]->GetID();
            buildS << "(";
            buildS << body[i]->GetParameters();
            buildS << ")";
            if(i != body.size() - 1) {
                buildS << ",";
            }
        }
        buildS << ".";
        
        return buildS.str();
    }
    
    

    Predicate *headPred;
    vector <Predicate*> body;
    stringstream buildS;
    
};

#endif
