#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

// 物品的靜態資料結構
struct ItemInfo {
    std::string id;          // 物品ID
    std::string name;        // 物品名稱
    std::string description; // 物品描述
    int price = 0;           // 物品價格
    int attack = 0;          // 物品的攻擊力（唯一屬性） 
};

// 物品類別，代表遊戲中的單一物品實例
class Item {
private:
    ItemInfo info;    

public:
    // 建構子：傳入物品資料並初始化
    Item( const ItemInfo& data );

    bool operator==( const Item& other ) const; //  比較運算子重載，用於判斷兩個物件是否相等

    // 取得物品靜態資料
    const ItemInfo& getInfo() const;

    // 顯示物品的詳細資訊
    void print() const;
};

// 物品管理系統，負責物品的載入和創建
class ItemSystem {
private:
    std::unordered_map<std::string, ItemInfo> itemDefinitions;

public:
    // 設定 Shop 為友元類別，這樣 Shop 就可以訪問 itemDefinitions
    friend class Shop;

    ItemSystem();  // 在建構子裡載入預設物品資料
    
    // 根據物品ID創建物品實例
    Item* createItem( const std::string& id );
};