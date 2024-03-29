#pragma once
#include <iostream>
#include "room_.h"
#include "roomDynamicallyIlluminated.h"
#include "roomLocked.h"

class Map {
public:

    Map();
    void nextRoom();

private:

    Room* shop = new RoomMaybeLight("Souvenir store ", "Here you can buy little gifts.",false);
    Room* entrance = new RoomMaybeLight("Entrance", "Here you can find the main gate of the zoo.",false);
    Room* desertAnimals = new Room("Desert animal section", "Here you can find snakes! ");
    Room* forestAnimals = new Room("Forest animal area", "Here you can find trees and a lake.");
    Room* tropicalAnimals = new Room("Tropical animal area", "Here you can find monkeys. ");
    Room* restrictedCactusZone = new RoomLocked("Restricted cactus zone", "Here you can find cactus. ", true);
    Room* restrictedLionFeedingZone = new RoomLocked("Restricted lion feeding zone", "Here you can find lions. ",true);
    Room* currentRoom;
};


