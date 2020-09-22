#include "Lexer.h"


Lexer::Lexer(string inFile, ofstream &outFile){
    Tokenizer tokenizer(inFile,outFile);
}
