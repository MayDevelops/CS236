#include "Lexer.h"

Lexer::Lexer(string inFile){
    Tokenizer tokenizer(inFile);
    //cout << "Getting tokens from tokenizer for lexer..." << endl;
    
    for(unsigned int i = 0; i < tokenizer.GetTokens().size(); i++) {
        tokens.push_back(*tokenizer.GetTokens()[i]);
    }
    
}

vector <Token> Lexer::GetTokens(){
    //cout << "Size in Lexer: " << tokens.size() << endl;
    return tokens;
}


