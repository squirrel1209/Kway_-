#include "Character.h"

Character::Character() : name(""), password(""), level(1), hp(100), money(500), attackPower( 10 ), inventory( 20 ) {}

void Character::showStatus() const {
    std::cout << "玩家: " << name << " | 等級: " << level << " | HP: " << hp << " | 金錢: " << money << " | 攻擊力: " << attackPower << std::endl;
} // end showStatus()

std::string Character::toString() const {
    std::string data = name + "\n" + password + "\n" +
                       std::to_string( level ) + "\n" +
                       std::to_string( hp ) + "\n" +
                       std::to_string( money ) + "\n" +
                       std::to_string( attackPower ) + "\n";

    data += inventory.serialize();  // 將背包資料接在後面
    return data;
} // end toString()

// 從字串中解析出玩家資料（反序列化）
Character Character::fromString( const std::string& data ) {
    std::istringstream iss( data );  // 用字串串流處理每一行資料

    std::string name, password;
    int level, hp, money, attackPower;

    // 一行一行讀取資料
    std::getline(iss, name);
    std::getline(iss, password);
    iss >> level;      iss.ignore();
    iss >> hp;         iss.ignore();
    iss >> money;      iss.ignore();
    iss >> attackPower;iss.ignore();

    // 讀取剩下的資料作為背包內容
    std::string inventoryData;
    std::getline(iss, inventoryData, '\0');  // 把剩下的所有文字都抓進來

    Inventory inv;
    inv.deserialize( inventoryData );  // 利用 ItemSystem 重建背包內容

    Character ch(name, password, level, hp, money, attackPower);
    ch.setInventory(inv);  // 指定背包

    return ch;
} // end fromString()

// 設定背包
void Character::setInventory( const Inventory& inv ) {
    inventory = inv;
}

// 取得背包，測試用
Inventory& Character::getInventory() {
    return this -> inventory;
}