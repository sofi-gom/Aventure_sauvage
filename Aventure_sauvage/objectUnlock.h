#pragma once
#include "room_.h"
using namespace std;

class ObjectUnlock :public ObjectSimple {
public:
	ObjectUnlock(string name, string description, string use, Room* openHiddenZone) :ObjectSimple(name, description, use) { this->openHiddenZone = openHiddenZone; }
	bool getRestrictedZoneOpener();
	objectType getType()override;
	void useObject(Room* room)override; 
private:
	Room* openHiddenZone;
	
};

