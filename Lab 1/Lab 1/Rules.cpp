#include "Rules.h"

Rules::Rules(Predicate *head, vector <Predicate*> inBody) {
    headPred = head;
    body = inBody;
}


string Rules::ToString() {
    buildS.str("");
    
    buildS << "  ";
    buildS << headPred->GetID();
    buildS << "(";
    buildS << headPred->GetParameters();
    buildS << ")";
    buildS << " :- ";
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

