class LoginSystem {
private:
    IPlayerData* playerDataStorage;  

public:
    LoginSystem( IPlayerData* storage ) : playerDataStorage( storage ) {}

    void registerUser( const string& username, const string& password );

    bool loginUser(const string& username, const string& password) {
        Player player = playerDataStorage->loadPlayerData(username);  // 載入玩家資料
        if (player.getName() == "") {
            cout << "帳號不存在！" << endl;
            return false;
        }

        // 假設我們只是驗證密碼，但這裡是簡化的範例
        string storedPassword = "password";  // 假設密碼儲存在某個地方
        if (password == storedPassword) {
            cout << "登入成功！" << endl;
            return true;
        } else {
            cout << "密碼錯誤！" << endl;
            return false;
        }
    }
};
