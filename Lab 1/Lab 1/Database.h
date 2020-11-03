#ifndef Database_h
#define Database_h

#include "Relation.h"


#include <stdio.h>
#include <map>
#include <string>




class Database {
    
public:
    void AddToMap(string s, Relation relation);
    
    

    map <string, Relation> database;
    
};

#endif
