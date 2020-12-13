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
    
    // MARK: Test Code For Rules Lab
    cout << "Rule Evaluation" << endl;
    
    int counter = 0;
    
    int start = db->GetCount();
    int finish = 0;
    bool loop = true;
    do{
        EvaluateRules();
        counter++;
        finish = db->GetCount();
        
        if(finish == start) {
            loop = false;
        } else {
            start = finish;
        }
        

    }while(loop);
    cout << endl << "Schemes populated after " << counter << " passes through the Rules." << endl;
    cout << endl << "Query Evaluation" << endl;
    EvaluateQueries();
}

void Interpreter::EvaluateRules() {
    for(int i = 0; i < dlp->rules.size(); i++) {
        
        cout << dlp->rules[i]->ToString() << endl;
        Relation tempRelation = db->database.at(dlp->rules[i]->body[0]->GetID());
        tempRelation.ChangeHeader(dlp->rules[i]->body[0]->parameters);
        for(int z = 1; z < dlp->rules[i]->body.size(); z++) {
            Relation tempRelation2 = db->database.at(dlp->rules[i]->body[z]->GetID());
            tempRelation2.ChangeHeader(dlp->rules[i]->body[z]->parameters);
            tempRelation = tempRelation.Join(tempRelation, tempRelation2);
        }
        
        vector <unsigned int> indexes;
        for(int j = 0; j < dlp->rules[i]->headPred->parameters.size(); j++) {
            for(int k = 0; k < tempRelation.header.columns.size(); k++) {
                if(dlp->rules[i]->headPred->parameters[j]->GetParameter() == tempRelation.header.columns[k]) {
                    indexes.push_back(k);
                }
            }
        }
        tempRelation = tempRelation.Project(indexes);

        db->database.at(dlp->rules[i]->headPred->ID).Union(tempRelation);
   }
}


void Interpreter::PopulateRelations() {

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
                // MARK: UNCOMMENT FOR LAB 3 OUTPUT
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



