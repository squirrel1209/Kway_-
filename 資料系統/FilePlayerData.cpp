#include "FilePlayerData.h"


void FilePlayerData::savePlayerData( const Character& player ) override {
    ofstream file( Character.getName() + ".txt" );  // 以玩家名稱命名檔案
    if ( file.is_open() ) {
        file << Character.toString();  // 儲存玩家資料
        file.close();
    } // end if
    
    else {
        cout << "無法儲存資料！" << endl;
    } // end else
} // end savePlayerData()

Character FilePlayerData::loadPlayerData( const string& username ) override {
    ifstream file( username + ".txt" );  // 根據用戶名稱讀取檔案
    stringstream ss;
    string line;
    if ( file.is_open() ) {
        while ( getline( file, line ) ) {
            ss << line << "\n";  // 把檔案資料加進 stringstream
        } // end while
    
        file.close();
        return Character::fromString( ss.str() );  // 反序列化資料並返回玩家物件
    } // end if 
    
    else {
        cout << "玩家資料檔案不存在！" << endl;
        return Player("");  // 如果檔案不存在，返回一個空的 Player
    } // end else
} // end loadPlayerData
