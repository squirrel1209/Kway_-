class IPlayerData {
    public:
        // 儲存玩家資料
        virtual void savePlayerData( const Character& player ) = 0;
        
        // 讀取玩家資料
        virtual Character loadPlayerData( const std::string& username ) = 0;
        virtual ~IPlayerData() = default;
    };
    