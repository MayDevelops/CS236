//
//  Database.cpp
//  Lab 1
//
//  Created by JC May on 11/2/20.
//  Copyright © 2020 MayDevlops. All rights reserved.
//

#include "Database.h"

void Database::AddToMap(string s, Relation* relation) {
    database.insert ( pair <string, Relation*> (s,relation) );
}
