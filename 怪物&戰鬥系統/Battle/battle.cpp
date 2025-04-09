#include "monster.cpp"
#include <windows.h>




void freezeCout()
{
    // 暫停畫面
    std::cout << "\n按 Enter 繼續...";
    std::cin.ignore();
    std::cin.get();
}

//戰鬥(史萊姆)
void battle(Player &p,Slime &m)
{
    //玩家輸入指令
    std::string order; 
    while(p.isAlive()&&m.isAlive())
    {
        //列出玩家及怪物的狀態
        system("cls");
        std::cout << "\n=================== BATTLE STATUS ===================\n";

        std::cout << (std::string(GREEN) + "【Player】" + RESET);
        p.printStatus();
        std::cout << "\n\n                           vs\n\n";
        std::cout << (std::string(RED) + "【Slime】 " + RESET);
        m.printStatus();
        std::cout << "\n=====================================================\n";
        //輪到玩家回合
        while(1)
        {
            std::cout <<"1:攻擊 2:回復 ";
            std::cin >> order;
            if(order=="1"||order=="2")break;
            else
            {
                std::cout << "錯誤的指令" << std::endl;
            }
        }
        if(order=="1")
        {
            p.attack();
            m.defense(p.attackPower);
            if(!m.isAlive())
            {
                std::cout << "史萊姆被擊倒了 !" << std::endl;
                freezeCout();
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
            std::cout << "玩家被擊倒了" << std::endl;
            freezeCout();
            break;
        }

        freezeCout();
    }
}

//=========================================================================================================================

//戰鬥(哥布林)
void battle(Player &p,Goblin &m)
{
    //玩家輸入指令
    std::string order; 
    while ( p.isAlive() && m.isAlive() )
    {
        system ( "cls" );
        //紀錄哥布林的可復活次數及匕首攻擊的冷卻時間
        static int goblin_revive = 1;
        static int goblin_bladeCD = 0;

        //列出玩家及怪物的狀態
        std::cout << "\n=================== BATTLE STATUS ===================\n";
        std::cout << (std::string(GREEN) + "【Player】" + RESET);
        p.printStatus();
        std::cout << "\n\n                           vs\n\n";
        std::cout << (std::string(RED) + "【Goblin】" + RESET);
        m.printStatus();
        std::cout << "\n=====================================================\n";



        //輪到玩家回合
        while(1)
        {
            std::cout << "1:攻擊 2:回復 ";
            std::cin >> order;
            if ( order=="1" || order=="2" ) break;
            else
            {
                std::cout << "錯誤的指令" << std::endl;
            }
        }
        if(order=="1")
        {
            p.attack();
            m.defense( p.attackPower );
            if( !m.isAlive () && goblin_revive == 1 )
            {
                m.deathEscape();
                goblin_revive--;
            }
            else if(!m.isAlive())
            {
                std::cout << "哥布林被擊倒了 !" << std::endl;
                freezeCout();
                break;
            };
        }
        else if(order=="2")
        {
            p.cure(p.level);
        }

        //輪到哥布林回合
        //如果匕首冷卻時間為0，進行匕首攻擊
        if(goblin_bladeCD==0)
        {
            m.bladeAttack();
            p.defense( m.attackPower+m.level/4 );
        }
        //否則正常攻擊
        else
        {
            m.attack();
            p.defense( m.attackPower );
        }
        if(!p.isAlive())
        {
            std::cout << "玩家被擊倒了" << std::endl;
            freezeCout();
            break;
        }

        //哥布林的匕首技能冷卻時間
        goblin_bladeCD++;
        goblin_bladeCD %= 2;

        freezeCout();
    }
}

//================================================================================================


//戰鬥(火龍)
void battle(Player &p,Dragon &m)
{
    //玩家輸入指令
    std::string order; 
    while(p.isAlive()&&m.isAlive())
    {
        //列出玩家及怪物的狀態
        system("cls");
        std::cout << "\n=================== BATTLE STATUS ===================\n";

        std::cout << (std::string(GREEN) + "【Player】" + RESET);
        p.printStatus();
        std::cout << "\n\n                           vs\n\n";
        std::cout << (std::string(RED) + "【Dragon】 " + RESET);
        m.printStatus();
        std::cout << "\n=====================================================\n";
        //輪到玩家回合
        while(1)
        {
            std::cout <<"1:攻擊 2:回復 ";
            std::cin >> order;
            if(order=="1"||order=="2")break;
            else
            {
                std::cout << "錯誤的指令" << std::endl;
            }
        }
        if(order=="1")
        {
            p.attack();
            m.defense(p.attackPower);
            if(!m.isAlive())
            {
                std::cout << "火龍被擊倒了 !" << std::endl;
                freezeCout();
                break;
            };
        }
        else if(order=="2")
        {
            p.cure(p.level);
        }

        //輪到火龍回合
        m.attack();
        p.defense(m.attackPower);
        if(!p.isAlive())
        {
            std::cout << "玩家被擊倒了" << std::endl;
            freezeCout();
            break;
        }

        m.fire(p);
        m.autoCure();

        freezeCout();
    }
}