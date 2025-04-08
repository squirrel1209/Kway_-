#include "Shop.h"

Shop::Shop( ItemSystem& system ) : itemSystem( system ) {}  // 傳入 ItemSystem 參考作為建構子

void Shop::showItems() const {
    std::cout << "商店擁有的物品：\n";

    // 直接從 itemDefinitions 取得所有物品並顯示
    for ( const auto& pair : itemSystem.itemDefinitions ) {
        const ItemInfo& item = pair.second;
        std::cout << "物品ID: " << item.id << ", 物品名稱: " << item.name << ", 價格: " << item.price << "\n";
    } // end for

} // end ShowItems

void Shop::buyItem( Character& player, const std::string& itemId ) {
    auto it = itemSystem.itemDefinitions.find( itemId );

    if ( it != itemSystem.itemDefinitions.end() ) {
        const ItemInfo& item = it->second;
        // 假設有方法處理購物邏輯
        std::cout << player.getName() << " 購買了 " << item.name << "，價格為 " << item.price << "。\n";
    } // end if
    
    else {
        std::cout << "找不到物品，請確認物品ID。\n";
    } // end else
} // end buyItem()

void Shop::sellItem( Character& player, const Item& item ) {
    // 假設有方法處理賣出邏輯
    std::cout << player.getName() << " 賣出了 " << item.getInfo().name << "。\n";
} // end sellItem()
