#include "Character.h"

int main() {
    Character play("abc", "aaa", 5, 100, 100);
    play.showStatus();

    // 測試序列化和反序列化
    string serialized = play.toString();
    cout << "序列化後的資料:\n" << serialized << endl;

    Character deserialized = Character::fromString(serialized);
    cout << "反序列化後的玩家資料:\n";
    deserialized.showStatus();
    system( "pause" );
    return 0;
}

