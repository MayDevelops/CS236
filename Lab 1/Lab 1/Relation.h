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
    
    Relation();
    Relation(string s, vector <Parameter*> sc);
    
    string ToString();
    string GetRelationName();
    void AddTuple(Tuple t);
    Relation Select1(int index, string value);
    Relation Select2(int index1, int index2);
    Relation Rename(int index, string value);
    Relation Project(vector <unsigned int> index);
    
    
    string nameOfRelation = "";
    Header header;
    set <Tuple> tuples; 
};

#endif
