#include <iostream>
#include <vector>
using namespace std;

class Player;

class Monster
{
protected:
    string name;    //名字
    int level;      //等級
    int attackPower;//攻擊力
    int max_hp;     //最大生命
    int hp;         //生命
public:
    Monster(string name,int level,int base_hp, int base_atk, int hp_growth, int atk_growth);
    ~Monster(){};
    void printStatus();
    virtual void attack(){};
    virtual void defense(int damage){};
    bool isAlive();
};


class Slime:public Monster
{
public:
    Slime(int level):Monster("Slime",level,5,2,1,1){};
    void attack()override;
    void defense(int damage)override;
    void cure(int level);
    friend void battle(Player &p,Slime &m);
};