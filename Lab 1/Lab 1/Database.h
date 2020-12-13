#ifndef Database_h
#define Database_h

#include "Relation.h"

#include <stdio.h>
#include <map>
#include <string>
#include <sstream>

class Database {
    
public:
    void AddToMap(string s, Relation relation);
    
    string toString () {
        ostringstream os;
        os << "";
        for(map<string, Relation>::iterator it = database.begin(); it != database.end(); it++) {
            os << (*it).second.ToString();
        }
        
        
        return os.str();
    }
    
    int GetCount() {
        int count = 0;
        for(map<string, Relation>::iterator it = database.begin(); it != database.end(); it++) {
            count += it->second.tuples.size();
        }
        return count;
    }
    
    
    
    
    
    
    map <string, Relation> database;
    
};

#endif
