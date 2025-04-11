#pragma once
#include "ItemSystem.h"
#include "Character.h"
#include <string>
#include <iostream>

class Shop {
private:
    ItemSystem& itemSystem;  // 引用 ItemSystem

public:
    // 傳入 ItemSystem 參考作為建構子
    Shop( ItemSystem& system );

    // 顯示商店目前有販售的物品
    void showItems() const;

    // 玩家購買物品
    void buyItem( Character& player, const std::string& itemId );

    // 玩家賣出物品
    void sellItem( Character& player, const Item& item );
};
