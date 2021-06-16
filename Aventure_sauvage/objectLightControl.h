#pragma once
#include "room_.h"
#include "roomDynamicallyIlluminated.h"
using namespace std;

class ObjectLightControl : public ObjectSimple {
public:
	ObjectLightControl(string name, string description, string use) :ObjectSimple(name, description, use) {}//Suggestion: add pointer attribute

	bool getIluminationObjectState();
	objectType getType()override;
	void useObject(Room* room) override;
	string getUse()override;
private:
	bool iluminationObjectState;
};


