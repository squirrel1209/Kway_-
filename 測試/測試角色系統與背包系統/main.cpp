#include "Character.h"
#include "ItemSystem.h"
#include "FilePlayerData.h"

int main() {
    // 創建物品系統
    ItemSystem itemSystem;
    FilePlayerData filePlayerData;

    // 創建角色並添加物品到背包
    Character player("Player1", "password123", 1, 100, 500, 10, 20);
    player.showStatus();
    
    Item* sword = itemSystem.createItem( "sword_iron" );
    sword -> print();
    
    player.getInventory().addItem( sword, 2 );  // 向背包中添加兩把劍

    std::cout << std::endl ;

    player.showPlayInventory(); // 顯示背包物品
    

    std::cout << std::endl << "====================" << std::endl;
    // 將角色資料儲存到字串
    std::string savedData = player.toString();
    filePlayerData.savePlayerData( player ); // 儲存角色資料到檔案
    std::cout << "儲存的角色資料：" << std::endl << savedData << std::endl;
    
    
    // 從字串中創建角色並恢復背包資料
    Character loadedPlayer = filePlayerData.loadPlayerData( player.getName() ); // 從檔案讀取角色資料
    std::cout << "載入的角色資料：" << std::endl;
    
    

    loadedPlayer.showStatus();

    std::cout << std::endl << "====================" << std::endl;

    player.showPlayInventory(); // 顯示背包物品
    
    system( "pause" );
    return 0;
}