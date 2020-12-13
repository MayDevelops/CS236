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
    Relation Select1(int index, string value);
    Relation Select2(int index1, int index2);
    Relation Rename(int index, string value);
    Relation Project(vector <unsigned int> index);
    
    string GetHeaderColumns() {
        string returnString = "";
        for(int i = 0; i < header.columns.size(); i++) {
            returnString += header.columns[i];
        }
        return returnString;
    }
    
    void MakeHeaderUnique() {
        header.columns.erase(unique(header.columns.begin(),header.columns.end()),header.columns.end());
    }
    
    void Project(string a, string b) {
        for(int i = 0; i < header.columns.size(); i++) {
            if(header.columns[i] == a || header.columns[i] == b) {
                //keep the header coulmn
            } else {
                //delete the column
                header.columns.erase(header.columns.begin() + i);
                for(set <Tuple>::iterator it = tuples.begin(); it != tuples.end(); it++) {
                    Tuple tempT = *it;
                    for(int j = 0; j < tempT.values.size(); j++) {
                        if(j == i) {
                            tempT.values.erase(tempT.values.begin() + i);
                        }
                    }
                    tempT.PrintValues();
                    tuples.erase(it);
                    tuples.insert(tempT);
                }
            }
        }
    }
    
    void Rename(string a, string b, string c) {
        nameOfRelation = c;
        header.columns[0] = a;
        header.columns[1] = b;
    }
    
    
    void PrintAllDetails(Rules* r) {
        cout << "***************" << endl;
        cout << nameOfRelation << endl;
        cout << header.PrintColumns() << endl;
        for(set <Tuple>::iterator it = tuples.begin(); it != tuples.end(); it++) {
            Tuple tempT = *it;
            for(int i = 0; i < 2; i++) {
                if(i % 2 != 0) {
                    cout << header.columns[i] << "=" << tempT.values[i];
                } else {
                    cout << header.columns[i] << "=" << tempT.values[i] << ", ";
                }
                
            }
            cout << endl;
            
            //tempT.PrintValues();
        }
        cout << "***************" << endl;
        
    }
    
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
        
        for(int i = 0; i < r1.header.columns.size(); i++) {
            h.AddColumns(r1.header.columns[i]);
        }
        for(int j = 0; j < r2.header.columns.size(); j++) {
            for(int k = 0; k < r1.header.columns.size(); k++) {
                if(r1.header.columns[k] == r2.header.columns[j]) {
                    matching.insert(pair<int,int>(k,j));
                }
            }
            h.AddColumns(r2.header.columns[j]);
        }
        //header.columns.erase(unique(header.columns.begin(),header.columns.end()),header.columns.end());
        
        h.columns.erase(unique(h.columns.begin(), h.columns.end()), h.columns.end());
        
        return h;
    }
    
    void ChangeHeader(vector <Parameter*> s) {
        Header h;
        for(int i = 0; i < s.size(); i++) {
            h.AddColumns(s[i]->GetParameter());
        }
        header = h;
    }
    
    bool IsJoinable(Tuple t1, Tuple t2) {
        bool joinable = true;
        
        for(map<int,int>::iterator it = matching.begin(); it != matching.end(); it++) {
            if(t1.values[it->first] != t2.values[it->second]) {
                joinable = false;
            }
        }
        return joinable;
    }
    
    Tuple CombineTuples(Tuple t1, Tuple t2) {
        Tuple tempTuple;
        
        for(int i = 0; i < t1.values.size(); i++) {
            tempTuple.AddTuple(t1.values[i]);
        }
        
        
        for(int j = 0; j < t2.values.size(); j++) {
            bool found = false;
            for(map<int,int>::iterator it = matching.begin(); it != matching.end(); it++) {
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
    
    
    map <int,int> matching;
    string nameOfRelation = "";
    Header header;
    set <Tuple> tuples;
    
};






#endif
