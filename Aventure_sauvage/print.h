
#pragma once
#include "room_.h"


class Room;

class Print {
public:
    void printName(Room* &room) const;
    void printDescription(Room* &room) const;
    void printAdjacentRooms(Room* &room) const;
    void printObjects(Room* &room) const;
};

