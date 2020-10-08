#include <iostream>
#include <fstream>
#include <string>

#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include "Tokenizer.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    //Vectors are storing the files for testing and development purposes, not needed for passoff.
    vector <string> twoEightyFiles = {"input0.txt","input1.txt", "input2.txt"};
    
    //, "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt"
    
    vector <string> outTwoEightyFiles = {"out0.txt", "out1.txt", "out2.txt"};
   //
    
    
    //ofstream outFile (""); //Passes to comply with constructor, but not being used during pasoff. Only used during testing and development.
    
    for(int i = 0; i < twoEightyFiles.size(); i++) {
    ofstream outFile (outTwoEightyFiles[i]); //Passes to comply with constructor, but not being used during pasoff. Only used during testing and development.
    Lexer lexer(twoEightyFiles[i], outFile);
        //cout << "Sending tokens to Parser..." << endl;
    Parser parser(lexer.GetTokens());
        //cout << "Tokens accepted by Parser..." << endl;
        bool theParse = parser.Parse();
        
        if(theParse) {
            cout << "TRUE TRUE TRUE" << endl;
            outFile << "TRUE TRUE TRUE" << endl;
        } else {
            cout << "FALSE FALSE FALSE" << endl;
            outFile <<"FALSE FALSE FALSE" << endl;
        }
    }
    
    return 0;
}




