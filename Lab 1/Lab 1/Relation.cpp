//
//  Relation.cpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#include "Relation.h"

Relation::Relation(string s, Header h) {
    nameOfRelation = s;
    header = h;
}

void Relation::ToString() {
    cout << nameOfRelation << endl;
    for(int i = 0; i < header.namesOfColumns.size(); i++) {
        if(i == header.namesOfColumns.size() - 1) {
            cout << header.namesOfColumns[i];
        } else {
        cout << header.namesOfColumns[i] << " ";
        }
    }
    
    cout << endl;
    for(set<Tuple*>::iterator tupIT = tuples.begin(); tupIT != tuples.end(); tupIT++) {
        Tuple* t = *tupIT;
        t->ToString();
    }
   
    cout << endl << endl;
}

string Relation::GetRelationName() {
    return nameOfRelation;
}

void Relation::AddTuple(Tuple* t) {
    tuples.insert(t);
}


