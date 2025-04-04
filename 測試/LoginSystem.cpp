#include "LoginSystem.h"

void LoginSystem::registerUser( const string& username, const string& password ) {
    Character player( username, password );  // 創建一個新的玩家
    playerDataStorage -> savePlayerData( player );  // 儲存玩家資料
    cout << "Registration successful~" << endl;
} // end registerUser


bool LoginSystem::loginUser( const string& username, const string& password ) {
    Character player = playerDataStorage -> loadPlayerData( username );  // 載入玩家資料
    
    if ( player.getName() == "" ) {
        cout << "Account does not exist" << endl;
        return false;
    } // end if

    // 假設我們只是驗證密碼，但這裡是簡化的範例
    if ( password == player.getPassword() ) {
        cout << "Login successful~" << endl;
        return true;
    } // end if 
    
    else {
        cout << "Incorrect password" << endl;
        return false;
    } // end else
}
