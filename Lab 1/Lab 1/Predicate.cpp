#include "Predicate.h"

Predicate::~Predicate() {
    for(int i = 0; i < parameters.size(); i++) {
        delete parameters[i];
    }
    parameters.clear();
}

Predicate::Predicate() {
    //default
}
Predicate::Predicate(string s) {
    ID = s;
}

void Predicate::AddParameter(string s) {
    parameters.push_back(new Parameter(s));
}

string Predicate::ToString() {
    if(tokenClassification == 's') {
        buildS.str("");
        
        buildS << "  ";
        buildS << ID;
        buildS << "(";
        for(int i = 0; i < parameters.size(); i++) {
            buildS << parameters[i]->GetParameter();
            if(i == parameters.size() - 1) {
                
            }else {
                buildS << ",";
            }
        }
        buildS << ")";
        
        return buildS.str();
    } else if (tokenClassification == 'f') {
        buildS.str("");
        
        buildS << "  ";
        buildS << ID;
        buildS << "(";
        for(int i = 0; i < parameters.size(); i++) {
            buildS << parameters[i]->GetParameter();
            if(i == parameters.size() - 1) {
                
            }else {
                buildS << ",";
            }
        }
        buildS << ")";
        buildS << ".";
        
        return buildS.str();
    } else {
        buildS.str("");
        
        buildS << "  ";
        buildS << ID;
        buildS << "(";
        for(int i = 0; i < parameters.size(); i++) {
            buildS << parameters[i]->GetParameter();
            if(i == parameters.size() - 1) {
                
            }else {
                buildS << ",";
            }
        }
        buildS << ")";
        buildS << "?";
        
        return buildS.str();
    }
}

void Predicate::SetClassification(char classification) {
    tokenClassification = classification;
}

string Predicate::GetID(){
    return ID;
}
string Predicate::GetParameters(){
    stringstream s;
    for(int i = 0; i < parameters.size(); i++) {
        s << parameters[i]->GetParameter();
        if(i == parameters.size() - 1) {
            
        }else {
            s << ",";
        }
    }
    return s.str();
}
