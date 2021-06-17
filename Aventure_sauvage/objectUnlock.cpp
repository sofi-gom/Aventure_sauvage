#include "objectUnlock.h"

objectType ObjectUnlock::getType() {
	return unlockType;
}

bool ObjectUnlock::getRestrictedZoneOpener() const{
	return openHiddenZone;
}

void ObjectUnlock::useObject(Room* &room) {
	openHiddenZone->toggleLocked();
}

string ObjectUnlock::getUse() {
	if (openHiddenZone->getLocked()) {
		return ObjectSimple::getUse() + " opened the " + openHiddenZone->getName() + "!";
	}
	else {
		return ObjectSimple::getUse() + " closed the " + openHiddenZone->getName() + "!";
	}
}
