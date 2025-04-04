#ifndef CHARACTER_H   // �p�G CHARACTER_H �|���w�q�A�h����U�������e
#define CHARACTER_H   // �w�q CHARACTER_H�A����Ʃw�q

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


    // ��ܪ��a���A
    void showStatus() const ;
    
    // ���o���a�W�r 
    string getName() const { return name; }
    
    // ���o���a�K�X
    string getPassword() const { return password; }
    
    // �ഫ���i�x�s���榡�]�ǦC�ơ^
    string toString() const ;
    
    // �q�r�ꤤ�ѪR�X���a��ơ]�ϧǦC�ơ^
    static Character& fromString( const string& data );
    
}; 
#endif // CHARACTER_H   // ��������A����ƥ]�t
