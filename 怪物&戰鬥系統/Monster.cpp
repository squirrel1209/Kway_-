/*
void battle( Player& player, Monster& monster ) {
    while ( player.getMoney() > 0 && monster.getMoney() > 0) {

        player.attack( monster );
        if ( monster.getMoney() <= 0 ) {
            cout << "你打敗了怪物！" << endl;
            player.addMoney(100);
            return;
        } // end if

        monster.attack( player );
        if ( player.getMoney() <= 0 ) {
            cout << "你被怪物打敗了..." << endl;
            return;
        } // end if
    } // end while
} // end battle
*/