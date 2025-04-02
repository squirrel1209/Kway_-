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


// 儲存使用者資料
void LoginSystem::saveUser( const string &username, const Character &player ) {
    users[username] = player;
    ofstream file( USER_DATA_FILE );
    
    for ( const auto &entry : users ) {
        file << entry.first << " " << entry.second.serialize() << "\n";
    } // end for
} // end saveUser()



// 註冊新使用者
void LoginSystem::registerUser() {
    string username, password, characterName;
    cout << "請輸入使用者名稱: ";
    cin >> username;
    
    if ( users.find( username ) != users.end() ) {
        cout << "此使用者已存在!\n";
        return;
    } // end if

    cout << "請輸入密碼: ";
    cin >> password;
    cout << "請輸入角色名稱: ";
    cin >> characterName;

    /*
    ItemSystem newBackpack;
    newBackpack.items.push_back("初始武器");
    */
    Character newPlayer( password );
    saveUser( username, newPlayer );
    cout << "註冊成功!\n";
} // end registerUser()

// 登入使用者
void LoginSystem::loginUser() {
    string username, password;
    cout << "請輸入使用者名稱: ";
    cin >> username;
    cout << "請輸入密碼: ";
    cin >> password;

    if ( users.find(username) != users.end() && users[username].password == password ) {
        cout << "登入成功!\n";
        Player &player = users[username];
        cout << "角色名稱: " << player.name << "\n";
        cout << "等級: " << player.level << "\n";
        cout << "生命值: " << player.hp << "\n";
        cout << "經驗: " << player.exp << "\n";
        cout << "金幣: " << player.money << "\n";
        /*
        cout << "背包物品: ";
        for ( const auto& item : player.backpack.items ) {
                cout << item << " ";
        }
        */
        cout << "\n";
    } // end if
        
    else {
        cout << "使用者名稱或密碼錯誤!\n";
    } // end if
}
