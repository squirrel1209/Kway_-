class IPlayerData {
public:
    // �x�s���a���
    virtual void savePlayerData( const Character& player ) = 0;
    
    // Ū�����a���
    virtual Character loadPlayerData( const string& username ) = 0;
    virtual ~IPlayerData() = default;
};

