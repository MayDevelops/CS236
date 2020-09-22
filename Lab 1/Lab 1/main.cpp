#include <iostream>
#include <fstream>
#include <string>

#include "Token.h"
#include "Lexer.h"
#include "Tokenizer.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    //Vectors are storing the files for testing and development purposes.
    vector <string> seventyFiles = {"input1.txt", "inputnoway.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt"};
    vector <string> ninetyFiles = {"input1.txt", "input2.txt", "input3.txt"};
    vector <string> hundredFiles {"input1.txt", "input2.txt"};
    vector <string> outSeventyFiles = {"out1.txt", "outnoway.txt", "out3.txt", "out4.txt", "out5.txt", "out6.txt", "out7.txt"};
    vector <string> outNinetyFiles = {"out1.txt", "out2.txt", "out3.txt"};
    vector <string> outHundredFiles {"out1.txt", "out2.txt"};
    
    ofstream outFile (""); //Passes to comply with constructor, but not being used during pasoff. Only used during testing and development.
    Lexer lexer(argv[1], outFile);
    
    return 0;
}
