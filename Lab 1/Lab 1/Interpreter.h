//
//  Interpreter.hpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#ifndef Interpreter_h
#define Interpreter_h

#include "Database.h"
#include "Relation.h"
#include "DatalogProgram.h"

#include <stdio.h>


class Interpreter {
public:
    Predicate temp;
    Interpreter(DatalogProgram &datalogProgram, Database &database);
    
    void PopulateRelations();
    void EvaluateQueries();
    void EvaluateRules();
    
    vector <string> GetRuleIDs(Rules* r) {
        vector <string> ruleID;
        for(int i = 0; i < r->body.size(); i++) {
            ruleID.push_back(r->body[i]->GetID());
        }
        return ruleID;
    }
    
    
    vector <int> GetDupeIndexes(string dupeChar, Rules* r) {
        vector<int> dupeIndexes;
        for(int i = 0; i < r->body.size(); i++) {
            for(int j = 0; j < r->body[i]->parameters.size(); j++) {
                if(dupeChar == r->body[i]->parameters[j]->GetParameter()) {
                    cout << "match found in bodyparams: " << dupeChar << ": " << j << endl;
                    dupeIndexes.push_back(j);
                }
            }
        }
        
        return dupeIndexes;
    }
    
    string DupeChar(Relation r) {
        size_t tempRelationSize = r.GetHeaderColumns().size();
        
        for(int i = 0; i < tempRelationSize; i++) {
            string toCheck = r.GetHeaderColumns();
            toCheck = toCheck[i];
            for(int j = (i + 1); j < tempRelationSize; j++) {
                string toCheckBeg = r.GetHeaderColumns();
                toCheckBeg = toCheckBeg[j];
                if(toCheck == toCheckBeg) {
                    return toCheck;
                }
            }
        }
        return "";
    }
    
    vector <Parameter*> PopulateHeaderBody(Rules* r) {
        vector <Parameter*> p;
        for(int i = 0; i < r->body.size(); i++) {
            for(int j = 0; j < r->body[i]->parameters.size(); j++) {
                p.push_back(r->body[i]->parameters[j]);
            }
        }
        
        return p;
    }
    
    Tuple IsJoinable(vector <string> ruleIDs, vector <int> dupeIndexes) {
        Predicate* p1 = nullptr;
        Predicate* p2 = nullptr;
        Tuple t;
        for(int i = 0; i < dlp->facts.size(); i++) {
            if(dlp->facts[i]->GetID() == ruleIDs[0]) {
                p1 = dlp->facts[i];
            }
            
            for(int j = (i + 1); j < dlp->facts.size(); j++) {
                if(dlp->facts[j]->GetID() == ruleIDs[1]) {
                    p2 = dlp->facts[j];
                }
                
                if(p1 == NULL || p2 == NULL) {
                    //do nothing
                } else {
                    if(p1->parameters[dupeIndexes[0]]->GetParameter() == p2->parameters[dupeIndexes[1]]->GetParameter()) {
                        cout << p1->parameters[dupeIndexes[0]]->GetParameter() << " :: " << p2->parameters[dupeIndexes[1]]->GetParameter() << endl;
                        cout << p1->GetParameters() << endl;
                        cout << p2->GetParameters() << endl;
                        t = CombineTuples(p1, p2);
                        return t;
                    }
                }
                
                
                
            }
        }
        
        return t;
    }
    
    Tuple CombineTuples(Predicate* p1, Predicate* p2) {
        vector <string> s;
        s.push_back(p1->parameters[0]->GetParameter());
        s.push_back(p1->parameters[1]->GetParameter());
        s.push_back(p2->parameters[0]->GetParameter());
        s.push_back(p2->parameters[1]->GetParameter());
        
        s.erase(unique(s.begin(),s.end()),s.end());
        
        Tuple tempTuple;
        for(int i = 0; i < s.size(); i++) {
            tempTuple.AddTuple(s[i]);
        }
        
        return tempTuple;
    }
    
    void UnionJoin(vector <string> ruleIDs, Relation &tempRelation) {
        for(int x = 0; x < ruleIDs.size(); x++) {
            for(int i = 0; i < dlp->facts.size(); i++) {
                Tuple t = Tuple();
                t.values.clear();
                if(dlp->facts[i]->GetID() == ruleIDs[x]) {
                    for(int j = 0; j < dlp->facts[i]->parameters.size(); j++) {
                        t.AddTuple(dlp->facts[i]->parameters[j]->GetParameter());
                    }
                    tempRelation.AddTuple(t);
                }
            }
        }
        
    }
    
    
    
    
    
    
    
private:
    DatalogProgram* dlp;
    Database* db;
};




#endif
