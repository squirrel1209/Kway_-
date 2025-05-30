#include "Inventory.h"

// 建構函數，初始化背包最大容量
Inventory::Inventory(int max) : maxSlots( max ) {}

// 向背包中添加物品
bool Inventory::addItem( Item* item, int quantity ) {
    std::string itemId = item->getInfo().id;

    if ( items.size() < maxSlots ) {
        auto it = items.find( itemId );
        if ( it != items.end() ) {
            it->second.quantity += quantity;  // 更新數量
        } // end if 
        
        else {
            items[itemId] = { item, quantity };  // 新增物品
        } // end else
        return true;
    } // end if

    return false;
} // end addItem()

// 從背包中移除指定數量的物品
bool Inventory::removeItem( const std::string& itemId, int quantity ) {
    auto it = items.find( itemId );

    if ( it != items.end() ) {
        if ( it->second.quantity >= quantity ) {
            it -> second.quantity -= quantity;

            if ( it->second.quantity == 0 ) {
                items.erase(it);  // 刪除物品
            } // end if

            return true;
        } // end if
    } // end if

    return false;
} // end removeItem()

void Inventory::showInventory() const {
    for ( const auto& pair : items ) {
        if ( pair.second.item != nullptr ) {
            pair.second.item -> print();  // 呼叫 Item 的 printf()
            std::cout << " 數量: " << pair.second.quantity << std::endl;
        } // end if
        
        else {
            std::cout << "未知物品 ID: " << pair.first << " 數量: " << pair.second.quantity << std::endl;
        } // end else
    } // end for
} // end showInventory()
