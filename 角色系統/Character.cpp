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

//-----------------------------------------戰鬥----------------------------------

void Character::attack() {
    std::cout << "玩家造成了" << attackPower << "點傷害" << std::endl;
} // end attack()

void Character::defense( int damage ) {
    std::cout << "玩家承受了" << damage << "點傷害 !" << std::endl;
    battleHp -= damage;
} // end defense()

void Character::cure( int level ) {
    std:: cout << "玩家恢復了" << level/3+1 << "點生命 !" << std::endl;
    battleHp += ( level / 3 + 1 ) ;
    if ( battleHp > hp ) battleHp = hp;
} // end cure()

bool Character::isAlive(){
    if( battleHp <= 0 )return false;
    else return true;
}

void coutSpace( std::string s,int space ) {
    std::cout << s;
    for( int i = 0 ; i < space-s.length() ; i++ )
    {
        std::cout << " ";
    }
}

void Character::printStatus()
{
    coutSpace( name,6 );
    coutSpace( " Lv: " + std::to_string( level ), 8 );
    coutSpace( " ATK: " + std::to_string( attackPower ),8 );
    std::cout << " HP: ";

    //HP低於1/3會顯示紅色警示
    if( battleHp <= hp / 3 )
    {
        std::cout << (std::string( RED ) + std::to_string( battleHp ) + RESET);
    }
    else
        std::cout << battleHp;

    std::cout << "/" << hp;
    std::cout << " Money: " << (std::string( GOLD ) + std::to_string( money ) + RESET);
}