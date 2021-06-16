#include "objectLightControl.h"


objectType ObjectLightControl::getType() {
	return illuminationType;
}

bool ObjectLightControl::getIluminationObject() {
	return iluminationObject;
}

//cambio
void ObjectLightControl::useObject(Room* room) {
	room->toggleIllumination();
	iluminationObject = !iluminationObject;
}

string ObjectLightControl::getUse() {
	if (iluminationObject) {
		return "se prendio " + ObjectSimple::getUse();
	}
	else {
		return "se apago " + ObjectSimple::getUse();
	}
}