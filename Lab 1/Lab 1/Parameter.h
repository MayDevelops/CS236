#ifndef Parameter_h
#define Parameter_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Parameter {
public:
    Parameter(string s);
    string GetParameter();
private:
    
    string parameter;
    
};
#endif
