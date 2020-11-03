#ifndef DatalogProgram_h
#define DatalogProgram_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#include "Predicate.h"
#include "Parameter.h"
#include "Rules.h"


using namespace std;

class DatalogProgram {
public:
    DatalogProgram();
    ~DatalogProgram();
    
    void ToString();
    void SetSchemes(Predicate* obj);
    void SetFacts(Predicate* obj);
    void SetQueries(Predicate* obj);
    void SetDomains(string s);
    void SetRules(Rules *obj);
    string RulesToString();


    vector <Predicate*> schemes;
    vector <Predicate*> facts;
    vector <Predicate*> queries;
    set <string> domains;
    vector <Rules*> rules;
};


#endif
