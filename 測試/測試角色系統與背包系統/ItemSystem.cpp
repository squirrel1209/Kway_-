#include "ItemSystem.h"

Item::Item( const ItemInfo& data ) : info( data ) {}

bool Item::operator==( const Item& other ) const {
    return info.id == other.info.id && info.name == other.info.name &&
              info.description == other.info.description &&
              info.price == other.info.price && info.attack == other.info.attack; // 比較物品的靜態資料是否相等
} // end operator==()

// 取得物品的靜態資料
const ItemInfo& Item::getInfo() const {
    return info; // 返回物品的靜態資料
} // end getInfo()

// 顯示物品的詳細資訊（名稱、價格、描述、攻擊力等）
void Item::print() const {
    std::cout << "[Item] " << info.name << " (" << info.id << ")\n";  // 顯示物品名稱與ID
    std::cout << "Price: " << info.price << "\n";                       // 顯示物品價格
    std::cout << info.description << "\n";                              // 顯示物品描述
    std::cout << "Attack: " << info.attack << "\n";                     // 顯示物品的攻擊力
} // end print()

// ItemSystem 類別建構子：載入預設的物品資料
ItemSystem::ItemSystem() {
    // 鐵劍
    ItemInfo sword;
    sword.id = "sword_iron";
    sword.name = "鐵劍";
    sword.description = "普通的鐵劍，適合新手使用。";
    sword.price = 50;
    sword.attack = 10;

    // 鋼斧
    ItemInfo axe;
    axe.id = "axe_steel";
    axe.name = "鋼斧";
    axe.description = "鋼製的斧頭，攻擊力更高。";
    axe.price = 80;
    axe.attack = 15;

    // 龍牙劍
    ItemInfo dragonSword;
    dragonSword.id = "sword_dragon";
    dragonSword.name = "龍牙劍";
    dragonSword.description = "傳說中的龍牙劍，擁有極高的攻擊力。";
    dragonSword.price = 200;
    dragonSword.attack = 50;

    // 長弓
    ItemInfo longBow;
    longBow.id = "bow_long";
    longBow.name = "長弓";
    longBow.description = "適合遠距離攻擊的長弓。";
    longBow.price = 120;
    longBow.attack = 30;

    // 巨錘
    ItemInfo giantHammer;
    giantHammer.id = "hammer_giant";
    giantHammer.name = "巨錘";
    giantHammer.description = "重型的巨錘，能造成強大的打擊。";
    giantHammer.price = 150;
    giantHammer.attack = 40;

    // 將物品資料存入物品定義（ID -> ItemInfo）
    itemDefinitions[sword.id] = sword;
    itemDefinitions[axe.id] = axe;
    itemDefinitions[dragonSword.id] = dragonSword;
    itemDefinitions[longBow.id] = longBow;
    itemDefinitions[giantHammer.id] = giantHammer;
} // end ItemSystem()

// 根據物品ID創建一個物品實例
Item* ItemSystem::createItem( const std::string& id ) {
    if ( !itemDefinitions.count(id) ) return nullptr;  // 如果沒有該物品ID，返回 nullptr
    return new Item( itemDefinitions[id] );  // 根據物品ID創建物品實例並返回
}