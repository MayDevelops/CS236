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

#include "Predicate.h"
#include "Tuple.h"
#include "Header.h"


using namespace std;

class Relation {
public:
    
    Relation(string s, vector <Parameter*> sc);
    
    string ToString();
    string GetRelationName();
    void AddTuple(Tuple t);
    Relation* project(Relation* rel, vector<int> pos);
    Relation* rename(Relation* rel, vector<string> newHeader);
    Relation* select2(Relation* rel, int index1, int index2);
    Relation* select1(Relation* rel, int index, string value);
    
    
    string nameOfRelation = "";
    Header header;
    set <Tuple> tuples;
   
    
    
};

#endif
