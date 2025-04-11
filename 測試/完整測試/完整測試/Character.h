#ifndef CHARACTER_H   // 如果 CHARACTER_H 尚未定義，則執行下面的內容
#define CHARACTER_H   // 定義 CHARACTER_H，防止重複定義

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Inventory.h"

// ANSI 顏色定義
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define GOLD    "\033[1;33m"

class Slime;
class Goblin;
class Dragon;
void coutSpace( std::string s,int space );


class Character {
    friend class Shop;

protected:
    std::string name;         // 玩家名稱
    std::string password;     // 密碼（簡化示範用，實際上不建議明文存儲）
    int level;                // 等級
    int hp;                   // 血量
    int money;                // 金錢
    int attackPower;          // 攻擊力
    Inventory inventory;      // 背包（包含持有物品）

    int battleHp;      // 戰鬥用血量
public:
    void showPlayInventory() const { inventory.showInventory(); } // 顯示背包物品

    Character();
    Character( const std::string& name, const std::string& password, int level = 1, int hp = 100, int money = 500, int attackPower = 10 ,int maxSlots = 20 ) 
        : name( name ), password( password ),  level( level ), hp( hp ), money( money ), attackPower( attackPower ), inventory( maxSlots ) { battleHp = hp; }
        
    // 顯示玩家狀態
    void showStatus() const ;
    
    // 取得玩家名字 
    std::string getName() const { return name; }
    
    // 取得玩家密碼
    std::string getPassword() const { return password; }
    
    // 轉換成可儲存的格式（序列化）
    std::string toString() const ;
    
    // 從字串中解析出玩家資料（反序列化）
    static Character fromString( const std::string& data );

    
    // 存取背包物件
    //const Inventory& getInventory() const;

    // 測試用
    Inventory& getInventory();

    void setInventory( const Inventory& inventory );


    //---------------------------------------------戰鬥---------------------------------------------
    void printStatus();
    void attack();
    void defense(int damage);
    void cure(int level);
    bool isAlive();
    friend void battle ( Character &p , Slime &m );
    friend void battle ( Character &p , Goblin &m );
    friend void battle ( Character &p , Dragon &m );
    friend void Quest  ( Character &p);
};


#endif // CHARACTER_H   // 結束條件，防止重複包含