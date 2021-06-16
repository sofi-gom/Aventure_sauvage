#include "objectUnlock.h"

objectType ObjectUnlock::getType() {
	return unlockType;
}

bool ObjectUnlock::getRestrictedZoneOpener() {
	return openHiddenZone;
}

void ObjectUnlock::useObject(Room* room) {
	openHiddenZone->toggleLocked();
}
