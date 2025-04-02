#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>


const string USER_DATA_FILE = "users.txt";

// �n�J�t�����O�A�t�d�޲z�ϥΪ̪����U�P�n�J
class LoginSystem {
private:
    unordered_map<string, Player> users; // �s�x�ϥΪ̸�T

    // ���J�ϥΪ̸�ơA�q�ɮ�Ū��
    void loadUsers();

    // �x�s�ϥΪ̸�ƨ��ɮ�
    void saveUser( const string& username, const Character& Character );

public:
    // �غc�l�A�b�Ұʮɦ۰ʸ��J�ϥΪ̼ƾ�
    LoginSystem() {
        loadUsers();
    } // end LoginSystem()

    // ���U�s�ϥΪ�
    void registerUser();

    // �n�J�ϥΪ�
    void loginUser();
};
