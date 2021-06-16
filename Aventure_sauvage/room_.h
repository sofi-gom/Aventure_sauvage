#pragma once
#include <stdio.h>
#include <iostream>
#include<string>
#include <algorithm>
#include "objectSimple.h"

#include <vector>

#define SOUTH_WORD "sur"
#define SOUTH_LETTER "s"
#define NORTH_WORD "norte"
#define NORTH_LETTER "n"
#define EAST_WORD "este"
#define EAST_LETTER "e"
#define WEST_WORD "west"
#define WEST_LETTER "w"
#define USE "use"


using namespace std;

typedef enum {
    room,
    dynamicLightRoom,
}roomType;

class Room {
public:
    Room(string name, string description);
    vector<unique_ptr<ObjectSimple>> objects;
    Room* N;
    Room* E;
    Room* S;
    Room* W;

    string getName();
    virtual string getDescription();
    virtual vector<ObjectSimple*> getObjects();
    virtual void toggleIllumination();
    virtual bool getLocked();
    virtual void toggleLocked();
    virtual roomType getType();
    virtual int  getObjectIndex(string objectName);

    private:

    string name;
    string description;

};



