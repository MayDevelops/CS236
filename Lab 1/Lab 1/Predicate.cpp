#include "Predicate.h"

Predicate::~Predicate() {
    for(unsigned int i = 0; i < parameters.size(); i++) {
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
        ss.str("");
    
        ss << "";
        ss << ID;
        ss << "(";
        for(unsigned int i = 0; i < parameters.size(); i++) {
            ss << parameters[i]->GetParameter();
            if(parameters[i]->GetParameter() == "(") continue;
            if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == "+") continue;
            if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == "*") continue;
            if(parameters[i]->GetParameter() == "+") continue;
            if(parameters[i]->GetParameter() == "*") continue;
            if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == ")") continue;
            if(i == parameters.size() - 1) {
                
            }else {
                ss << ",";
            }
        }
        ss << ")";
        
        return ss.str();
    } else if (tokenClassification == 'f') {
        ss.str("");
        
        ss << "";
        ss << ID;
        ss << "(";
        for(unsigned int i = 0; i < parameters.size(); i++) {
            ss << parameters[i]->GetParameter();
            if(parameters[i]->GetParameter() == "(") continue;
            if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == "+") continue;
            if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == "*") continue;
            if(parameters[i]->GetParameter() == "+") continue;
            if(parameters[i]->GetParameter() == "*") continue;
            if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == ")") continue;
            if(i == parameters.size() - 1) {
                
            }else {
                ss << ",";
            }
        }
        ss << ")";
        ss << ".";
        
        return ss.str();
    } else {
        ss.str("");
        
        ss << "";
        ss << ID;
        ss << "(";
        for(unsigned int i = 0; i < parameters.size(); i++) {
            ss << parameters[i]->GetParameter();
            if(parameters[i]->GetParameter() == "(") continue;
            if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == "+") continue;
            if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == "*") continue;
            if(parameters[i]->GetParameter() == "+") continue;
            if(parameters[i]->GetParameter() == "*") continue;
            if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == ")") continue;
            if(i == parameters.size() - 1) {
                
            }else {
                ss << ",";
            }
        }
        ss << ")";
        ss << "?";
        
        return ss.str();
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
    for(unsigned int i = 0; i < parameters.size(); i++) {
        
        s << parameters[i]->GetParameter();
        if(parameters[i]->GetParameter() == "(") continue;
        if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == "+") continue;
        if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == "*") continue;
        if(parameters[i]->GetParameter() == "+") continue;
        if(parameters[i]->GetParameter() == "*") continue;
        if(i != parameters.size() - 1 && parameters[i + 1]->GetParameter() == ")") continue;
        if(i == parameters.size() - 1) {
            
        }else {
            s << ",";
        }
    }
    return s.str();
}
