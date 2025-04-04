class IPlayerData {
public:
    // 儲存玩家資料
    virtual void savePlayerData( const Player& player ) = 0;
    
    // 讀取玩家資料
    virtual Player loadPlayerData( const string& username ) = 0;
    virtual ~IPlayerData() = default;
};

