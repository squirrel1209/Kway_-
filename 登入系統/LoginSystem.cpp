    
void LoginSystem::registerUser( const string& username, const string& password ) {
    Character player( username );  // �Ыؤ@�ӷs�����a
    string data = "password=" + password;  // ���]�o�O�x�s���K�X���
    playerDataStorage -> savePlayerData( player );  // �x�s���a���
    cout << "���U���\�I" << endl;
} // end registerUser


bool LoginSystem::loginUser( const string& username, const string& password ) {
    Character player = playerDataStorage->loadPlayerData( username );  // ���J���a���
    if ( player.getName() == "" ) {
        cout << "�b�����s�b�I" << endl;
        return false;
    } // end if

    // ���]�ڭ̥u�O���ұK�X�A���o�̬O²�ƪ��d��
    if ( password == player.getPassword() ) {
        cout << "�n�J���\�I" << endl;
        return true;
    } // end if 
    
    else {
        cout << "�K�X���~�I" << endl;
        return false;
    } // end else
}
