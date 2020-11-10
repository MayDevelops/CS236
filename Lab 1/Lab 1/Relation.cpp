//
//  Relation.cpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#include "Relation.h"
Relation::Relation() {
    //default
}

Relation::Relation(string s, vector <Parameter*> sc) {
    nameOfRelation = s;
    
    for(int i = 0; i < sc.size(); i++) {
        header.AddColumns(sc[i]->GetParameter());
    }
}

string Relation::ToString() {
    string s = "";
    for (set<Tuple*>::iterator setIT = tuples.begin(); setIT != tuples.end(); setIT++) {
        if(header.columns.size() == 0) {
            
        } else {
            s += "  ";
            s += (*setIT)->ToString(header.columns);
        }
    }
    
    return s;
}

string Relation::GetRelationName() {
    return nameOfRelation;
}

void Relation::AddTuple(Tuple* t) {
    tuples.insert(t);
}



Relation Relation::Select1(int index, string value){
    Relation temp;
    temp.header = header;
    temp.nameOfRelation = nameOfRelation;
    for (set<Tuple*>::iterator it = tuples.begin(); it != tuples.end(); it++) {
        if ((*it)->values[index] == value) {
            temp.AddTuple((*it));
        }
    }
    return temp;
}

Relation Relation::Select2(int index1, int index2) {
    Relation temp;
    temp.header = header;
    temp.nameOfRelation = nameOfRelation;
    for (set<Tuple*>::iterator it = tuples.begin(); it != tuples.end(); it++) {
        if ((*it)->values[index1] == (*it)->values[index2]) {
            temp.AddTuple((*it));
        }
    }
    
    return temp;
    
}

Relation Relation::Rename(int index, string value) {
    Relation temp;
    temp.header = header;
    temp.nameOfRelation = nameOfRelation;
    temp.tuples = tuples;
    temp.header.columns[index] = value;
    
    return temp;
}

Relation Relation::Project(vector <int> indexes) {
    Relation temp;
    temp.nameOfRelation = nameOfRelation;
    
    //Takes care of the header
    Header tempH;
    for (int i = 0; i < header.columns.size(); i++) {
        for(int j = 0; j < indexes.size(); j++) {
            if (indexes[j] == i) {
                tempH.AddColumns(header.columns[i]);
            }
        }
    }
    //Assigning the new header to the new Relation.
    temp.header = tempH;
    
    //Taking care of the tuples
    for (set<Tuple*>::iterator it = tuples.begin(); it != tuples.end(); it++) {
        Tuple* tempT = new Tuple;
        for (int i = 0; i < (*it)->values.size(); i++) {
            for (int j = 0; j < indexes.size(); j++) {
                if (indexes[j] == i) {
                    tempT->AddTuple((*it)->values[i]);
                }
            }
        }
        temp.AddTuple(tempT);
    }
    
    return temp;
}

