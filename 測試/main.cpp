#include "Character.h"

int main() {
    Character play("abc", "aaa", 5, 100, 100);
    play.showStatus();

    // ���էǦC�ƩM�ϧǦC��
    string serialized = play.toString();
    cout << "�ǦC�ƫ᪺���:\n" << serialized << endl;

    Character deserialized = Character::fromString(serialized);
    cout << "�ϧǦC�ƫ᪺���a���:\n";
    deserialized.showStatus();
    system( "pause" );
    return 0;
}

