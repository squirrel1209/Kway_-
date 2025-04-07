#include <iostream>
using namespace std;

class Slime;

class Player
{
protected:
    string name;     //名字
    int level;       //等級
    int attackPower; //攻擊力
    int max_hp;      //最大生命
    int hp;          //當前生命
public:
    Player():name("Eugene"),level(1),attackPower(2),hp(20),max_hp(20){};
    void printStatus();
    void attack();
    void defense(int damage);
    void cure(int level);
    bool isAlive();
    friend void battle(Player &p,Slime &m);
};