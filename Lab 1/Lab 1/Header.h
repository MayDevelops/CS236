//
//  Header.hpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Header {
public:
    
    void AddColumns(string s);
    string PrintColumns() {
        string temp = "";
        for(int i = 0; i < columns.size(); i++) {
            temp += " " + columns[i] + "\t";
        }
        return temp;
    }
    
    
    vector <string> columns;
};

#endif
