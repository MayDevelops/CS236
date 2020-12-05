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
    
    //cout << endl << "Inside PopulateRelations..." << endl;
    
    for(unsigned int i = 0; i < dlp->schemes.size(); i++) {
        //cout << "Creating Relation object..." << endl;
        Relation relation(dlp->schemes[i]->GetID(), dlp->schemes[i]->parameters);
        db->AddToMap(relation.GetRelationName(), relation);
        
        //Facts
        for (unsigned int j = 0; j < dlp->facts.size(); j++) {
            Tuple t;
            for (unsigned int k = 0; k < dlp->facts[j]->parameters.size(); k++) {
                t.AddTuple(dlp->facts[j]->parameters[k]->GetParameter());
            }
            for (map<string,Relation>::iterator it = db->database.begin(); it != db->database.end(); it++) {
                if (dlp->facts[j]->GetID() == (*it).first) {
                    db->database.at(dlp->facts[j]->GetID()).AddTuple(t);
                }
            }
        }
    }
    
    //cout << db->toString();
    EvaluateQueries();
}


void Interpreter::EvaluateQueries() {
    map<string,unsigned int> theMap;
    for(unsigned int i = 0; i < dlp->queries.size(); i++) {
        //Get Querie Name
        string qName = dlp->queries[i]->GetID();
        
        //Loop through map and find the relation that matches
        for(map<string, Relation>::iterator it = db->database.begin(); it != db->database.end(); it++) {
            //Search through the map and find the one with the matching relation name
            if(qName == (*it).first) {
                Relation temp = (*it).second;
                Relation t = temp;
                vector <unsigned int> indexes;
                vector <string> seentIt;
                
                //Select,Project,Rename
                for(unsigned int j = 0; j < dlp->queries[i]->parameters.size(); j++) {
                    string parameter = dlp->queries[i]->parameters[j]->GetParameter();
                    
                    //This checks to see if it is a constant or not.
                    if (parameter[0] == '\'') {
                        t = t.Select1(j, parameter);
                        
                    } else {
                        theMap.insert(pair<string,unsigned int>(parameter,j));
                        //Select2
                        bool hasSeenIt = true;
                        for (unsigned int k = 0; k < seentIt.size(); k++) {
                            if (seentIt[k] == parameter) {
                                hasSeenIt = false;
                                for (map<string,unsigned int>::iterator mapIT = theMap.begin(); mapIT != theMap.end(); mapIT++) {
                                    if((*mapIT).first == parameter) {
                                        t = t.Select2((*mapIT).second,j);
                                    }
                                }
                            }
                        }
                        if (hasSeenIt) {
                            seentIt.push_back(parameter);
                            indexes.push_back(j);
                        }
                        t = t.Rename(j, parameter);
                        
                    }
                }
                //project
                t = t.Project(indexes);
                cout << dlp->queries[i]->ToString();
                cout << " ";
                if (t.tuples.size() > 0) {
                    cout << "Yes(" << t.tuples.size() << ")";
                    cout << endl;
                    cout << t.ToString();
                } else {
                    cout << "No" << endl;
                }
                
            }
        }
    }
}



