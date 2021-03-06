//
//  Interpreter.hpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#ifndef Interpreter_h
#define Interpreter_h

#include "Database.h"
#include "Relation.h"
#include "DatalogProgram.h"

#include <stdio.h>


class Interpreter {
public:
    Predicate temp;
    Interpreter(DatalogProgram &datalogProgram, Database &database);
    
    void PopulateRelations();
    void EvaluateQueries();
    void EvaluateRules();
    
private:
    DatalogProgram* dlp;
    Database* db;
};
#endif
