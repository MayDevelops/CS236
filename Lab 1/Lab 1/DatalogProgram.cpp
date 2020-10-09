#include "DatalogProgram.h"

DatalogProgram::~DatalogProgram(){
    for(int i = 0; i < schemes.size(); i++) {
        delete schemes[i];
    }
    schemes.clear();
    
    for(int i = 0; i < facts.size(); i++) {
        delete facts[i];
    }
    facts.clear();
    
    for(int i = 0; i < queries.size(); i++) {
        delete queries[i];
    }
    queries.clear();
    
    for(int i = 0; i < rules.size(); i++) {
        delete rules[i];
    }
    rules.clear();
}

void DatalogProgram::ToString(ofstream &outFile) {
    outFile << "Schemes(" << schemes.size() << "):" << endl;
    for(int i = 0; i < schemes.size(); i++) {
        outFile << schemes[i]->ToString() << endl;
    }
    outFile << "Facts(" << facts.size() << "):" << endl;
    for(int i = 0; i < facts.size(); i++) {
        outFile << facts[i]->ToString() << endl;
    }
    outFile << "Rules(" << rules.size() << "):" << endl;
    for(int i = 0; i < rules.size(); i++) {
        outFile << rules[i]->ToString() << endl;
    }
    outFile << "Queries(" << queries.size() << "):" << endl;
    for(int i = 0; i < queries.size(); i++) {
        outFile << queries[i]->ToString() << endl;
    }
    outFile << "Domain(" << domains.size() << "):" << endl;
    set <string>::iterator it;
    for(it = domains.begin(); it != domains.end(); it++) {
        outFile << "  " << (*it) << endl;
    }
    
    /*
     cout << "Schemes(" << schemes.size() << "):" << endl;
     for(int i = 0; i < schemes.size(); i++) {
     cout << schemes[i]->ToString() << endl;
     }
     cout << "Facts(" << facts.size() << "):" << endl;
     for(int i = 0; i < facts.size(); i++) {
     cout << facts[i]->ToString() << endl;
     }
     
     cout << "Rules(" << rules.size() << "):" << endl;
     for(int i = 0; i < rules.size(); i++) {
     cout << rules[i]->ToString() << endl;
     }
     
     cout << "Queries(" << queries.size() << "):" << endl;
     for(int i = 0; i < queries.size(); i++) {
     cout << queries[i]->ToString() << endl;
     }
     
     cout << "Domain(" << domains.size()  << "):" << endl;
     set <string>::iterator it2;
     for(it2 = domains.begin(); it2 != domains.end(); it2++) {
     cout << "  " << (*it2) << endl;
     }
     */
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
