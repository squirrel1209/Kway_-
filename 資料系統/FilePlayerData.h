#include "Character.h" 
#include "IPlayerData.h"
#include <fstream>
#include <sstream>


class FilePlayerData : public IPlayerData {
public:
    void savePlayerData( const Character& player ) override ;
    Character loadPlayerData( const string& username ) override;
}; // end FilePlayerData()
