#include "Parser.h"

Parser::Parser(vector <Token> tokensIn, DatalogProgram &datalogProgram) {
    tokens = tokensIn;
    dlp = &datalogProgram;
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



bool Parser::Scheme(int &index) {
    if(tokens[index].GetID() != "ID") return false; else {predicateContainer.push_back(new Predicate(tokens[index].GetValue())); index++;}
    if(tokens[index].GetID() != "LEFT_PAREN") return false; else index++;
    if(tokens[index].GetID() != "ID") return false; else {predicateContainer[0]->AddParameter(tokens[index].GetValue()); index++;}
    
    if(!IDList(index)) return false;
    predicateContainer[0]->SetClassification('s');
    dlp->SetSchemes(predicateContainer[0]);
    predicateContainer.clear();
    return true;
}

bool Parser::SchemeList(int &index) {
    if(tokens[index].GetID() == "FACTS") {index++; return true;}
    
    if(!Scheme(index)) return false;
    if(!SchemeList(index)) return false;
    
    return true;
}

//only care about ID's and Strings
bool Parser::Fact(int &index) {
    if(tokens[index].GetID() != "ID") return false; else {predicateContainer.push_back(new Predicate(tokens[index].GetValue())); index++;}
    if(tokens[index].GetID() != "LEFT_PAREN") return false; else index++;
    if(tokens[index].GetID() != "STRING") return false; else {predicateContainer[0]->AddParameter(tokens[index].GetValue()); dlp->SetDomains((tokens[index].GetValue())); index++;}
    if(!StringList(index)) return false;
    if(tokens[index].GetID() != "PERIOD") return false; else index++;
    predicateContainer[0]->SetClassification('f');
    dlp->SetFacts(predicateContainer[0]);
    predicateContainer.clear();
    return true;
}

bool Parser::FactList(int &index) {
    if(tokens[index].GetID() == "RULES") {index++; return true;}
    
    if(!Fact(index)) return false;
    if(!FactList(index)) return false;
    
    return true;
}

//only care about ID's, strings, expressions
bool Parser::Rule(int &index) {
    if(!HeadPredicate(index)) return false;
    Predicate* tempHeadPred = predicateContainer[0];
    predicateContainer.clear();
    if(tokens[index].GetID() != "COLON_DASH") return false; else index++;
    if(!Predicates(index)) return false;
    if(!PredicateList(index)) return false;
    dlp->SetRules(new Rules(tempHeadPred, predicateContainer));
    predicateContainer.clear();
    //dlp->Temp();
    
    return true;
}

bool Parser::RuleList(int &index) {
    if(tokens[index].GetID() == "QUERIES") {index++; return true;}
    
    if(!Rule(index)) return false;
    if(!RuleList(index)) return false;
    
    return true;
}

//only care about strings id's
bool Parser::Query(int &index) {
    predicateContainer.clear();
    
    if(!Predicates(index)) return false;
    if(tokens[index].GetID() != "Q_MARK") return false; else index++;
    predicateContainer[0]->SetClassification('q');
    dlp->SetQueries(predicateContainer[0]);
    predicateContainer.clear();
    return true;
}

bool Parser::QueryList(int &index) {
    if(tokens[index].GetID() == "EOF") {index++; return true;}
    
    if(!Query(index)) return false;
    if(!QueryList(index)) return false;
    
    return true;
}

bool Parser::HeadPredicate(int &index) {
    if(tokens[index].GetID() != "ID") return false; else {predicateContainer.push_back(new Predicate(tokens[index].GetValue())); index++;}
    if(tokens[index].GetID() != "LEFT_PAREN") return false; else index++;
    if(tokens[index].GetID() != "ID") return false; else {predicateContainer[0]->AddParameter(tokens[index].GetValue()); index++;}
    if(!IDList(index)) return false;
    return true;
}

bool Parser::Predicates(int &index) {
    if(tokens[index].GetID() != "ID") return false; else {predicateContainer.push_back(new Predicate(tokens[index].GetValue())); index++;}
    if(tokens[index].GetID() != "LEFT_PAREN") return false; else index++;
    if(!Parameter(index)) return false;
    if(!ParameterList(index)) return false;
    
    return true;
}

bool Parser::PredicateList(int &index) {
    if(tokens[index].GetID() == "PERIOD") {index++; return true;}
    
    if(tokens[index].GetID() != "COMMA") return false; else index++;
    if(!Predicates(index)) return false;
    if(!PredicateList(index)) return false;
    
    return true;
}

bool Parser::StringList(int &index) {
    if(tokens[index].GetID() == "RIGHT_PAREN") {index++; return true;}
    
    if(tokens[index].GetID() != "COMMA") return false; else index++;
    if(tokens[index].GetID() != "STRING") return false; else {predicateContainer[CalculateContainerIndex()]->AddParameter(tokens[index].GetValue()); dlp->SetDomains((tokens[index].GetValue())); index++;}
    if(!StringList(index)) return false;
    
    return true;;
}

bool Parser::IDList(int &index) {
    if(tokens[index].GetID() == "RIGHT_PAREN") {index++; return true;}
    if(tokens[index].GetID() != "COMMA") return false; else index++;
    if(tokens[index].GetID() != "ID") return false; else {predicateContainer[CalculateContainerIndex()]->AddParameter(tokens[index].GetValue()); index++;}
    if(!IDList(index)) return false;
    return true;
}

bool Parser::Parameter(int &index) {
    if( (tokens[index].GetID() != "STRING") && (tokens[index].GetID() != "ID") && (!Expression(index)) ) return false; else {predicateContainer[CalculateContainerIndex()]->AddParameter(tokens[index].GetValue()); index++;}
    
    return true;
}

bool Parser::ParameterList(int &index) {
    if(tokens[index].GetID() == "RIGHT_PAREN") {index++; return true;}
    
    if(tokens[index].GetID() != "COMMA") return false; else index++;
    if(!Parameter(index)) return false;
    if(!ParameterList(index)) return false;
    return true;
}

bool Parser::Expression(int &index) {
    if(tokens[index].GetID() == "RIGHT_PAREN") {index++; return true;}
    
    if(tokens[index].GetID() != "LEFT_PAREN") return false; else {predicateContainer[CalculateContainerIndex()]->AddParameter(tokens[index].GetValue()); index++;}
    if(!Parameter(index)) return false;
    if(!Operator(index)) return false;
    if(!Parameter(index)) return false;
    
    return true;
}

bool Parser::Operator(int &index) {
    if( (tokens[index].GetID() != "ADD") && (tokens[index].GetID() != "MULTIPLY") ) return false; else {predicateContainer[CalculateContainerIndex()]->AddParameter(tokens[index].GetValue()); index++;}
    
    
    return true;
}

void Parser::ReturnFailure(){
    tokens[index].Print();
}

int Parser::CalculateContainerIndex() {
    
    if(predicateContainer.size() == 1) {
        return 0;
    } else {
        return((int)predicateContainer.size() - 1);
    }
}
