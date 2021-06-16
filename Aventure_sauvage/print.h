
#pragma once
#include "room_.h"


class Room;

class Print {
public:
    void printName(Room* room);
    void printDescription(Room* room);
    void printAdjacentRooms(Room* room);
    void printObjects(Room* room);
};

