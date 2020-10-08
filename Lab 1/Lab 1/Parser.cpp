#include "Parser.h"

Parser::Parser(vector <Token> tokensIn) {
    tokens = tokensIn;
}

bool Parser::Parse() {
    int index = 0;
    
    
    if(tokens[index++].GetID() != "SCHEMES") return false;
    if(tokens[index++].GetID() != "COLON") return false;
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
    cout << "SchemeList: " << index << endl;
    if(tokens[index++].GetID() == "FACTS") return true; else index--;
    
    if(!Scheme(index)) return false;
    if(!SchemeList(index)) return false;
    
    return true;
}
bool Parser::FactList(int &index) {
    cout << "FactList: " << index << endl;

    if(tokens[index++].GetID() == "RULES") return true; else index--;
    
    if(!Fact(index)) return false;
    if(!FactList(index)) return false;
    
    return true;
}
bool Parser::RuleList(int &index) {
    cout << "RuleList: " << index << endl;
    
    if(tokens[index++].GetID() == "QUERIES") return true; else index--;

    if(!Rule(index)) return false;
    if(!RuleList(index)) return false;
    
    return true;
}
bool Parser::QueryList(int &index) {
    cout << "QueryList: " << index << endl;

    if(tokens[index++].GetID() == "EOF") return true; else index--;
    
    if(!Query(index)) return false;
    if(!QueryList(index)) return false;

    return true;
}
bool Parser::Scheme(int &index) {
    cout << "Scheme: " << index << endl;

    if(tokens[index++].GetID() != "ID") return false;
    if(tokens[index++].GetID() != "LEFT_PAREN") return false;
    if(tokens[index++].GetID() != "ID") return false;

    if(!IDList(index)) return false;
    
    return true;
}
bool Parser::Fact(int &index) {
    cout << "Fact: " << index << endl;

    if(tokens[index++].GetID() != "ID") return false;
    if(tokens[index++].GetID() != "LEFT_PAREN") return false;
    if(tokens[index++].GetID() != "STRING") return false;
    if(!StringList(index)) return false;
    if(tokens[index++].GetID() != "PERIOD") return false;
    
    return true;
}
bool Parser::Rule(int &index) {
    cout << "Rule: " << index << endl;

    if(!HeadPredicate(index)) return false;
    if(tokens[index++].GetID() != "COLON_DASH") return false;
    if(!Predicate(index)) return false;
    if(!PredicateList(index)) return false;

    return true;
}
bool Parser::Query(int &index) {
    cout << "Query: " << index << endl;

    if(!Predicate(index)) return false;
    if(tokens[index++].GetID() != "Q_MARK") return false;

    return true;
}
bool Parser::HeadPredicate(int &index) {
    cout << "HeadPredicate: " << index << endl;

    if(tokens[index++].GetID() != "ID") return false;
    if(tokens[index++].GetID() != "LEFT_PAREN") return false;
    if(tokens[index++].GetID() != "ID") return false;
    if(!IDList(index)) return false;
    
    return true;
}
bool Parser::Predicate(int &index) {
    cout << "Predicate: " << index << endl;

    if(tokens[index++].GetID() != "ID") return false;
    if(tokens[index++].GetID() != "LEFT_PAREN") return false;
    if(!Parameter(index)) return false;
    if(!ParameterList(index)) return false;
    
    return true;
}
bool Parser::PredicateList(int &index) {
    cout << "PredicateList: " << index << endl;

    if(tokens[index++].GetID() == "PERIOD") return true; else index--;
    
    if(tokens[index++].GetID() != "COMMA") return false;
    if(!Predicate(index)) return false;
    if(!PredicateList(index)) return false;

    return true;
}
bool Parser::ParameterList(int &index) {
    cout << "ParameterList: " << index << endl;
    
    if(tokens[index++].GetID() == "RIGHT_PAREN") return true; else index--;
    
    if(tokens[index++].GetID() != "COMMA") return false;
    if(!Parameter(index)) return false;
    if(!ParameterList(index)) return false;

    return true;
}
bool Parser::StringList(int &index) {
    cout << "StringList: " << index << endl;

    if(tokens[index++].GetID() == "RIGHT_PAREN") return true; else index--;
    
    if(tokens[index++].GetID() != "COMMA") return false;
    if(tokens[index++].GetID() != "STRING") return false;
    if(!StringList(index)) return false;
    
    return true;;
}
bool Parser::IDList(int &index) {
    cout << "IDList: " << index << endl;

    if(tokens[index++].GetID() == "RIGHT_PAREN") return true; else index--;
    
    
    if(tokens[index++].GetID() != "COMMA") return false;
    if(tokens[index++].GetID() != "ID") return false;
    if(!IDList(index)) return false;
    
    return true;
}
bool Parser::Parameter(int &index) {
    cout << "Parameter: " << index << endl;

    if( (tokens[index].GetID() != "STRING") && (tokens[index].GetID() != "ID") && (!Expression(index)) ) return false; else index++;
    
    return true;
}
bool Parser::Expression(int &index) {
    cout << "Expression: " << index << endl;

    if(tokens[index].GetID() == "RIGHT_PAREN") {index++; return true;}

    if(tokens[index++].GetID() != "LEFT_PAREN") return false;
    if(!Parameter(index)) return false;
    if(!Operator(index)) return false;
    if(!Parameter(index)) return false;

    return true;
}
bool Parser::Operator(int &index) {
    cout << "Operator: " << index << endl;

    if( (tokens[index].GetID() != "ADD") && (tokens[index].GetID() != "MULTIPLY") ) return false; else index++;
        

    return true;
}
