#include "LoginSystem.h"

void LoginSystem::registerUser( const string& username, const string& password ) {
    Character player( username, password );  // �Ыؤ@�ӷs�����a
    playerDataStorage -> savePlayerData( player );  // �x�s���a���
    cout << "Registration successful~" << endl;
} // end registerUser


bool LoginSystem::loginUser( const string& username, const string& password ) {
    Character player = playerDataStorage -> loadPlayerData( username );  // ���J���a���
    
    if ( player.getName() == "" ) {
        cout << "Account does not exist" << endl;
        return false;
    } // end if

    // ���]�ڭ̥u�O���ұK�X�A���o�̬O²�ƪ��d��
    if ( password == player.getPassword() ) {
        cout << "Login successful~" << endl;
        return true;
    } // end if 
    
    else {
        cout << "Incorrect password" << endl;
        return false;
    } // end else
}
