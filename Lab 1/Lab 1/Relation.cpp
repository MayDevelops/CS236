//
//  Relation.cpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#include "Relation.h"

Relation::Relation(string s, vector <Parameter*> sc) {
    nameOfRelation = s;
    
    for(int i = 0; i < sc.size(); i++) {
        header.AddColumns(sc[i]->GetParameter());
    }
}

string Relation::ToString() {
    string returnVal;
    
    vector<Tuple> v1;
    copy(tuples.begin(), tuples.end(), back_inserter(v1));
    
    for (vector<Tuple>::iterator it = v1.begin(); it != v1.end(); it++) {
        returnVal += " ";
        returnVal += (it)->ToString();
    }
    
    return returnVal;
}

string Relation::GetRelationName() {
    return nameOfRelation;
}

void Relation::AddTuple(Tuple t) {
    tuples.insert(t);
}


Relation* Relation::project(Relation* rel, vector<int> pos){
    set<Tuple> newTuples;
    vector <string> newAttributes;
    
    for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {
        newAttributes.push_back(rel->header.attributes[(*it)]);
    }
    
    for (set<Tuple>::iterator it2 = rel->tuples.begin(); it2 != rel->tuples.end(); it2++) {
        Tuple tuple;
        for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {
            tuple.AddTuple((*it2).values[(*it)]);
        }
        newTuples.insert(tuple);
    }
    rel->header.attributes = newAttributes;
    rel->tuples = newTuples;
    return rel;
}

Relation* Relation::rename(Relation* rel, vector<string> newHeader) {
    vector <string> newAttributes;
    
    for(int i = 0; i < newHeader.size(); i++) {
        newAttributes.push_back(newHeader[i]);
    }
    
    rel->header.attributes = newAttributes;
    return rel;
}

Relation* Relation::select2(Relation* rel, int index1, int index2) {
    set<Tuple> newTuples;
    for (set<Tuple>::iterator it = rel->tuples.begin(); it != rel->tuples.end(); it++) {
        if ((*it).values[index1] == (*it).values[index2]) {
            newTuples.insert((*it));
        }
    }
    rel->tuples = newTuples;
    return rel;
}

Relation* Relation::select1(Relation* rel, int index, string value) {
    set<Tuple> newTuples;
    for (set<Tuple>::iterator it = rel->tuples.begin(); it != rel->tuples.end(); it++) {
        if ((*it).values[index] == value) {
            newTuples.insert((*it));
        }
    }
    
    rel->tuples = newTuples;
    return rel;
}
