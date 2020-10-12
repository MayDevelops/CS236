#include <iostream>
#include <fstream>
#include <string>

#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include "Tokenizer.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
#ifdef DEBUG
    vector <string> twoEightyFiles = {"input0.txt","input1.txt", "input2.txt"};
    //"input0.txt","input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt"
    vector <string> outTwoEightyFiles = {"out0.txt", "out1.txt", "out2.txt"};
    //"out0.txt", "out1.txt", "out2.txt", "out3.txt", "out4.txt", "out5.txt", "out6.txt", "out7.txt", "out8.txt"
    
    for(unsigned int i = 0; i < twoEightyFiles.size(); i++) {
        ofstream outFile (outTwoEightyFiles[i]);
        Lexer lexer(twoEightyFiles[i], outFile);
        DatalogProgram datalogProgram;
        Parser parser(lexer.GetTokens(), datalogProgram);
        if(parser.Parse()) {
            //cout << "Success!" << endl;
            outFile << "Success!" << endl;
            datalogProgram.ToString(outFile);

            cout << endl << endl;

        } else {
            //cout << "Failure!" << endl;
            outFile <<"Failure!" << endl;
            parser.ReturnFailure(outFile);
        }
    }
#endif
    
    ofstream outFile (argv[2]);
    Lexer lexer(argv[1], outFile);
    DatalogProgram datalogProgram;
    Parser parser(lexer.GetTokens(), datalogProgram);
    if(parser.Parse()) {
        outFile << "Success!" << endl;
        datalogProgram.ToString(outFile);
    } else {
        outFile << "Failure!" << endl;
        parser.ReturnFailure(outFile);
    }

    
    return 0;
}




