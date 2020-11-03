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

void Tuple::ToString() {
    for(int i = 0; i < values.size(); i++) {
        cout << values[i];
    }
}
