//
//  Relation.hpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#ifndef Relation_h
#define Relation_h

#include <stdio.h>
#include <set>
#include <string>
#include <map>
#include <algorithm>


#include "Predicate.h"
#include "Tuple.h"
#include "Header.h"
#include "Rules.h"

using namespace std;

class Relation {
public:
    
    Relation();
    Relation(string s) {
        nameOfRelation = s;
    }
    Relation(string s, vector <Parameter*> sc);
    
    string ToString();
    string GetRelationName();
    void AddTuple(Tuple t);
    Relation Select1(unsigned int index, string value);
    Relation Select2(unsigned int index1, unsigned int index2);
    Relation Rename(unsigned int index, string value);
    Relation Project(vector <unsigned int> index);
    

    
    void Project1(vector <unsigned int> pos) {
        set <Tuple> newTuples;
        vector <string> newAttributes;
        
        for(vector<unsigned int>::iterator it = pos.begin(); it != pos.end(); it++) {
            newAttributes.push_back(this->header.columns.at((*it)));
        }
        
        for (set<Tuple>::iterator it2 = this->tuples.begin(); it2 != this->tuples.end(); it2++) {
            Tuple tuple = Tuple();
            Tuple t = (*it2);
            for(vector<unsigned int>::iterator it3 = pos.begin(); it3 != pos.end(); it3++) {
                if((*it3) > (*it2).values.size() - 1) {
                    //do nothing
                } else {
                string s = (*it2).values.at(*it3);
                tuple.AddTuple(s);
                }
            }
            newTuples.insert(tuple);
        }
        
        this->header.columns = newAttributes;
        this->tuples = newTuples;
        
        
    }
    
    /*
     for(unsigned int i = 0; i < pos.size(); i++) {
         string s = (*it2).values[i];
         tuple.AddTuple(s);
     }
     */
    
    
    void Union(Relation t) {
        for(set <Tuple>::iterator it = t.tuples.begin(); it != t.tuples.end(); it++) {
            if (this->tuples.insert((*it)).second == true) { //if it's new
                Tuple t = (*it);
                cout << t.ToString(header.columns);
            }
            this->AddTuple((*it));
        }
    }
    
    
    
    Relation Join(Relation r1, Relation r2) {
        Relation r;
        r.header = CombineHeader(r1, r2);
        
        for(set<Tuple>::iterator it1 = r1.tuples.begin(); it1 != r1.tuples.end(); it1++) {
            for(set<Tuple>::iterator it2 = r2.tuples.begin(); it2 != r2.tuples.end(); it2++) {
                if(IsJoinable((*it1), (*it2))) {
                    r.AddTuple(CombineTuples((*it1), (*it2)));
                }
            }
        }
        return r;
    }
    
    Header CombineHeader(Relation r1, Relation r2) {
        Header h;
        bool matchFound = false;
        
        for(unsigned int i = 0; i < r1.header.columns.size(); i++) {
            h.AddColumns(r1.header.columns[i]);
        }
        for(unsigned int j = 0; j < r2.header.columns.size(); j++) {
            matchFound = false;
            for(unsigned int k = 0; k < r1.header.columns.size(); k++) {
                if(r1.header.columns[k] == r2.header.columns[j]) {
                    matching.insert(pair<unsigned int,unsigned int>(k,j));
                    matchFound = true;
                    break;
                }
            }
            if(!matchFound) {
                h.AddColumns(r2.header.columns[j]);
            }
            
        }
        //header.columns.erase(unique(header.columns.begin(),header.columns.end()),header.columns.end());
        
        h.columns.erase(unique(h.columns.begin(), h.columns.end()), h.columns.end());
        
        
        
        return h;
    }
    
    void ChangeHeader(vector <Parameter*> s) {
        Header h;
        for(unsigned int i = 0; i < s.size(); i++) {
            h.AddColumns(s[i]->GetParameter());
        }
        header = h;
    }
    
    bool IsJoinable(Tuple t1, Tuple t2) {
        bool joinable = true;
        
        for(map<unsigned int,unsigned int>::iterator it = matching.begin(); it != matching.end(); it++) {
            if(t1.values[it->first] != t2.values[it->second]) {
                joinable = false;
            }
        }
        return joinable;
    }
    
    Tuple CombineTuples(Tuple t1, Tuple t2) {
        Tuple tempTuple;
        
        for(unsigned int i = 0; i < t1.values.size(); i++) {
            tempTuple.AddTuple(t1.values[i]);
        }
        
        
        for(unsigned int j = 0; j < t2.values.size(); j++) {
            bool found = false;
            for(map<unsigned int,unsigned int>::iterator it = matching.begin(); it != matching.end(); it++) {
                if(it->second == j) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                tempTuple.AddTuple(t2.values[j]);
            }
        }
        return tempTuple;
    }
    
    
    map <unsigned int,unsigned int> matching;
    string nameOfRelation = "";
    Header header;
    set <Tuple> tuples;
    
};






#endif
