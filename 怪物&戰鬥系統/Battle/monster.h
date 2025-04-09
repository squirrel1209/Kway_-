#include <iostream>
#include <vector>
#include <string>
#include "player.cpp"

// ANSI 顏色定義
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class Player;

class Monster
{
protected:
    std:: string name;    //名字
    int level;      //等級
    int attackPower;//攻擊力
    int max_hp;     //最大生命
    int hp;         //生命
public:
    Monster(std:: string name,int level,int base_hp, int base_atk, int hp_growth, int atk_growth);
    ~Monster(){};
    void printStatus();
    virtual void attack(){};
    virtual void defense( int damage ){};
    bool isAlive();
};


class Slime:public Monster
{
public:
    Slime(int level):Monster( "Slime" , level , 5 , 2 , 1 , 1 ){};
    void attack() override;
    void defense( int damage )override;
    void cure( int level );
    friend void battle( Player &p , Slime &m );
};

class Goblin:public Monster
{
public:
    Goblin(int level):Monster( "Goblin" , level , 7 , 3 , 2 , 2 ){};
    void attack() override;
    void defense(int damage)override;
    void bladeAttack();
    void deathEscape();
    friend void battle ( Player &p , Goblin &m );
};

class Dragon:public Monster
{
public:
    Dragon(int level):Monster( "Dragon" , level ,30,30,5,5){};
    void attack()override;
    void defense(int damage)override;
    void fire( Player& p );
    void autoCure();
    friend void battle ( Player &p , Dragon &d );

};