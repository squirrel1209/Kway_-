#include <iostream>
#include <cstdlib>
#include <ctime>
// ANSI 顏色定義
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"


class Slime;
class Goblin;
class Dragon;

class Player
{
protected:
    std::string name;     //名字
    int level;       //等級
    int attackPower; //攻擊力
    int max_hp;      //最大生命
    int hp;          //當前生命
    
public:
    Player():name("Eugene"),level(1),attackPower(4),hp(1000),max_hp(1000){};
    void printStatus();
    void attack();
    void defense(int damage);
    void cure(int level);
    bool isAlive();
    friend void battle ( Player &p , Slime &m );
    friend void battle ( Player &p , Goblin &m );
    friend void battle ( Player &p , Dragon &m );
};