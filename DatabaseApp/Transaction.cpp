#include"Transaction.h"

Transaction::Transaction(std::string name, std::string type, int value){
    this->name = name;
    this->type = type;
    this->value = value;
}

Transaction::~Transaction(){
    
}

std::string Transaction::toString(){
    std::string str = "Name: " + this->getName + "\n" + "Type: " + this->getType + "\n" + "Value: " + this->getValue;
    return str;
}