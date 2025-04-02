
#include <sstream>
#include <string>

class Character {
private:
    string password;         // �K�X
 
    string name;         // ���⪺�W��
    int level;           // ����
    int attackPower;     // �����O 
    int mp;              // �]�q 
    int hp;              // �ͩR��
    int exp;             // �g��� 
    int money;           // ����

    ItemSystem backpack  // �I�]
    
public:
    // �w�]�غc�l�A��l�ƨ����ݩ�
    Character() : level(1), exp(0), money(100), attackPower(10), mp(100), hp(100) {}
    
    // �a�Ѽƪ��غc�l�A�q�{���ƾګإߨ���
    Character( string password ) 
        : password(password), level(1), exp(0), money(0), attackPower(10), mp(100), hp(100) {}
    
    // �N���a��ƧǦC�Ƭ��r��A��K�s��
    string serialize();
    
    // �ѪR���a�ƾ�
    static Character deserialize( const string& data );
    
    // ��ܨ����T (�i�Ω����)
    void display();
};
