#include "Character.h"

Character::Character() : name(""), password(""), level(1), hp(100), money(500) {}

void Character::showStatus() const {
    cout << "玩家: " << name << " | 等級: " << level << " | HP: " << hp << " | 金錢: " << money << endl;
} // end showStatus()

string Character::toString() const {
    return name + "\n" + password + "\n" + to_string( level ) + "\n" + to_string( hp ) + "\n" + to_string( money ) + "\n";
} // end toString()

// 從字串中解析出玩家資料（反序列化）
Character& Character::fromString( const string& data ) {
    size_t pos1 = data.find( "\n" );
    string name = data.substr( 0, pos1 );

    size_t pos2 = data.find( "\n", pos1 + 1 );
    string password = data.substr( pos1 + 1, pos2 - pos1 - 1 );

    size_t pos3 = data.find( "\n", pos2 + 1 );
    int level = stoi( data.substr( pos2 + 1, pos3 - pos2 - 1 ) );

    size_t pos4 = data.find( "\n", pos3 + 1 );
    int hp = stoi( data.substr( pos3 + 1, pos4 - pos3 - 1 ) );

    int money = stoi( data.substr( pos4 + 1 ) );

    return Character( name, password, level, hp, money );
}
