
#include <string>
using namespace std;

typedef enum {
    simpleType,
    illuminationType,
    unlockType
}objectType;

class Room;

class ObjectSimple {
public:

    ObjectSimple(string name, string description, string use);

    string getName();
    string getDescription();
    virtual string getUse();
    //virtual string getUse(Room* room) {}
    virtual objectType getType();
    virtual void useObject(Room* room) {}


private:
    string name;
    string description;
    string use;
};