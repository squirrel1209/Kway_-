class LoginSystem {
private:
    IPlayerData* playerDataStorage;  

public:
    LoginSystem( IPlayerData* storage ) : playerDataStorage( storage ) {}

    void registerUser( const string& username, const string& password );

    bool loginUser( const string& username, const string& password );
};
