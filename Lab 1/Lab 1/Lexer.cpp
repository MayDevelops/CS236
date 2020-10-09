#include "Lexer.h"

Lexer::Lexer(string inFile, ofstream &outFile){
    Tokenizer tokenizer(inFile,outFile);
    //cout << "Getting tokens from tokenizer for lexer..." << endl;
    
    for(int i = 0; i < tokenizer.GetTokens().size(); i++) {
        tokens.push_back(*tokenizer.GetTokens()[i]);
    }
    
}

vector <Token> Lexer::GetTokens(){
    //cout << "Size in Lexer: " << tokens.size() << endl;
    return tokens;
}


