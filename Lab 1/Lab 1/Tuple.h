//
//  Tuple.hpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#ifndef Tuple_h
#define Tuple_h

#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class Tuple  {
public:
    bool operator< (const Tuple& other) const {
        return this->values < other.values;
    }
    void AddTuple(string s);
    string ToString(vector<string> header);
    
    vector <string> values;
    
};

#endif
