#include "roomDynamicallyIlluminated.h"

roomType RoomMaybeLight::getType() {
	return dynamicLightRoom;
}

void RoomMaybeLight::toggleIllumination() {
	illumination = !illumination;
}

bool RoomMaybeLight::getIllumination() {
	return illumination;
}

string RoomMaybeLight::getDescription(){
	if (!illumination) {
		return "The room is dark and you can also see the adjacent rooms. ";
	}
	else return Room::getDescription();
}


int  RoomMaybeLight::getObjectIndex(string objectName) {
	int objectIndex = -1;

	//looks for object
	for (int i = 0; i < objects.size(); i++) {
		if (illumination) {
			if (objects[i]->getName().find(objectName) != string::npos) {
				objectIndex = i;
				break;
			}
		}
		else {
			if (objects[i]->getName().find(objectName) != string::npos && (objects[i]->getType()==illuminationType)) {
				objectIndex = i;
				break;
			}
		}
		
	}
	return objectIndex;
}

//VERSION 1


vector < ObjectSimple*> RoomMaybeLight::getObjects() {
	if (getIllumination()) {
		return Room::getObjects();//cambio objects
	} 
	else {
		vector < ObjectSimple*> illuminationObjects;
		for (int i = 0; i < Room::getObjects().size(); i++) {
			if (Room::getObjects()[i]->getType() == illuminationType) {
				illuminationObjects.push_back(Room::getObjects()[i]);
			}
		}
		return illuminationObjects;
	}
}

