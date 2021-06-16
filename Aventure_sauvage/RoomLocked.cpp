#include "roomLocked.h"

bool RoomLocked::getLocked() {
	return locked;
}

void RoomLocked::toggleLocked() {
	locked = !locked;
}