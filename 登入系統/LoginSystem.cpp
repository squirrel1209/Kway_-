#include "LoginSystem.h"

void LoginSystem::loadUsers() {
    users.clear();

    ifstream file( USER_DATA_FILE );
    string line, username;
    
    while ( getline( file, line ) ) {
        stringstream ss( line );
        ss >> username;
        string data = line.substr( username.size() + 1 );
        users[username] = Character::deserialize( data );
    } // end while
    
} // end loadUsers()


// �x�s�ϥΪ̸��
void LoginSystem::saveUser( const string &username, const Character &player ) {
    users[username] = player;
    ofstream file( USER_DATA_FILE );
    
    for ( const auto &entry : users ) {
        file << entry.first << " " << entry.second.serialize() << "\n";
    } // end for
} // end saveUser()



// ���U�s�ϥΪ�
void LoginSystem::registerUser() {
    string username, password, characterName;
    cout << "�п�J�ϥΪ̦W��: ";
    cin >> username;
    
    if ( users.find( username ) != users.end() ) {
        cout << "���ϥΪ̤w�s�b!\n";
        return;
    } // end if

    cout << "�п�J�K�X: ";
    cin >> password;
    cout << "�п�J����W��: ";
    cin >> characterName;

    /*
    ItemSystem newBackpack;
    newBackpack.items.push_back("��l�Z��");
    */
    Character newPlayer( password );
    saveUser( username, newPlayer );
    cout << "���U���\!\n";
} // end registerUser()

// �n�J�ϥΪ�
void LoginSystem::loginUser() {
    string username, password;
    cout << "�п�J�ϥΪ̦W��: ";
    cin >> username;
    cout << "�п�J�K�X: ";
    cin >> password;

    if ( users.find(username) != users.end() && users[username].password == password ) {
        cout << "�n�J���\!\n";
        Player &player = users[username];
        cout << "����W��: " << player.name << "\n";
        cout << "����: " << player.level << "\n";
        cout << "�ͩR��: " << player.hp << "\n";
        cout << "�g��: " << player.exp << "\n";
        cout << "����: " << player.money << "\n";
        /*
        cout << "�I�]���~: ";
        for ( const auto& item : player.backpack.items ) {
                cout << item << " ";
        }
        */
        cout << "\n";
    } // end if
        
    else {
        cout << "�ϥΪ̦W�٩αK�X���~!\n";
    } // end if
}
