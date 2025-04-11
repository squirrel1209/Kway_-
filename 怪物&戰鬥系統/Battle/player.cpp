#include "player.h"
#include <iomanip>

void Player::attack()
{
    std:: cout << "玩家造成了" << attackPower << "點傷害" << std::endl;
}

void Player::defense( int damage )
{
    std:: cout << "玩家承受了" << damage << "點傷害 !" << std::endl;
    hp-= damage;
}

void Player::cure( int level )
{
    std:: cout << "玩家恢復了" << level/3+1 << "點生命 !" << std::endl;
    hp += (level/3+1) ;
    if ( hp > max_hp ) hp = max_hp;
}

bool Player::isAlive()
{
    if (  hp <= 0 )return false;
    else return true;
}

void Player::printStatus()
{
    coutSpace(name,6);
    coutSpace(" Lv: " + std::to_string(level),8);
    coutSpace(" ATK: " + std::to_string(attackPower),8);
    std::cout <<" HP: ";
    //HP低於1/3會顯示紅色警示
    if(hp<=max_hp/3)
    {
        std::cout << (std::string(RED) + std::to_string(hp) + RESET);
    }
    else
        std::cout << hp;
        std::cout << "/" << max_hp;
}
