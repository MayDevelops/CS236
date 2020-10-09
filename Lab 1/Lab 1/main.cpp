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
    vector <string> twoEightyFiles = {"input0.txt","input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt"};
    
    //"input0.txt","input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt"
    
    vector <string> outTwoEightyFiles = {"out0.txt", "out1.txt", "out2.txt", "out3.txt", "out4.txt", "out5.txt", "out6.txt", "out7.txt", "out8.txt"};
    //"out0.txt", "out1.txt", "out2.txt", "out3.txt", "out4.txt", "out5.txt", "out6.txt", "out7.txt", "out8.txt"
    
    
    //ofstream outFile (""); //Passes to comply with constructor, but not being used during pasoff. Only used during testing and development.
    
    /*
    for(int i = 0; i < twoEightyFiles.size(); i++) {
        ofstream outFile (outTwoEightyFiles[i]); //Passes to comply with constructor, but not being used during pasoff. Only used during testing and development.
        Lexer lexer(twoEightyFiles[i], outFile);
        //cout << "Sending tokens to Parser..." << endl;
        
        DatalogProgram datalogProgram;
        
        Parser parser(lexer.GetTokens(), datalogProgram);
        //cout << "Tokens accepted by Parser..." << endl;
        bool theParse = parser.Parse();
        if(theParse) {
            
            cout << "Success!" << endl;
            outFile << "Success!" << endl;
            datalogProgram.ToString(outFile);
        } else {
            cout << "Failure!" << endl;
            outFile <<"Failure!" << endl;
            parser.ReturnFailure(outFile);
        }
        
        
        
        
    }
    */
    
    
    
    
     ofstream outFile (argv[2]);
     Lexer lexer(argv[1], outFile);
     DatalogProgram datalogProgram;
     
     Parser parser(lexer.GetTokens(), datalogProgram);
     bool theParse = parser.Parse();
     if(theParse) {
     outFile << "Success!" << endl;
        datalogProgram.ToString(outFile);
     } else {
     outFile << "Failure!" << endl;
     parser.ReturnFailure(outFile);
     
     }
     
    
    return 0;
}




