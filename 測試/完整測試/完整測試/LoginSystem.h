#include "FilePlayerData.h"

class LoginSystem {
private:
    IPlayerData* playerDataStorage;  

public:
    LoginSystem( IPlayerData* storage ) : playerDataStorage( storage ) {}

    void registerUser( const std::string& username, const std::string& password );

    bool loginUser( const std::string& username, const std::string& password );
};
