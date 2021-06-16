#pragma once
#include "room_.h"
#include "roomDynamicallyIlluminated.h"
using namespace std;

class ObjectLightControl : public ObjectSimple {//RoomMaybeLight* roomMaybeLight
public:
	ObjectLightControl(string name, string description, string use) :ObjectSimple(name, description, use) {}//ajoute de pointeur attribut
	bool getIluminationObject();

	objectType getType()override;
	void useObject(Room* room) override;
	string getUse()override;
private:
	bool iluminationObject;
};


