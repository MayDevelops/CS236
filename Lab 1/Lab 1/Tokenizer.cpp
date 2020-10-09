#include "Tokenizer.h"

Tokenizer::Tokenizer(){
    //default
}

Tokenizer::Tokenizer(string inFile, ofstream &outFile){
    ParseFileInput(inFile, outFile);
}

Tokenizer::~Tokenizer(){
    for(size_t i = 0; i < tokens.size(); i++) {
        delete tokens[i];
    }
}

void Tokenizer::ParseFileInput(string inFile, ofstream &outFile) {
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
                    tokens.push_back(new Token(17,"",lineNumber, outFile));
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
                tokens.push_back(new Token(16,word,lineNumber, outFile));
                enterSwitch = false;
            }
            if(enterSwitch) {
                switch (inChar) {
                    case ',' : {
                        tokens.push_back(new Token(0,",",lineNumber, outFile));
                        break;
                    }
                    case '.' : {
                        tokens.push_back(new Token(1,".",lineNumber, outFile));
                        break;
                    }
                    case '?' : {
                        tokens.push_back(new Token(2,"?",lineNumber, outFile));
                        break;
                    }
                    case '(' : {
                        tokens.push_back(new Token(3,"(",lineNumber, outFile));
                        break;
                    }
                    case ')' : {
                        tokens.push_back(new Token(4,")",lineNumber, outFile));
                        break;
                    }
                    case ':' : {
                        if(file.peek() == '-'){
                            inChar = file.get();
                            tokens.push_back(new Token(6,":-",lineNumber, outFile));
                            break;
                        } else {
                            tokens.push_back(new Token(5,":",lineNumber, outFile));
                            break;
                        }
                    }
                    case '*' : {
                        tokens.push_back(new Token(7,"*",lineNumber, outFile));
                        break;
                    }
                    case '+' : {
                        tokens.push_back(new Token(8,"+",lineNumber, outFile));
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
                                tokens.push_back(new Token(16,word,lineNumber, outFile));
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
                            tokens.push_back(new Token(16,word,lineNumber, outFile));
                        }else {
                            tokens.push_back(new Token(14,word,lineNumber, outFile));
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
                    tokens.push_back(new Token(9,"Schemes",lineNumber, outFile));
                } else if (word == "Facts") {
                    tokens.push_back(new Token(10,"Facts",lineNumber, outFile));
                } else if (word == "Rules") {
                    tokens.push_back(new Token(11,"Rules",lineNumber, outFile));
                } else if (word == "Queries") {
                    tokens.push_back(new Token(12,"Queries",lineNumber, outFile));
                } else {//this is ID
                    tokens.push_back(new Token(13,word,lineNumber, outFile));
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
