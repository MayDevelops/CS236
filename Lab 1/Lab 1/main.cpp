#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "Token.h"
#include "Lexer.h"
#include "Tokenizer.h"


using namespace std;



int main(int argc, const char * argv[]) {
    
    vector <string> seventyFiles = {"input1.txt", "inputnoway.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt"};
    vector <string> ninetyFiles = {"input1.txt", "input2.txt", "input3.txt"};
    vector <string> hunnitFiles {"input1.txt", "input2.txt"};
    vector <string> testFiles = {"test.txt"};
    
    vector <string> outSeventyFiles = {"out1.txt", "outnoway.txt", "out3.txt", "out4.txt", "out5.txt", "out6.txt", "out7.txt"};
    vector <string> outNinetyFiles = {"out1.txt", "out2.txt", "out3.txt"};
    vector <string> outHunnitFiles {"out1.txt", "out2.txt"};
    vector <string> outTestFiles = {"outTest.txt"};
    
    
 

    
    for (int i = 0; i < seventyFiles.size(); i++){
        ofstream outFile (outSeventyFiles[i]);
    Lexer lexer(seventyFiles[i], outFile);
        cout << endl << endl << endl;

    }
    
    
    
    
    
    
    
    return 0;
}