#include "carte.h"
#include "room_.h"
#include "objectUnlock.h"
#include "objectLightControl.h"
#include "print.h"
#include "Interaction.h"


using namespace std;

Map::Map(){
    printf("\033[93m>>>WILD ADVENTURE<<<\n\n");
    
    ///objets in the souvenir shop
    shop->objects.push_back(make_unique<ObjectSimple>("A piano", "The piano has a lot of keys", "You are playing a song on the piano"));
    shop->objects.push_back(make_unique <ObjectSimple>("A pencil", "The pencil has a broken tip", "You are writing a poem with the pencil"));
    shop->objects.push_back(make_unique <ObjectLightControl>("A switch", "The switch can turn ON/OFF the light", "the light "));

    //objets in the desert animal area
    desertAnimals->objects.push_back(make_unique<ObjectUnlock>("A key to open the cactus zone", "The key is golden", "The key", restrictedCactusZone));
    desertAnimals->objects.push_back(make_unique<ObjectSimple>("A bottle of water", "The bottle of water is not open", "te tomas el agua de la botella"));
   //objects at the entrance
    entrance->objects.push_back(make_unique<ObjectLightControl>("A switch", "The switch can turn ON/OFF the light", "the light "));
    //objects in the forest animal section
    forestAnimals->objects.push_back(make_unique<ObjectUnlock>("A key to open the lion feeding area.", "The key is golden", "The key ", restrictedLionFeedingZone));

    //connexions between the rooms
    entrance->W = shop;
    entrance->N = desertAnimals;
    shop->E = entrance;
    desertAnimals->S = entrance;
    desertAnimals->E = forestAnimals;
    desertAnimals->N = tropicalAnimals;
    tropicalAnimals->S = desertAnimals;
    forestAnimals->W = desertAnimals;
    desertAnimals->W = restrictedCactusZone;
    shop->N = restrictedCactusZone;
    restrictedCactusZone->E = desertAnimals;
    restrictedCactusZone->S = shop;
    restrictedLionFeedingZone->S = forestAnimals;
    restrictedLionFeedingZone->W = tropicalAnimals;
    forestAnimals->N = restrictedLionFeedingZone;
    tropicalAnimals->E = restrictedLionFeedingZone;
    currentRoom = entrance;
    
}
//move to another room
void Map::nextRoom(){
    
    Print print;
    Interaction interaction;
    print.printName(currentRoom);
    print.printDescription(currentRoom);
    print.printObjects(currentRoom);
    print.printAdjacentRooms(currentRoom);
    Room* moveFromRoom;
    do {
        moveFromRoom = interaction.showGameResponse(currentRoom);
        cout << endl;
    } while (moveFromRoom == NULL);
    currentRoom = moveFromRoom;
}
