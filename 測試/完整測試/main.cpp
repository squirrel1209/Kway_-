#include <iostream>
#include "ItemSystem.h"
#include "Inventory.h"
#include "Shop.h"
#include "LoginSystem.h"
#include "Quest.h"
#include "QuestSystem.h"


void showLoginMenu();
void handleRegistration( LoginSystem& loginSystem );
bool handleLogin( LoginSystem& loginSystem, std::string& username, std::string& password );
void showMainMenu( Shop& shop, Character& player, FilePlayerData& fileStorage );
void handleCombat( Character& player );
void handleShop( Shop& shop, Character& player );
void handleQuest( Character& player );

int main() {
    SetConsoleOutputCP( 65001 ); // 設定控制台輸出編碼為 UTF-8

    FilePlayerData fileStorage; // 使用檔案儲存方式
    ItemSystem itemSystem; // 物品系統
    Shop shop( itemSystem ); // 商店系統
    LoginSystem loginSystem( &fileStorage );  // 登入系統

    int choice;
    std::string username, password;

    showLoginMenu();
    std::cin >> choice;

    while ( true ) {
        switch ( choice ) {
            case 1: {
                handleRegistration( loginSystem );
                showLoginMenu();
                std::cin >> choice;
                break;
            } // end case 1

            case 2: {
                if ( handleLogin( loginSystem, username, password ) ) {
                    // 登入成功，清空命令行畫面
                    system( "cls" );

                    // 登入成功，顯示遊戲主畫面
                    Character player = fileStorage.loadPlayerData( username );
                    player.showStatus();  // 顯示角色資訊
                    showMainMenu( shop, player, fileStorage );  // 顯示主遊戲選單
                } // end if
                
                else {
                    showLoginMenu();
                    std::cin >> choice;
                } // end else

                break;
            } // end case 2

            case 3: {
                std::cout << "------------------------------" << std::endl;
                std::cout << "感謝您的遊玩!" << std::endl;
                std::cout << "遊戲結束!" << std::endl;
                std::cout << "------------------------------" << std::endl;
                return 0; // 結束程式
            } // end case 3

            default: {
                std::cout << "請輸入有效的選項 (1-3): ";
                std::cin >> choice;
                break;
            } // end default

        } // end switch

    } // end while

} // end main

void showLoginMenu() {
    std::cout << std::endl << "==============================" << std::endl;
    std::cout << "         遊戲登入系統         " << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "          1. 註冊" << std::endl;
    std::cout << "          2. 登入" << std::endl;
    std::cout << "          3. 離開" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "請輸入選項 (1-3): ";
} // end showLoginMenu()

void handleRegistration( LoginSystem &loginSystem ) {
    std::string username, password;
    std::cout << "------------------------------" << std::endl;
    std::cout << "【註冊】" << std::endl;
    std::cout << "請輸入使用者名稱: ";
    std::cin >> username;
    std::cout << "請輸入密碼: ";
    std::cin >> password;
    loginSystem.registerUser( username, password );
} // end handleRegistration()

bool handleLogin( LoginSystem &loginSystem, std::string &username, std::string &password ) {
    std::cout << "------------------------------" << std::endl;
    std::cout << "【登入】" << std::endl;
    std::cout << "請輸入使用者名稱: ";
    std::cin >> username;
    std::cout << "請輸入密碼: ";
    std::cin >> password;

    if ( !loginSystem.loginUser( username, password ) ) {
        std::cout << "登入失敗，請檢查使用者名稱或密碼。" << std::endl;
        return false;
    } // end if

    return true;
} // end handleLogin()

void showMainMenu( Shop& shop, Character& player, FilePlayerData& fileStorage ) {
    int choice;
    while ( true ) {
        system("cls");
        std::cout << "==============================" << std::endl;
        std::cout << "        遊戲主畫面           " << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "          1. 戰鬥" << std::endl;
        std::cout << "          2. 商店" << std::endl;
        std::cout << "          3. 任務" << std::endl;
        std::cout << "          4. 結束" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "請輸入選項 (1-4): ";
        std::cin >> choice;

        switch ( choice ) {
            case 1: {
                // 登入成功，清空命令行畫面
                system( "cls" );
                handleCombat( player );
                break;
            } // 戰鬥

            case 2: {
                // 登入成功，清空命令行畫面
                system( "cls" );
                handleShop( shop, player );
                break;
            } // 商店

            case 3: {
                // 登入成功，清空命令行畫面
                system( "cls" );
                handleQuest( player );
                break;
            } // 任務

            case 4: {
                std::cout << "感謝您的遊玩!" << std::endl;
                std::cout << "遊戲結束!" << std::endl;
                fileStorage.savePlayerData( player ); // 儲存玩家資料
                exit( 0 );  // 結束程式
            } // 結束

            default: {
                std::cout << "請輸入有效的選項 (1-4): ";
                break;
            } // default

        } // end switch
    } // end while
} // end showMainMenu()

void handleCombat( Character& player ) {
    std::cout << "進入戰鬥模式..." << std::endl;
    // 這裡可以加入戰鬥邏輯
    Quests( player );
} // end handleCombat()

void handleShop( Shop& shop, Character& player ) {
    std::cout << "進入商店..." << std::endl;

    std::cout << "\n== 玩家初始狀態 ==" << std::endl;
    player.showStatus();
    std::cout << "\n== 玩家背包狀態 ==" << std::endl;
    player.showPlayInventory();

    shop.showItems();

    std::string input;
    while ( true ) {
        std::cout << "\n輸入要購買的物品ID（輸入 q 離開商店）：";
        std::cin >> input;

        if ( input == "q" || input == "Q" ) {
            system("cls");
            std::cout << "離開商店...\n";
            break;
        } // end if

        shop.buyItem( player, input );
    } // end while

    std::cout << "\n== 玩家狀態（購買後） ==" << std::endl;
    player.showStatus();
    std::cout << "\n== 玩家背包狀態 ==" << std::endl;
    player.showPlayInventory();

    /*
    // 顯示販售示範（這段可以保留或移除）
    std::cout << "\n== 玩家販售第一個背包物品 ==" << std::endl;
    if (!player.getInventory().empty()) {
        shop.sellItem(player, player.getInventory()[0]);
    }

    std::cout << "\n== 玩家狀態（販售後） ==" << std::endl;
    player.showStatus();
    player.showPlayInventory();
    */
} // end handleShop()

void handleQuest( Character& player ) {
    std::cout << "查看任務..." << std::endl;
    // 這裡可以加入任務邏輯
    startQuest( player );
} // end handleQuest()


