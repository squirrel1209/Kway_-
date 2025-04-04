#include "LoginSystem.h"

int main() {
    FilePlayerData fileStorage;  // �ϥ��ɮ��x�s�覡
    LoginSystem loginSystem(&fileStorage);

    string username, password;


    cout << "1. ���U  2. �n�J  3. ���}" << endl;
    int choice;
    cin >> choice;

    if ( choice == 1 ) {
        cout << "��J�ϥΪ̦W��: ";
        cin >> username;
        cout << "��J�K�X: ";
        cin >> password;
        loginSystem.registerUser( username, password);
    } // end if
    
    else if ( choice == 2 )  {
        cout << "��J�ϥΪ̦W��: ";
        cin >> username;
        cout << "��J�K�X: ";
        cin >> password;
        if ( !loginSystem.loginUser( username, password ) ) return 0;
    } 
    
    else {
        return 0;
    }

    // �n�J��i�H�ާ@���a���
    Character player = fileStorage.loadPlayerData(username);
    player.showStatus();

    return 0;
}
