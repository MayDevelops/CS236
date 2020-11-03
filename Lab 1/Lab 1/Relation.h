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
    
    Relation(string s, Header h);
    
    void ToString();
    string GetRelationName();
    void AddTuple(Tuple* t);
    
private:
    
    string nameOfRelation = "";
    Header header;
    set <Tuple*> tuples;
   
    
    
};

#endif
