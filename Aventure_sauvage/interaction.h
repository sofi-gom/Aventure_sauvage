#pragma once
#include "room_.h"
#include "print.h"


class Interaction {
public:
    Room* showGameResponse(Room* &room);
    
private:
    string userInput;
    void eraseSubstring(std::string& mystring, const std::string& toErase);
    Room* validDirection(string word, string  letter, Room*& room);
};

