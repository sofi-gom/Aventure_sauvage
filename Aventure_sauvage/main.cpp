
#include <iostream>
#include "carte.h"

using namespace std;


int main() {
    //creates the map
    Map map = Map();
     
    while (true) {
        map.nextRoom();
    }
    return 0;
}
