
#include <sstream>
#include <string>

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

    ItemSystem backpack  // 背包
    
public:
    // 預設建構子，初始化角色屬性
    Character() : level(1), exp(0), money(100), attackPower(10), mp(100), hp(100) {}
    
    // 帶參數的建構子，從現有數據建立角色
    Character( string password ) 
        : password(password), level(1), exp(0), money(0), attackPower(10), mp(100), hp(100) {}
    
    // 將玩家資料序列化為字串，方便存檔
    string serialize();
    
    // 解析玩家數據
    static Character deserialize( const string& data );
    
    // 顯示角色資訊 (可用於測試)
    void display();
};
