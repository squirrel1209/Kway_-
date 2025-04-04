#ifndef CHARACTER_H   // 如果 CHARACTER_H 尚未定義，則執行下面的內容
#define CHARACTER_H   // 定義 CHARACTER_H，防止重複定義

#include <iostream>
#include <string>

using namespace std;

class Character {
protected:
    string name;
    string password;
    int level;
    int hp;
    int money;
    
public:
    Character();
    Character( string name, string password, int level = 1, int hp = 100, int money = 500 ) 
        : name( name ), password( password ) {}
        
    Character() : name( name ), password( password ),  level( level ), hp( hp ), money( money ) {}


    // 顯示玩家狀態
    void showStatus() const ;
    
    // 取得玩家名字 
    string getName() const { return name; }
    
    // 取得玩家密碼
    string getPassword() const { return password; }
    
    // 轉換成可儲存的格式（序列化）
    string toString() const ;
    
    // 從字串中解析出玩家資料（反序列化）
    static Character& fromString( const string& data );
    
}; 
#endif // CHARACTER_H   // 結束條件，防止重複包含
