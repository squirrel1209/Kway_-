#ifndef CHARACTER_H   // 如果 CHARACTER_H 尚未定義，則執行下面的內容
#define CHARACTER_H   // 定義 CHARACTER_H，防止重複定義

#include <sstream>
#include <string>
#include <iostream> 

using namespace std;

class Character {
private:
    string password;         // 密碼
 
    string name;         // 角色的名稱
    int level;           // 等級
    int attackPower;     // 攻擊力 
    int mp;              // 魔量 
    int hp;              // 生命值
    int exp;             // 經驗值 
    int money;           // 金錢

    //ItemSystem backpack  // 背包
    
public:
    // 預設建構子，初始化角色屬性
    Character() : level(1), exp(0), money(100), attackPower(10), mp(100), hp(100) {}
    
    // 帶參數的建構子，從現有數據建立角色
    Character( string password ) 
        : password(password), level(1), exp(0), money(0), attackPower(10), mp(100), hp(100) {}
    
    Character( string password, string name, int level, int exp, int money, int attackPower, int mp, int hp )
        : password(password), level(level), exp(exp), money(money), attackPower(attackPower), mp(mp), hp(hp) {}
    
    // 將玩家資料序列化為字串，方便存檔
    string serialize();
    
    // 解析玩家數據
    static Character deserialize( const string& data );
    
    // 顯示角色資訊 (可用於測試)
    void display();
};

#endif // CHARACTER_H   // 結束條件，防止重複包含
