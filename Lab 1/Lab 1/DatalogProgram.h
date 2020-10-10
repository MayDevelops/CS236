#ifndef DatalogProgram_h
#define DatalogProgram_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>

#include "Predicate.h"
#include "Parameter.h"
#include "Rules.h"


using namespace std;

class DatalogProgram {
public:
    ~DatalogProgram();
    
    void ToString(ofstream &outFile);
    void SetSchemes(Predicate* obj);
    void SetFacts(Predicate* obj);
    void SetQueries(Predicate* obj);
    void SetDomains(string s);
    void SetRules(Rules *obj);
    string RulesToString();
    void Temp() {
        for(int i = 0 ;i < rules.size(); i++) {
            cout << rules[i]->ToString() << endl;
        }
    }
    
    
    
private:
    vector <Predicate*> schemes;
    vector <Predicate*> facts;
    vector <Predicate*> queries;
    set <string> domains;
    vector <Rules*> rules;
    
    string tempString = "";
    stringstream buildS;
    
    
};


#endif
