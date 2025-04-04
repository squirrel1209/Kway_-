#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FilePlayerData : public IPlayerData {
    void savePlayerData( const Player& player ) override ;
    Character loadPlayerData( const string& username ) override;
} // end FilePlayerData()
