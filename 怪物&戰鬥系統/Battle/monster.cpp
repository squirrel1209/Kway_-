#include "monster.h"

//初始化怪物的:名字、等級、基礎生命、基礎攻擊力、生命成長率、攻擊力成長率
Monster::Monster(string name,int level,int base_hp, int base_atk, int hp_growth, int atk_growth)
{
    this->name=name;
    this->level=level;
    attackPower=base_atk+level*atk_growth;
    hp=base_hp+level*hp_growth;
    max_hp=hp;
}

void Monster::printStatus()
{
    cout<<name<<" | "<<"Lv:"<<level<<" ATK: "<<attackPower<<" HP: "<<hp<<"/"<<max_hp;
}

//判斷怪物是否戰敗
bool Monster::isAlive()
{
    if(hp<=0)return false;
    else return true;
}

//史萊姆攻擊
void Slime::attack()
{
    cout<<"史萊姆彈跳著攻擊造成了"<<attackPower<<"點傷害 !"<<endl;
}

//史萊姆被攻擊
void Slime::defense(int damage)
{
    cout<<"史萊姆承受了"<<damage<<"點傷害 !"<<endl;
    hp-=damage;
}

//史萊姆治療
void Slime::cure(int level)
{
    cout<<"史萊姆正在治療自己，恢復了"<<level/5+1<<"點生命"<<endl;
    hp+=(level/5+1);
    if(hp>max_hp)hp=max_hp;
}
