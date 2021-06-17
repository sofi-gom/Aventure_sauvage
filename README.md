---------DESCRIPTION OF THE GAME:-----------------

This is the map of a zoo. The zoo has normal rooms, rooms that can change their lighting and rooms that can be opened or closed. Each room can have a different list of objects. An " illumination object " can change the lighting of a room with dynamic lighting, an "object unlock" can unlock (or lock) a room to enter a restricted area. The restricted rooms are not shown in the options of rooms you can go to, until you unlock it.

The user can move around the map by choosing to move North, South, East, or West. The option " look " can show you at all times which room you are in. In you write "look" followed by the name of an object found in the room, you will get its description. To use the object you have to write "use" plus the name of the object. 

---------DESCRIPTION OF THE CLASSES:-----------------

Carte: Describes the map of the game. It contains all the rooms and its connections. It contains a function to move from one room to another. 

Interaction: It contains the response of the game to the commands of the user. It verifies that the information the user wants to use is available and gives the response, if it is not it gives a message saying it is not available.

Print: No cout is made on the class itself, they are mostly managed by a class Print. Here you can find the methods to print a list of objects, the adjacent rooms to a room and other room information including the name and description.

objectLightControl: This object can affect the state of a room with dynamic lighting. Usually using a switch, we can know if it is in the ON/OFF position by using its attribute: illuminationObjectState. It affects the room it is located in.

ObjectSimple: This object will inherit to objectLightControl and Object Unlock. It has a name and a description. We use the properties of polymorphism to redefine methods such as UseObject().

Object Unlock: This object will open/close a room that is restricted, usually a key. If the restricted room is open, we can now see it as part of the list of rooms we can visit. 

Room_: The regular room has a list of objects, a name and a description.

RoomDynamicallyIlluminated: This room has the same things are the regular room but it also has an attribute in its constructor to know whether the room is illuminated.

roomLocked: This room has the same things are the regular room but it also has an attribute in its constructor to know whether the room is locked.
