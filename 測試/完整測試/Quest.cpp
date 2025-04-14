#include "Quest.h"


std::vector<std::string> slimeBox = {
    std::string(GREEN) + "////////////////" + RESET,
    std::string(GREEN) + "//            //" + RESET,
    std::string(GREEN) + "//     史     //" + RESET,
    std::string(GREEN) + "//     萊     //" + RESET,
    std::string(GREEN) + "//     姆     //" + RESET,
    std::string(GREEN) + "//            //" + RESET,
    std::string(GREEN) + "//            //" + RESET,
    std::string(GREEN) + "////////////////" + RESET
};

std::vector<std::string> goblinBox = {
    std::string(CYAN) + "////////////////" + RESET,
    std::string(CYAN) + "//            //" + RESET,
    std::string(CYAN) + "//     哥     //" + RESET,
    std::string(CYAN) + "//     布     //" + RESET,
    std::string(CYAN) + "//     林     //" + RESET,
    std::string(CYAN) + "//            //" + RESET,
    std::string(CYAN) + "//            //" + RESET,
    std::string(CYAN) + "////////////////" + RESET
};

std::vector<std::string> dragonBox = {
    std::string(RED) + "////////////////" + RESET,
    std::string(RED) + "//            //" + RESET,
    std::string(RED) + "//            //" + RESET,
    std::string(RED) + "//     火     //" + RESET,
    std::string(RED) + "//     龍     //" + RESET,
    std::string(RED) + "//            //" + RESET,
    std::string(RED) + "//            //" + RESET,
    std::string(RED) + "////////////////" + RESET
};


void printMonsterRow(const std::vector<std::vector<std::string>>& boxes) {
    for (size_t i = 0; i < boxes[0].size(); ++i) {
        for (const auto& box : boxes) {
            std::cout << box[i] << "   ";
        }
        std::cout << std::endl;
    }
}


void Quests(Character& p)
{
    std::vector<std::vector<std::string>> monsters;

    //關卡數(決定怪物等級)
    static int round=1;

    while(1)
    {
        monsters.clear();
        system("cls");

        //隨機取出三隻怪物做選擇
        srand ( time ( NULL ) );
        for(int i=0;i<3;i++)
        {
            int x = rand();
            x%=3;
            if( x ==0 ) monsters.push_back(slimeBox);
            else if( x == 1 ) monsters.push_back(goblinBox);
            else if( x == 2 ) monsters.push_back(dragonBox);
        }

        //列出三種選擇
        printMonsterRow(monsters);
        std::cout << "\n\n  1:左 2:中 3:右 4:離開\n";
        
        int order;
        std::cin >> order;
        if( order == 1 )
        {
            if ( monsters[0] == slimeBox )
            {
                Slime s(round);
                battle(p,s);
            }
            else if( monsters[0] == goblinBox )
            {
                Goblin g(round);
                battle(p,g);
            }
            else if( monsters[0] == dragonBox )
            {
                Dragon d(round);
                battle(p,d);
            }
        }
        else if( order == 2)
        {
            if ( monsters[1] == slimeBox )
            {
                Slime s(round);
                battle(p,s);
            }
            else if( monsters[1] == goblinBox )
            {
                Goblin g(round);
                battle(p,g);
            }
            else if( monsters[1] == dragonBox )
            {
                Dragon d(round);
                battle(p,d);
            }
        }
        else if( order == 3)
        {
            if ( monsters[2] == slimeBox )
            {
                Slime s(round);
                battle(p,s);
            }
            else if( monsters[2] == goblinBox )
            {
                Goblin g(round);
                battle(p,g);
            }
            else if( monsters[2] == dragonBox )
            {
                Dragon d(round);
                battle(p,d);
            }
        }
        else if( order == 4)break;

        //HP消耗完則退出戰鬥並補滿HP
        if (!p.isAlive())
        {
            p.battleHp=p.hp;
            std:: cout << "失敗了，下次再加油..." << std::endl;
            break;
        }

        round++;
    }
}