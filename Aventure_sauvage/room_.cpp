#include "room_.h"


roomType Room::getType() {
    return room;
}

void Room::toggleIllumination() {}

bool Room::getLocked() {
    return false;
}
void Room::toggleLocked() {}

Room::Room(string name, string description) {
    this->name = name;
    this->description = description;
}


string Room::getName() const{
    return name;
}



string Room::getDescription() {
    return description;
}


vector<ObjectSimple*> Room::getObjects() {
    vector<ObjectSimple*> listObjects;
    for (int i = 0; i < objects.size(); i++) {
        ObjectSimple* oneObject = objects[i].get();
        listObjects.push_back(oneObject);
    }
    return listObjects;
}


int  Room::getObjectIndex(string objectName) {
    int objectIndex = -1;

    //looks for object
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->getName().find(objectName) != string::npos) {
            objectIndex = i;
            break;
        }
    }
    return objectIndex;
}
