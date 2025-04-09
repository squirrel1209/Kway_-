#include "monster.h"
#include <iomanip>

//初始化怪物的:名字、等級、基礎生命、基礎攻擊力、生命成長率、攻擊力成長率
Monster::Monster(std:: string name,int level,int base_hp, int base_atk, int hp_growth, int atk_growth)
{
    this->name=name;
    this->level=level;
    attackPower=base_atk+level*atk_growth;
    hp=base_hp+level*hp_growth;
    max_hp=hp;
}


void Monster::printStatus()
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

//判斷怪物是否戰敗
bool Monster::isAlive()
{
    if(hp<=0)return false;
    else return true;
}

//史萊姆攻擊
void Slime::attack()
{
    std::cout << "史萊姆正在彈跳著，攻擊力為" << attackPower << " !" << std::endl;
}

//史萊姆被攻擊
void Slime::defense(int damage)
{
    std::cout << "史萊姆承受了" << damage << "點傷害 !" << std::endl;
    hp-=damage;
}

//史萊姆治療
void Slime::cure(int level)
{
    std::cout << "史萊姆正在治療自己，恢復了" << level/5+1 << "點生命" << std::endl;
    hp+=(level/5+1);
    if(hp>max_hp)hp=max_hp;
}

//========================================================================================

void Goblin::attack()
{
    std::cout << "哥布林給了您一拳，攻擊力為" << attackPower << " !" << std::endl;
}

void Goblin::defense(int damage)
{
    std::cout << "哥布林承受了" << damage << "點傷害" << std::endl;
    hp-=damage;
}

void Goblin::bladeAttack()
{
    attackPower++;
    std::cout << "哥布林拿出了匕首，攻擊力增加，攻擊力為" << attackPower+level/4 << "點 !" << std::endl;
}

void Goblin::deathEscape()
{
    std::cout << "哥布林撐住了這次攻擊 !" << std::endl;
    hp=1;
}

//=======================================================================================

void Dragon::attack()
{
    std::cout << "火龍伸出了爪子，攻擊力為" << attackPower << "點" << std::endl;
}

void Dragon::defense(int damage)
{
    hp-=(damage*0.9);
    std::cout << "火龍用鱗片阻擋部分傷害，受到"<<damage*0.9<<"點傷害" << std::endl;
}

void Dragon::fire(Player& p)
{
    std::cout << "火焰四處燃燒" << std::endl;
    p.defense(level);
}

void Dragon::autoCure()
{
    hp+=level/2;
    std::cout << "火龍正在自我回復，回復了" << level/2 << "點生命" << std::endl;
}