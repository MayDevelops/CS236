#include "Token.h"

Token::Token(){
    //default constructor
}
Token::Token(int tokenID, string value, int line, ofstream &outFile){
    stringValue = value;
    lineNumber = line;
    EnumToString(tokenID);
    Print(outFile);
}

void Token::Print(ofstream &outFile) {
    cout << "(" << enumString << ",\"" << stringValue << "\"," << lineNumber << ")" << endl;
    //outFile << "(" << enumString << ",\"" << stringValue << "\"," << lineNumber << ")" << endl;
    
}

void Token::EnumToString(int enumValue) {
    switch (enumValue) {
        case 0 : {
            enumString = "COMMA";
            break;
        }
        case 1 : {
            enumString = "PERIOD";
            break;
        }
        case 2 : {
            enumString = "Q_MARK";
            break;
        }
        case 3 : {
            enumString = "LEFT_PAREN";
            break;
        }
        case 4 : {
            enumString = "RIGHT_PAREN";
            break;
        }
        case 5 : {
            enumString = "COLON";
            break;
        }
        case 6 : {
            enumString = "COLON_DASH";
            break;
        }
        case 7 : {
            enumString = "MULTIPLY";
            break;
        }
        case 8 : {
            enumString = "ADD";
            break;
        }
        case 9 : {
            enumString = "SCHEMES";
            break;
        }
        case 10 : {
            enumString = "FACTS";
            break;
        }
        case 11 : {
            enumString = "RULES";
            break;
        }
        case 12 : {
            enumString = "QUERIES";
            break;
        }
        case 13 : {
            enumString = "ID";
            break;
        }
        case 14 : {
            enumString = "STRING";
            break;
        }
        case 15 : {
            enumString = "COMMENT";
            break;
        }
        case 16 : {
            enumString = "UNDEFINED";
            break;
        }
        case 17 : {
            enumString = "EOF";
            break;
        }
    }
}

string Token::GetID() {
    return enumString;
}

string Token::GetValue() {
    return stringValue;
}

int Token::GetLine() {
    return lineNumber;
}

void Token::Get() {
    cout << endl << lineNumber << " " << enumString << " \"" << stringValue << "\"" << endl << endl;
}
