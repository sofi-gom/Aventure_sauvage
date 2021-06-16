#pragma once
#include "room_.h"

class RoomLocked : public Room {
public:
	RoomLocked(string name, string description, bool locked) :Room(name, description) { this->locked = locked; }

	bool getLocked()override;
	void toggleLocked()override;
private:
	bool locked;

};