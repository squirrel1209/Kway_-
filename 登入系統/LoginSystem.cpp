    
void LoginSystem::registerUser( const string& username, const string& password ) {
    Character player( username );  // 創建一個新的玩家
    string data = "password=" + password;  // 假設這是儲存的密碼資料
    playerDataStorage -> savePlayerData( player );  // 儲存玩家資料
    cout << "註冊成功！" << endl;
} // end registerUser


bool LoginSystem::loginUser( const string& username, const string& password ) {
    Character player = playerDataStorage->loadPlayerData( username );  // 載入玩家資料
    if ( player.getName() == "" ) {
        cout << "帳號不存在！" << endl;
        return false;
    } // end if

    // 假設我們只是驗證密碼，但這裡是簡化的範例
    if ( password == player.getPassword() ) {
        cout << "登入成功！" << endl;
        return true;
    } // end if 
    
    else {
        cout << "密碼錯誤！" << endl;
        return false;
    } // end else
}
