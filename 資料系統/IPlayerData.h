class IPlayerData {
public:
    // �x�s���a���
    virtual void savePlayerData( const Player& player ) = 0;
    
    // Ū�����a���
    virtual Player loadPlayerData( const string& username ) = 0;
    virtual ~IPlayerData() = default;
};

