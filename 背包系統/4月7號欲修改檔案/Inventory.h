#pragma once
#include "ItemSystem.h"
#include <unordered_map>
#include <string>

class Inventory {
private:
    std::unordered_map<std::string, InventoryItem> items;  // 儲存物品，鍵為 itemId
    int maxSlots;

public:
    Inventory(int max = 20);  // 背包最大容量

    bool addItem(Item* item, int quantity = 1);  // 向背包添加物品
    bool removeItem(const std::string& itemId, int quantity = 1);  // 從背包中移除物品
    void showInventory() const;  // 顯示背包中的所有物品

    std::string serialize() const;  // 序列化背包資料
    bool deserialize(const std::string& data, ItemSystem& itemSystem);  // 反序列化背包資料
};
