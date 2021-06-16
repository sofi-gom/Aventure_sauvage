#include "carte.h"
#include "room_.h"
#include "objectUnlock.h"
#include "objectLightControl.h"
#include "print.h"
#include "Interaction.h"


using namespace std;

Map::Map() {
    printf("\033[93m***Fun Game***\n\n");
    entrance->W = shop;
    entrance->N = desertAnimals;

    ///objetos de la tiendita
    shop->objects.push_back(make_unique<ObjectSimple>("un piano", "el piano tiene muchas teclas", "estas tocando una cancion en el piano"));
    shop->objects.push_back(make_unique <ObjectSimple>("un lapiz", "el lapiz tiene la punta rota", "estas escribiendo palabras con el lapiz"));
    shop->objects.push_back(make_unique <ObjectLightControl>("un switch", "el switch va a prender la luz", "la luz "));

    //objetos de  animales del desierto
    desertAnimals->objects.push_back(make_unique<ObjectUnlock>("una llave  de los cactus", "la llave es dorada", "la llave abre la puerta de la zona escondida de cactus", restrictedCactusZone));
    desertAnimals->objects.push_back(make_unique<ObjectSimple>("una botella de agua", "la botella de agua no esta abierta", "te tomas el agua de la botella"));
    desertAnimals->objects.push_back(make_unique<ObjectLightControl>("un switch", "el switch va a prender la luz", "la luz "));
   //objetos de la entrada
    entrance->objects.push_back(make_unique<ObjectLightControl>("un switch", "el switch va a prender o apagar la luz", "la luz "));



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
    currentRoom = entrance;
}

void Map::nextRoom() {
    
    Print print;
    Interaction interaction;
    print.printName(currentRoom);
    print.printDescription(currentRoom);
    print.printObjects(currentRoom);
    print.printAdjacentRooms(currentRoom);
    Room* moveFromRoom;
    do {
        moveFromRoom = interaction.showDoors(currentRoom);
        cout << endl;
    } while (moveFromRoom == NULL);
    currentRoom = moveFromRoom;
}
