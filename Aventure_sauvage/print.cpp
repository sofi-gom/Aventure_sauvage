#include "print.h"

void Print::printName(Room* room) {
    cout << "-----" << room->getName() << "-----" << "\n";
}

void Print::printDescription(Room* room) {
    cout << room->getDescription() << "\n";
}

void Print::printObjects(Room* room) {
    if (room->getObjects().size() > 0) {
        cout << "\nObject list: " << endl;
        for (int i = 0; i < room->getObjects().size(); i++) cout << " " << room->getObjects()[i]->getName() << endl; // to get the object type room->getObjects()[i]->getType()
        cout << "To use an object write 'use' and the name of the object you want to use. " << endl;
    }
    else cout << "There are no objects in this room." << endl;
    
}

void Print::printAdjacentRooms(Room* room) {
    cout << "\nThese are the surrounding rooms: \n";
    if (room->N != NULL) {
        if (!room->N->getLocked())cout << room->N->getName() << " [" << NORTH_LETTER << "]\n";
    }
    if (room->S != NULL) {
        if (!room->S->getLocked())cout << room->S->getName() << " [" << SOUTH_LETTER << "]\n";
    }
    if (room->E != NULL) {
        if (!room->E->getLocked())cout << room->E->getName() << " [" << EAST_LETTER << "]\n";
    }
    if (room->W != NULL) {
        if (!room->W->getLocked())cout << room->W->getName() << " [" << WEST_LETTER << "]\n";
    }
    cout << "Choose a direction to enter another room. \n";
}