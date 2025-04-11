#pragma once
#include "ItemSystem.h"
#include <unordered_map>
#include <sstream>

struct InventoryItem {
    Item* item;   // 指向物品實例
    int quantity; // 數量
};

class Inventory {
private:
    std::unordered_map<std::string, InventoryItem> items;  // 使用 unordered_map 儲存物品，鍵為 itemId
    int maxSlots;
    
public:
Inventory(int max = 20);  // 建構函數，初始化背包的最大容量

//Inventory( const Inventory& )

// 向背包中添加物品，如果物品已存在，則增加數量
bool addItem( Item* item, int quantity = 1 );

// 向背包中添加物品（使用物品 ID 字串）
bool addItem( const std::string& id, int quantity );

// 從背包中移除指定數量的物品
bool removeItem( const std::string& itemId, int quantity = 1 );

// 顯示背包中的所有物品及其數量
void showInventory() const;


// 序列化背包資料
std::string serialize() const;

// 反序列化背包資料
bool deserialize(const std::string& data );  


// 假設 getItemById 是根據 ID 找到物品的函數
Item* getItemById( const std::string& id );
};