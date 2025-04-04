#include "LoginSystem.h"

int main() {
    FilePlayerData fileStorage;  // 使用檔案儲存方式
    LoginSystem loginSystem(&fileStorage);

    string username, password;


    cout << "1. 註冊  2. 登入  3. 離開" << endl;
    int choice;
    cin >> choice;

    if ( choice == 1 ) {
        cout << "輸入使用者名稱: ";
        cin >> username;
        cout << "輸入密碼: ";
        cin >> password;
        loginSystem.registerUser( username, password);
    } // end if
    
    else if ( choice == 2 )  {
        cout << "輸入使用者名稱: ";
        cin >> username;
        cout << "輸入密碼: ";
        cin >> password;
        if ( !loginSystem.loginUser( username, password ) ) return 0;
    } 
    
    else {
        return 0;
    }

    // 登入後可以操作玩家資料
    Character player = fileStorage.loadPlayerData(username);
    player.showStatus();

    return 0;
}
