#pragma once
#include "room_.h"
using namespace std;

class RoomMaybeLight:public Room {
public:
	RoomMaybeLight(string name, string description, bool illumination) :Room(name, description) { this->illuminationState = illumination; }

	bool getIllumination() const;
	void toggleIllumination();
	roomType getType()override;
	int  getObjectIndex(string objectName)override;
	string getDescription() override;
	vector <ObjectSimple*>getObjects() override;

private:
	bool illuminationState;
};
