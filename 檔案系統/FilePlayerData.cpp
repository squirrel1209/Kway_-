#include "FilePlayerData.h"


void FilePlayerData::savePlayerData( const Character& player )  {
    std::ofstream file( player.getName() + ".txt" );  // 以玩家名稱命名檔案
    if ( file.is_open() ) {
        file << player.toString();  // 儲存玩家資料
        file.close();
    } // end if
    
    else {
        std::cout << "無法儲存資料！" << std::endl;
    } // end else
} // end savePlayerData()

Character FilePlayerData::loadPlayerData( const std::string& username )  {
    std::ifstream file( username + ".txt" );  // 根據用戶名稱讀取檔案
    std::stringstream ss;
    std::string line;
    if ( file.is_open() ) {
        while ( getline( file, line ) ) {
            ss << line << "\n";  // 把檔案資料加進 stringstream
        } // end while
    
        file.close();
        return Character::fromString( ss.str() );  // 反序列化資料並返回玩家物件
    } // end if 
    
    else {
        std::cout << "玩家資料檔案不存在！" << std::endl;
        return Character();  // 如果檔案不存在，返回一個空的 Character
    } // end else
} // end loadPlayerData