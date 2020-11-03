#include "DatalogProgram.h"
DatalogProgram::DatalogProgram() {
    //default constructor
}

DatalogProgram::~DatalogProgram(){
    for(unsigned int i = 0; i < schemes.size(); i++) {
        delete schemes[i];
    }
    schemes.clear();
    
    for(unsigned int i = 0; i < facts.size(); i++) {
        delete facts[i];
    }
    facts.clear();
    
    for(unsigned int i = 0; i < queries.size(); i++) {
        delete queries[i];
    }
    queries.clear();
    
    for(unsigned int i = 0; i < rules.size(); i++) {
        delete rules[i];
    }
    rules.clear();
}

void DatalogProgram::ToString() {
    cout << "Schemes(" << schemes.size() << "):" << endl;
    for(unsigned int i = 0; i < schemes.size(); i++) {
        cout << schemes[i]->ToString() << endl;
    }
    cout << "Facts(" << facts.size() << "):" << endl;
    for(unsigned int i = 0; i < facts.size(); i++) {
        cout << facts[i]->ToString() << endl;
    }
    
    cout << "Rules(" << rules.size() << "):" << endl;
    for(unsigned int i = 0; i < rules.size(); i++) {
        cout << rules[i]->ToString() << endl;
    }
    
    cout << "Queries(" << queries.size() << "):" << endl;
    for(unsigned int i = 0; i < queries.size(); i++) {
        cout << queries[i]->ToString() << endl;
    }
    
    cout << "Domain(" << domains.size()  << "):" << endl;
    set <string>::iterator it2;
    for(it2 = domains.begin(); it2 != domains.end(); it2++) {
        cout << "  " << (*it2) << endl;
    }
}

void DatalogProgram::SetSchemes(Predicate *obj) {
    schemes.push_back(obj);
}

void DatalogProgram::SetFacts(Predicate *obj) {
    facts.push_back(obj);
}

void DatalogProgram::SetQueries(Predicate *obj) {
    queries.push_back(obj);
}

void DatalogProgram::SetDomains(string s) {
    domains.insert(s);
}

void DatalogProgram::SetRules(Rules *obj) {
    rules.push_back(obj);
}
