#include "FilePlayerData.h"


int main() {
    // 創建一個 Character 物件，並顯示它的初始狀態
    Character player("Player1", "password123", 5, 80, 1000);
    cout << "Original Player:" << endl;
    player.showStatus();
    cout << endl;

    // 儲存玩家資料到檔案
    FilePlayerData fileData;
    fileData.savePlayerData(player);

    // 載入玩家資料
    Character loadedPlayer = fileData.loadPlayerData("Player1");

    // 顯示載入的玩家資料
    cout << "Loaded Player:" << endl;
    loadedPlayer.showStatus();
    
    system( "pause" );
    return 0;
}
