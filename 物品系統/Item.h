#include <string>

using namespace std;

class Item {
protected:
    string name;
    int price;
    
public:
    Item( string name, int price ) : name( name ), price( price ) {}
};

class Weapon : public Item {
private:
    int attackPower;

public:
    Weapon( string name, int price, int attackPower ) : Item( name, price ), attackPower( attackPower ) {}
    
    
};
