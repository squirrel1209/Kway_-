#include "LoginSystem.h"


void LoginSystem::registerUser( const std::string& username, const std::string& password ) {
    // 檢查帳號是否已存在
    Character existingPlayer = playerDataStorage -> loadPlayerData( username );
    if ( !existingPlayer.getName().empty() ) {
        std::cout << "Account already exists!" << std::endl;
        return;
    } // end if

    Character player( username, password );  // 創建一個新的玩家
    playerDataStorage -> savePlayerData( player );  // 儲存玩家資料
    std::cout << "Registration successful~" << std::endl;
} // end registerUser


bool LoginSystem::loginUser( const std::string& username, const std::string& password ) {
    Character player = playerDataStorage -> loadPlayerData( username );  // 載入玩家資料
    
    if ( player.getName() == "" ) {
        std::cout << "Account does not exist" << std::endl;
        return false;
    } // end if

    // 假設我們只是驗證密碼，但這裡是簡化的範例
    if ( password == player.getPassword() ) {
        std::cout << "Login successful~" << std::endl;
        return true;
    } // end if 
    
    else {
        std::cout << "Incorrect password" << std::endl;
        return false;
    } // end else
}