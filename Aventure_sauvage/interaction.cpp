#include "interaction.h"

//Shows if there is a room in the direction the user wants to go
Room* Interaction::validDirection(string word, string  letter, Room* room) {
    if ((userInput.compare(letter) == 0 || userInput.compare(word) == 0)) {
        if (room == NULL) {
            cout << "Sorry! No rooms in that direction.\n";
            return room;
        }
        else {
            if (!room->getLocked()) {
                return room;
            }
            else {
                cout << "Sorry! No rooms in that direction.\n";
                return room;
            }
        }
    }
    else return NULL;
}


Room* Interaction::showGameResponse(Room* room) {
    //lowercase input
    getline(cin, userInput);
    for_each(userInput.begin(), userInput.end(), [](char& c) {
        c = tolower(c);
        });
    //move to another room
    Room* auxRom = validDirection(NORTH_LETTER, NORTH_WORD, room->N);
    if (auxRom != NULL) return auxRom;
    auxRom = validDirection(SOUTH_LETTER, SOUTH_WORD, room->S);
    if (auxRom != NULL) return auxRom;
    auxRom = validDirection(EAST_LETTER, EAST_WORD, room->E);
    if (auxRom != NULL) return auxRom;
    auxRom = validDirection(WEST_LETTER, WEST_WORD, room->W);
    if (auxRom != NULL) return auxRom;

    if (userInput.find(USE) != string::npos) {

        if (userInput.compare(USE) == 0) {
            cout << "Use what?" << endl;
        }
        else {
            eraseSubstring(userInput, USE" ");
            int objectIndex = room->getObjectIndex(userInput);


            if (objectIndex == -1) {
                cout << "Object not found" << endl;
            }
            else {
                cout << room->objects[objectIndex]->getUse() << endl;
                room->objects[objectIndex]->useObject(room);
            }
        }
        return NULL;
    }

    else if (userInput.find("look") != string::npos) {
        Print print;
        if (userInput.compare("look") == 0) {
            print.printName(room);
            print.printDescription(room);
            print.printObjects(room);
            print.printAdjacentRooms(room);
        }
        else {
            eraseSubstring(userInput, "look ");
            cout << "Look for object " << userInput << endl;

            int objectIndex = room->getObjectIndex(userInput);
            if (objectIndex == -1) {
                cout << "Object not found." << endl;
            }
            else {
                cout << room->objects[objectIndex]->getDescription() << endl;
            }
        }
        return NULL;
    }
    else {
        cout << "Invalid entry/I don't know that. \n\n";
        return room;
    }
}

void Interaction::eraseSubstring(std::string& myString, const std::string& eraseThis)
{
    // Search if what I want to erase is in the string
    size_t pos = myString.find(eraseThis);
    if (pos != std::string::npos)
    {
        // Erase eraseThis from string
        myString.erase(pos, eraseThis.length());
    }
}
