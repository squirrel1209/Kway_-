#include <iostream>

#include "Character.h"
//#include "ItemSystem.h"
#include "FilePlayerData.h"
//#include "Inventory.h"
//#include "Shop.h"
#include "LoginSystem.h"


using namespace std;
int main() {
    FilePlayerData fileStorage; // 使用檔案儲存方式
    LoginSystem loginSystem( &fileStorage );  // 登入系統


    int choice;
    string username, password;

    
    cout << "==============================" << endl;
    cout << "         遊戲登入系統         " << endl;
    cout << "==============================" << endl;
    cout << "          1. 註冊" << endl;
    cout << "          2. 登入" << endl;
    cout << "          3. 離開" << endl;
    cout << "------------------------------" << endl;
    cout << "請輸入選項 (1-3): ";
    
    cin >> choice;


    while ( true ) {
        switch ( choice ) {
            case 1: {
                cout << "------------------------------" << endl;
                cout << "【註冊】" << endl;
                cout << "請輸入使用者名稱: ";
                cin >> username;
                cout << "請輸入密碼: ";
                cin >> password;
                login.registerUser(username, password);
            } // end case 1

            case 2: {
                cout << "------------------------------" << endl;
                cout << "【登入】" << endl;
                cout << "請輸入使用者名稱: ";
                cin >> username;
                cout << "請輸入密碼: ";
                cin >> password;

                if ( !login.loginUser( username, password ) ) {
                    cout << "登入失敗，請檢查使用者名稱或密碼。" << endl;
                    cout << "請重新輸入選項 (1-3): ";
                    cin >> choice;
                    continue; // 重新開始
                } // end if

                //else  主畫面
            } // end case 2

            case 3: {
                cout << "------------------------------" << endl;
                cout << "感謝您的遊玩!" << endl;
                cout << "遊戲結束!" << endl;
                cout << "------------------------------" << endl;
                return 0; // 結束程式
            } // end case 3

            default: {
                cout << "請輸入有效的選項 (1-3): ";
                cin >> choice;
                continue; // 重新開始循環
            } // end default

        } // end switch
    } // end while


    
    system( "pause" );
} // end main()