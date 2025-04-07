#include "monster.cpp"
#include "player.cpp"

void battle(Player &p,Slime &m)
{
    //玩家輸入指令
    string order; 
    while(p.isAlive()&&m.isAlive())
    {
        //列出玩家及怪物的狀態
        p.printStatus();
        cout<<"      vs      ";
        m.printStatus();
        cout<<endl;


        //輪到玩家回合
        while(1)
        {
            cout<<"1:攻擊 2:回復 ";
            cin>>order;
            if(order=="1"||order=="2")break;
            else
            {
                cout<<"錯誤的指令"<<endl;
            }
        }
        if(order=="1")
        {
            p.attack();
            m.defense(p.attackPower);
            if(!m.isAlive())
            {
                cout<<"史萊姆被擊倒了 !"<<endl;
                break;
            };
        }
        else if(order=="2")
        {
            p.cure(p.level);
        }

        //輪到史萊姆回合
        //史萊姆血量小於30%時會回復生命
        if(m.hp<=(m.max_hp*0.3))
        {
            m.cure(m.level);
        }
        //否則正常攻擊
        else
        {
            m.attack();
            p.defense(m.attackPower);
        }
        if(!p.isAlive())
        {
            cout<<"玩家被擊倒了"<<endl;
            break;
        }
    }
}