// main.cpp
#include "Inventory.h"
#include "ItemSystem.h"
#include <iostream>

int main() {
    ItemSystem itemSys;

    // 建立物品
    Item* sword = itemSys.createItem("sword_iron");
    Item* axe_steel = itemSys.createItem("axe_steel");
    Item* sword_dragon = itemSys.createItem("sword_dragon");

    // 建立背包
    Inventory bag(5);

    // 加入物品
    bag.addItem(sword, 1);
    bag.addItem(axe_steel, 3);
    bag.addItem(sword_dragon, 2);

    // 顯示背包內容
    std::cout << "=== 初始背包內容 ===" << std::endl;
    bag.showInventory();

    // 移除物品
    bag.removeItem("axe_steel", 1);

    std::cout << "\n=== 移除 1 個axe_steel後 ===" << std::endl;
    bag.showInventory();

    // 釋放記憶體（注意！你之後可以改用 smart pointer 管理）
    delete sword;
    delete axe_steel;
    delete sword_dragon;
    system( "pause" );
    return 0;
}
