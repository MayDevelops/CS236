//
//  Interpreter.cpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram &datalogProgram, Database &database){
    dlp = &datalogProgram;
    db = &database;
    
    PopulateRelations();
}



void Interpreter::PopulateRelations() {
    
    cout << endl << "Inside PopulateRelations..." << endl;
    
    for(int i = 0; i < dlp->schemes.size(); i++) {
        cout << "Creating Relation object..." << endl;
        Relation relation(dlp->schemes[i]->GetID(), dlp->schemes[i]->parameters);
        cout << "Adding relation object to DB Map..." << endl;
        db->AddToMap(relation.GetRelationName(), relation);
        
        //Facts
        for(vector <Predicate*>::iterator factsIT = dlp->facts.begin(); factsIT != dlp->facts.end(); factsIT++) {
            Tuple* t = new Tuple();
            for(vector<Parameter*>::iterator paramIT = (*factsIT)->parameters.begin(); paramIT != (*factsIT)->parameters.end(); paramIT++) {
                t->AddTuple((*paramIT)->GetParameter());
            }
            for(map <string, Relation>::iterator mapIT = db->database.begin(); mapIT != db->database.end(); mapIT++) {
                if((*mapIT).first == (*factsIT)->GetID()) {
                    relation.AddTuple(t);
                }
            }
        }
        
        //Add to Map
        
        
        
        
        
        
        
        
        cout << "Calling Relation ToString..." << endl;
        relation.ToString();
        
    }
}


