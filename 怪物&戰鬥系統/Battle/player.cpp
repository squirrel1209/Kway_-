#include "player.h"

void Player::attack()
{
    cout<<"玩家造成了"<<attackPower<<"點傷害";
}

void Player::defense(int damage)
{
    cout<<"玩家承受了"<<damage<<"點傷害 !";
    hp-=damage;
}

void Player::cure(int level)
{
    cout<<"玩家恢復了"<<level/3+1<<"點生命 !"<<endl;
    hp+=(level/3+1);
    if(hp>max_hp)hp=max_hp;
}

bool Player::isAlive()
{
    if(hp<=0)return false;
    else return true;
}

void Player::printStatus()
{
    cout<<name<<" | "<<"Lv:"<<level<<" ATK: "<<attackPower<<" HP: "<<hp<<"/"<<max_hp;
};
