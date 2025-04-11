#include "battle.h"


extern std::vector<std::string> slimeBox;
extern std::vector<std::string> goblinBox;
extern std::vector<std::string> dragonBox;


//印出關卡圖像
void printMonsterRow(const std::vector<std::vector<std::string>>& boxes);

//與怪物戰鬥
void Quest(Character& p);