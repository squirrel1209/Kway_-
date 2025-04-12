#include "monster.h"
#include <windows.h>


//暫停畫面，按Enter繼續
void freezeCout();

//與史萊姆戰鬥
void battle ( Character &p, Slime &m  );

//與哥布林戰鬥
void battle ( Character &p, Goblin &m );

//與火龍戰鬥
void battle ( Character &p, Dragon &m );