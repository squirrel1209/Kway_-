class LoginSystem {
private:
    IPlayerData* playerDataStorage;  

public:
    LoginSystem( IPlayerData* storage ) : playerDataStorage( storage ) {}

    void registerUser( const string& username, const string& password );

    bool loginUser(const string& username, const string& password) {
        Player player = playerDataStorage->loadPlayerData(username);  // ���J���a���
        if (player.getName() == "") {
            cout << "�b�����s�b�I" << endl;
            return false;
        }

        // ���]�ڭ̥u�O���ұK�X�A���o�̬O²�ƪ��d��
        string storedPassword = "password";  // ���]�K�X�x�s�b�Y�Ӧa��
        if (password == storedPassword) {
            cout << "�n�J���\�I" << endl;
            return true;
        } else {
            cout << "�K�X���~�I" << endl;
            return false;
        }
    }
};
