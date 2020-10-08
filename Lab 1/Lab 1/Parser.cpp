#include "Parser.h"

Parser::Parser(vector <Token> tokensIn) {
    tokens = tokensIn;
}

bool Parser::Parse() {
    
    
    
    if(tokens[index].GetID() != "SCHEMES") return false; else index++;
    if(tokens[index].GetID() != "COLON") return false; else index++;
    if(!Scheme(index)) return false;
    if(!SchemeList(index)) return false;
    if(tokens[index++].GetID() != "COLON") return false;
    if(!FactList(index)) return false;
    if(tokens[index++].GetID() != "COLON") return false;
    if(!RuleList(index)) return false;
    if(tokens[index++].GetID() != "COLON") return false;
    if(!Query(index)) return false;
    if(!QueryList(index)) return false;
    
    return true;
}


bool Parser::SchemeList(int &index) {
#ifndef DEBUG
    cout << "SchemeList: " << index << endl;
#endif
    if(tokens[index].GetID() == "FACTS") {index++; return true;}
    
    if(!Scheme(index)) return false;
    if(!SchemeList(index)) return false;
    
    return true;
}
bool Parser::FactList(int &index) {
#ifndef DEBUG
    cout << "FactList: " << index << endl;
#endif
    if(tokens[index].GetID() == "RULES") {index++; return true;}
    
    if(!Fact(index)) return false;
    if(!FactList(index)) return false;
    
    return true;
}
bool Parser::RuleList(int &index) {
#ifndef DEBUG
    cout << "RuleList: " << index << endl;
#endif
    if(tokens[index].GetID() == "QUERIES") {index++; return true;}

    if(!Rule(index)) return false;
    if(!RuleList(index)) return false;
    
    return true;
}
bool Parser::QueryList(int &index) {
#ifndef DEBUG
    cout << "QueryList: " << index << endl;
#endif
    if(tokens[index].GetID() == "EOF") {index++; return true;}
    
    if(!Query(index)) return false;
    if(!QueryList(index)) return false;

    return true;
}
bool Parser::Scheme(int &index) {
#ifndef DEBUG
    cout << "Scheme: " << index << endl;
#endif
    if(tokens[index].GetID() != "ID") return false; else index++;
    if(tokens[index].GetID() != "LEFT_PAREN") return false; else index++;
    if(tokens[index].GetID() != "ID") return false; else index++;

    if(!IDList(index)) return false;
    
    return true;
}
bool Parser::Fact(int &index) {
#ifndef DEBUG
    cout << "Fact: " << index << endl;
#endif
    if(tokens[index].GetID() != "ID") return false; else index++;
    if(tokens[index].GetID() != "LEFT_PAREN") return false; else index++;
    if(tokens[index].GetID() != "STRING") return false; else index++;
    if(!StringList(index)) return false;
    if(tokens[index].GetID() != "PERIOD") return false; else index++;
    
    return true;
}
bool Parser::Rule(int &index) {
#ifndef DEBUG
    cout << "Rule: " << index << endl;
#endif
    if(!HeadPredicate(index)) return false;
    if(tokens[index].GetID() != "COLON_DASH") return false; else index++;
    if(!Predicate(index)) return false;
    if(!PredicateList(index)) return false;

    return true;
}
bool Parser::Query(int &index) {
#ifndef DEBUG
    cout << "Query: " << index << endl;
#endif
    if(!Predicate(index)) return false;
    if(tokens[index].GetID() != "Q_MARK") return false; else index++;

    return true;
}
bool Parser::HeadPredicate(int &index) {
#ifndef DEBUG
    cout << "HeadPredicate: " << index << endl;
#endif
    if(tokens[index].GetID() != "ID") return false; else index++;
    if(tokens[index].GetID() != "LEFT_PAREN") return false; else index++;
    if(tokens[index].GetID() != "ID") return false; else index++;
    if(!IDList(index)) return false;
    
    return true;
}
bool Parser::Predicate(int &index) {
#ifndef DEBUG
    cout << "Predicate: " << index << endl;
#endif
    if(tokens[index].GetID() != "ID") return false; else index++;
    if(tokens[index].GetID() != "LEFT_PAREN") return false; else index++;
    if(!Parameter(index)) return false;
    if(!ParameterList(index)) return false;
    
    return true;
}
bool Parser::PredicateList(int &index) {
#ifndef DEBUG
    cout << "PredicateList: " << index << endl;
#endif
    if(tokens[index].GetID() == "PERIOD") {index++; return true;}
    
    if(tokens[index].GetID() != "COMMA") return false; else index++;
    if(!Predicate(index)) return false;
    if(!PredicateList(index)) return false;

    return true;
}
bool Parser::ParameterList(int &index) {
#ifndef DEBUG
    cout << "ParameterList: " << index << endl;
#endif
    
    if(tokens[index].GetID() == "RIGHT_PAREN") {index++; return true;}
    
    if(tokens[index].GetID() != "COMMA") return false; else index++;
    if(!Parameter(index)) return false;
    if(!ParameterList(index)) return false;
    return true;
}
bool Parser::StringList(int &index) {
#ifndef DEBUG
    cout << "StringList: " << index << endl;
#endif
    if(tokens[index].GetID() == "RIGHT_PAREN") {index++; return true;}
    
    if(tokens[index].GetID() != "COMMA") return false; else index++;
    if(tokens[index].GetID() != "STRING") return false; else index++;
    if(!StringList(index)) return false;
    
    return true;;
}
bool Parser::IDList(int &index) {
#ifndef DEBUG
    cout << "IDList: " << index << endl;
#endif
    if(tokens[index].GetID() == "RIGHT_PAREN") {index++; return true;}
    
    
    if(tokens[index].GetID() != "COMMA") return false; else index++;
    if(tokens[index].GetID() != "ID") return false; else index++;
    if(!IDList(index)) return false;
    
    return true;
}
bool Parser::Parameter(int &index) {
#ifndef DEBUG
    cout << "Parameter: " << index << endl;
#endif
    if( (tokens[index].GetID() != "STRING") && (tokens[index].GetID() != "ID") && (!Expression(index)) ) return false; else index++;
    
    return true;
}
bool Parser::Expression(int &index) {
#ifndef DEBUG
    cout << "Expression: " << index << endl;
#endif

    if(tokens[index].GetID() == "RIGHT_PAREN") {index++; return true;}

    if(tokens[index].GetID() != "LEFT_PAREN") return false; else index++;
    if(!Parameter(index)) return false;
    if(!Operator(index)) return false;
    if(!Parameter(index)) return false;

    return true;
}
bool Parser::Operator(int &index) {
#ifndef DEBUG
    cout << "Operator: " << index << endl;
#endif
    if( (tokens[index].GetID() != "ADD") && (tokens[index].GetID() != "MULTIPLY") ) return false; else index++;
        

    return true;
}

void Parser::ReturnFailure(ofstream &outFile){
    tokens[index].Print(outFile);
}
