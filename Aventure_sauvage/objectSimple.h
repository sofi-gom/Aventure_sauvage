
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
    virtual objectType getType();
    virtual void useObject(Room* room) {}//doesn't affect anything when used


private:
    string name;
    string description;
    string use;
};