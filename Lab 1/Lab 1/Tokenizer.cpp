#include "Tokenizer.h"

Tokenizer::Tokenizer(){
    //default
}

Tokenizer::Tokenizer(string inFile){
    ParseFileInput(inFile);
}

Tokenizer::~Tokenizer(){
    for(unsigned int i = 0; i < tokens.size(); i++) {
        delete tokens[i];
    }
}

void Tokenizer::ParseFileInput(string inFile) {
    ifstream file;
    file.open(inFile);
    char inChar = '\a';
    int lineNumber = 1;
    string word = "";
    int tempLineNumber = 0;
    
    if (file.is_open()) {
        while (true) {
            bool enterSwitch = true;
            word = "";
            if (file.peek() == ifstream::traits_type::eof() ) {
                if(file.peek() == -1) {
                    lineNumber = lineNumber + tempLineNumber;
                    tempLineNumber = 0;
                    tokens.push_back(new Token(17,"",lineNumber));
                }
                break;
            }
            if(tempLineNumber > 0) {
                lineNumber = lineNumber + tempLineNumber;
                tempLineNumber = 0;
            }
            inChar = file.get();
            if (inChar == '\n'){
                lineNumber++;
                lineNumber = lineNumber + tempLineNumber;
                tempLineNumber = 0;
            }
            
            if(!isalpha(inChar) && CheckCharApproval(inChar)){
                word += inChar;
                tokens.push_back(new Token(16,word,lineNumber));
                enterSwitch = false;
            }
            if(enterSwitch) {
                switch (inChar) {
                    case ',' : {
                        tokens.push_back(new Token(0,",",lineNumber));
                        break;
                    }
                    case '.' : {
                        tokens.push_back(new Token(1,".",lineNumber));
                        break;
                    }
                    case '?' : {
                        tokens.push_back(new Token(2,"?",lineNumber));
                        break;
                    }
                    case '(' : {
                        tokens.push_back(new Token(3,"(",lineNumber));
                        break;
                    }
                    case ')' : {
                        tokens.push_back(new Token(4,")",lineNumber));
                        break;
                    }
                    case ':' : {
                        if(file.peek() == '-'){
                            inChar = file.get();
                            tokens.push_back(new Token(6,":-",lineNumber));
                            break;
                        } else {
                            tokens.push_back(new Token(5,":",lineNumber));
                            break;
                        }
                    }
                    case '*' : {
                        tokens.push_back(new Token(7,"*",lineNumber));
                        break;
                    }
                    case '+' : {
                        tokens.push_back(new Token(8,"+",lineNumber));
                        break;
                    }
                    case '#' : { //FIXME:: still need to implement the block comment rules here
                        bool undefined = true;
                        if(file.peek() == '|') {
                            word += inChar;
                            inChar = file.get();
                            word += inChar;
                            
                            while(file.get(inChar)) {
                                if (inChar == '|' && file.peek() == '#'){
                                    //this is the end of th eblock
                                    word += inChar;
                                    inChar = file.get();
                                    word += inChar;
                                    //tokens.push_back(new Token(15,word,lineNumber, outFile));
                                    undefined = false;
                                    break;
                                } else if (inChar == '\n') {
                                    tempLineNumber++;
                                    word += inChar;
                                } else {
                                    word += inChar;
                                }
                            }
                            if(undefined){
                                tokens.push_back(new Token(16,word,lineNumber));
                            }
                            break;
                        } else {
                            while(inChar != '\n') {
                                word += inChar;
                                inChar = file.get();
                            }
                            file.putback(inChar);
                            //tokens.push_back(new Token(15,word,lineNumber, outFile));
                            break;
                        }
                    }
                    case '\'' : {
                        word += inChar;
                        int numQ = 1;
                        
                        while(file.get(inChar)){
                            if (inChar == '\'' && file.peek() == '\'') {
                                word += inChar;
                                inChar = file.get();
                                word += inChar;
                                continue;
                            }
                            if(inChar == '\'') {
                                word += inChar;
                                numQ++;
                                break;
                            } else if (inChar == '\n') {
                                word += inChar;
                                tempLineNumber++;
                                continue;
                            }
                            word += inChar;
                        }
                        if(numQ % 2 != 0) {
                            tokens.push_back(new Token(16,word,lineNumber));
                        }else {
                            tokens.push_back(new Token(14,word,lineNumber));
                        }
                    }
                }
            }
            
            if (isalpha(inChar)){
                while(isalnum(inChar)){
                    word += inChar;
                    inChar = file.get();
                }
                file.putback(inChar);
                
                if(word == "Schemes") {
                    tokens.push_back(new Token(9,"Schemes",lineNumber));
                } else if (word == "Facts") {
                    tokens.push_back(new Token(10,"Facts",lineNumber));
                } else if (word == "Rules") {
                    tokens.push_back(new Token(11,"Rules",lineNumber));
                } else if (word == "Queries") {
                    tokens.push_back(new Token(12,"Queries",lineNumber));
                } else {//this is ID
                    tokens.push_back(new Token(13,word,lineNumber));
                }
            }
        }
    } else {
        cout << "unable to open file." << endl;
    }
#ifndef DEBUG
    //cout << "Total Tokens = " << tokens.size() << endl;
#endif
    //outFile << "Total Tokens = " << tokens.size();
    
}

string Tokenizer::PrintChars(vector <char> chars){
    string temp(chars.begin(), chars.end());
    return temp;
}

bool Tokenizer::CheckCharApproval(char inChar){
    if (inChar == '#' || inChar == ',' || inChar == '.' || inChar == '?' || inChar == '(' || inChar == ')' || inChar == ':' || inChar == '*' || inChar == '+' || inChar == '\n' || inChar == '\'' || inChar == ' ' || inChar == '\t') {
        return false;
    } else {
        return true;
    }
}

vector <Token*> Tokenizer::GetTokens(){
    //cout << "Size in Tokenizer: " << tokens.size() << endl;
    
    
    return tokens;
}
