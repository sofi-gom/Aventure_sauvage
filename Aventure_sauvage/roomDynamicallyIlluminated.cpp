#include "roomDynamicallyIlluminated.h"

roomType RoomMaybeLight::getType() {
	return dynamicLightRoom;
}

void RoomMaybeLight::toggleIllumination() {
	illuminationState = !illuminationState;
}

bool RoomMaybeLight::getIllumination() const{
	return illuminationState;
}
//For rooms with dynamic lighting on change the description based on its state
string RoomMaybeLight::getDescription(){
	if (!illuminationState) {
		return "The room is dark and you can only see the adjacent rooms. ";
	}
	else return Room::getDescription();
}

//Finds where in the objets vector, a certain object is located
int  RoomMaybeLight::getObjectIndex(string objectName) {
	int objectIndex = -1;

	//looks for object
	for (int i = 0; i < objects.size(); i++) {
		if (illuminationState) {
			if (objects[i]->getName().find(objectName) != string::npos) {
				objectIndex = i;
				break;
			}
		}
		else {//if the room's light is OFF, we only look for the first object that can affect lighting
			if (objects[i]->getName().find(objectName) != string::npos && (objects[i]->getType()==illuminationType)) {
				objectIndex = i;
				break;
			}
		}
	}
	return objectIndex;
}

//returns either the list with all the objects if the light of the room is ON, or a list of objects that can change lighting if the light of the room is OFF
vector < ObjectSimple*> RoomMaybeLight::getObjects() {
	if (getIllumination()) {
		return Room::getObjects();
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

