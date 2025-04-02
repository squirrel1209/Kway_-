#include "Character.h"

string Character::serialize() {
    stringstream ss;
    ss  << password << " "
        << name << " "
        << level << " "
        << exp << " "
        << money << " "
        << attackPower << " "
        << mp << " "
        << hp;
    return ss.str();
} // end serialize()

Character Character::deserialize( const string& data ) {
    stringstream ss( data );
    string password, name;
    int level, exp, money, attackPower, mp, hp;

    // 依序提取各個屬性
    ss >> password >> name >> level >> exp >> money >> attackPower >> mp >> hp;

    return Character( password, name, level, exp, money, attackPower, mp, hp );
} // deserialize()

void Character::display() {
    cout << "Password: " << password << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Exp: " << exp << endl;
    cout << "Money: " << money << endl;
    cout << "Attack Power: " << attackPower << endl;
    cout << "MP: " << mp << endl;
    cout << "HP: " << hp << endl;
} // end display()
