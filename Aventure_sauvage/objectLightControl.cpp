#include "objectLightControl.h"


objectType ObjectLightControl::getType() {
	return illuminationType;
}

bool ObjectLightControl::getIluminationObjectState() const{
	return iluminationObjectState;
}

void ObjectLightControl::useObject(Room* &room) {
	room->toggleIllumination();
	iluminationObjectState = !iluminationObjectState;
}

string ObjectLightControl::getUse() {
	if (iluminationObjectState) {
		return ObjectSimple::getUse()+ "turned ON ";
	}
	else {
		return ObjectSimple::getUse()+ "turned OFF ";
	}
}