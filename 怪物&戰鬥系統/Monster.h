
class Monster : public Character {
public:
    Monster( string name, int level, int hp, int money ) : Character(name, level, hp, money) {}	
};


void battle( Player& player, Monster& monster );
