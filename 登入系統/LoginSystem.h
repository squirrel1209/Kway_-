#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>


const string USER_DATA_FILE = "users.txt";

// 登入系統類別，負責管理使用者的註冊與登入
class LoginSystem {
private:
    unordered_map<string, Player> users; // 存儲使用者資訊

    // 載入使用者資料，從檔案讀取
    void loadUsers();

    // 儲存使用者資料到檔案
    void saveUser( const string& username, const Character& Character );

public:
    // 建構子，在啟動時自動載入使用者數據
    LoginSystem() {
        loadUsers();
    } // end LoginSystem()

    // 註冊新使用者
    void registerUser();

    // 登入使用者
    void loginUser();
};
