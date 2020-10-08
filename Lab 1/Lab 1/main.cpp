#include <iostream>
#include <fstream>
#include <string>

#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include "Tokenizer.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
#ifndef DEBUG
    //Vectors are storing the files for testing and development purposes, not needed for passoff.
    vector <string> twoEightyFiles = {"input0.txt","input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt"};
    
    //"input0.txt","input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt"
    
    vector <string> outTwoEightyFiles = {"out0.txt", "out1.txt", "out2.txt", "out3.txt", "out4.txt", "out5.txt", "out6.txt", "out7.txt", "out8.txt"};
   //"out0.txt", "out1.txt", "out2.txt", "out3.txt", "out4.txt", "out5.txt", "out6.txt", "out7.txt", "out8.txt"
    
    
    //ofstream outFile (""); //Passes to comply with constructor, but not being used during pasoff. Only used during testing and development.
    
    for(int i = 0; i < twoEightyFiles.size(); i++) {
    ofstream outFile (outTwoEightyFiles[i]); //Passes to comply with constructor, but not being used during pasoff. Only used during testing and development.
    Lexer lexer(twoEightyFiles[i], outFile);
        //cout << "Sending tokens to Parser..." << endl;
    Parser parser(lexer.GetTokens());
        //cout << "Tokens accepted by Parser..." << endl;
        bool theParse = parser.Parse();
        
        if(theParse) {
            cout << "\t\tTRUE TRUE TRUE" << endl;
            outFile << "TRUE TRUE TRUE" << endl;
        } else {
            cout << "\t\tFailure!" << endl;
            outFile <<"Failure!" << endl;
            parser.ReturnFailure(outFile);
        }
    }
#endif
    
#ifdef DEBUG
    ofstream outFile (argv[2]);
    Lexer lexer(argv[1], outFile);
    Parser parser(lexer.GetTokens());
    bool theParse = parser.Parse();
    if(theParse) {
        outFile << "TRUE TRUE TRUE" << endl;
    } else {
        outFile << "Failure!" << endl;
        parser.ReturnFailure(outFile);
        
    }
#endif
    return 0;
}




