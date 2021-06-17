
#include "objectSimple.h"

ObjectSimple::ObjectSimple(string name, string description, string use) {
    this->name = name;
    this->description = description;
    this->use = use;
}

string ObjectSimple::getName() const{
    return name;
}

objectType ObjectSimple::getType() {
    return simpleType;
}

string ObjectSimple::getDescription() const{
    return description;
}

string ObjectSimple::getUse() {
    return use;
}