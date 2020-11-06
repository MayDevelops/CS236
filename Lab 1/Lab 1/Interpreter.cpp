//
//  Interpreter.cpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram &datalogProgram, Database &database){
    dlp = &datalogProgram;
    db = &database;
    
    PopulateRelations();
}



void Interpreter::PopulateRelations() {
    
    cout << endl << "Inside PopulateRelations..." << endl;
    
    for(int i = 0; i < dlp->schemes.size(); i++) {
        cout << "Creating Relation object..." << endl;
        Relation* relation = new Relation(dlp->schemes[i]->GetID(), dlp->schemes[i]->parameters);
        cout << "Adding relation object to DB Map..." << endl;
        db->AddToMap(relation->GetRelationName(), relation);
        
        //Facts
        for(vector <Predicate*>::iterator factsIT = dlp->facts.begin(); factsIT != dlp->facts.end(); factsIT++) {
            Tuple t;
            for(vector<Parameter*>::iterator paramIT = (*factsIT)->parameters.begin(); paramIT != (*factsIT)->parameters.end(); paramIT++) {
                t.AddTuple((*paramIT)->GetParameter());
            }
            for(map <string, Relation*>::iterator mapIT = db->database.begin(); mapIT != db->database.end(); mapIT++) {
                if((*mapIT).first == (*factsIT)->GetID()) {
                    Relation* rel = db->database[(*factsIT)->GetID()];
                    rel->AddTuple(t);
                }
            }
        }
//        cout << "Calling Relation ToString..." << endl;
//        relation->ToString();
//
    }
}

void Interpreter::EvaluateQueries() {
    for (vector<Predicate*>::iterator it2 = dlp->queries.begin(); it2 != dlp->queries.end(); it2++) {
        Relation r = EvaluatePredicate((*it2));
        
        string out = (*it2)->ToString() + " ";
        int size = 0;
        for (set<Tuple>::iterator it = r.tuples.begin(); it != r.tuples.end(); it++) {
            size++;
        }
        if (size == 0) {
            out += "No\n";
        } else {
            out += "yes(" + to_string(size) + ")\n";
        }
        
        bool allConst = true;
        for (vector <Parameter*>::iterator it3 = (*it2)->parameters.begin(); it3 != (*it2)->parameters.end(); it3++) {
            if ((*it3)->isConstant() != true) {
                allConst = false;
                break;
            }
        }
        
        if (!allConst) {
            out += r.ToString();
        }
        cout << out;
    }
}

Relation Interpreter::EvaluatePredicate(Predicate* p) {
    Relation rel = *(db->database[p->GetID()]);
    map<int,string> vm;
    int i = 0;
    int j = 0;
    
    for(vector <Parameter*>::iterator it = p->parameters.begin(); it != p->parameters.end(); it++) {
        if ((*it)->isConstant() == true) {
            rel = *(rel.select1(&rel, i, (*it)->GetParameter()));
        } else {
            bool seenIt = false;
            for (map<int,string>::iterator it3 = vm.begin(); it3 != vm.end(); it3++) {
                if ((it3)->second == (*it)->GetParameter()) {
                    seenIt = true;
                    j = (*it3).first;
                    break;
                }
            }
            
            if (!seenIt) {
                vm.insert(pair<int, string>(i, (*it)->GetParameter()));
            } else {
                rel = *(rel.select2(&rel, i, j));
            }
        }
        i++;
    }
    
    vector<int> pos;
    vector<string> newHeaderVals;
    for (map<int, string>::iterator it = vm.begin(); it != vm.end(); it++) {
        pos.push_back((*it).first);
        newHeaderVals.push_back((*it).second);
    }
    rel = *(rel.project(&rel, pos));
    rel = *(rel.rename(&rel, newHeaderVals));
    
    return rel;
}


