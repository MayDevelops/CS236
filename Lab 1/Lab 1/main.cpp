#include <iostream>
#include <fstream>
#include <string>

#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include "Database.h"
#include "Tokenizer.h"
#include "Interpreter.h"

using namespace std;

int main(int argc, const char * argv[]) {
    

    vector <string> inFiles = {"input0.txt","input1.txt", "input2.txt"};
    //"input0.txt","input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt"
    
    
    
    
#ifdef DEBUG
    Lexer lexer(argv[1]);
    DatalogProgram datalogProgram;
    Parser parser(lexer.GetTokens(), datalogProgram);
    if(parser.Parse()) {
        cout << "Success!" << endl;
        datalogProgram.ToString();
    } else {
        cout << "Failure!" << endl;
        parser.ReturnFailure();
    }
#endif
    
    
#ifndef DEBUG
    for(int i = 0; i < inFiles.size(); i++) {
        Lexer lexer(inFiles[i]);
        
        
        DatalogProgram datalogProgram;
        Database database;
        Parser parser(lexer.GetTokens(), datalogProgram);
        
        
        if(parser.Parse()) {
            
            Interpreter interpreter(datalogProgram, database);
            cout << endl << endl << endl << "Calling datalogProgram ToString..." << endl;
            cout << "Success!" << endl;
            datalogProgram.ToString();
        } else {
            cout << "Failure!" << endl;
            //Interpreter interpreter(datalogProgram, database);

            parser.ReturnFailure();
        }
    }
#endif
    

    
    return 0;
}




