#include<vector>

class Shop {
private:
    static vector<Item*> inventory;
    
public:
    void addItem( Item* item );
    void showItems() const;
    void buyItem( Character& player, int index );
};
