//
//  Tuple.cpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#include "Tuple.h"

void Tuple::AddTuple(string s) {
    values.push_back(s);
}

string Tuple::ToString(vector<string> header) {
    string s = "";
    int counter = 0;
    for (unsigned int i = 0; i < header.size(); i++) {
        s += header[i] + "=";
        
        if (i == header.size() - 1) {
            s += values[i] + "\n";
        } else {
            s += values[i] + ", ";
        }
        counter++;
    }
    
    return s;
}
