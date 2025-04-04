int main() {
    LoginSystem login;
    Shop shop;
    shop.addItem(new Weapon("長劍", 100, 15));
    shop.addItem(new Armor("鐵甲", 50, 5));

    int choice;
    string username, password;

    cout << "1. 註冊  2. 登入  3. 離開" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "輸入使用者名稱: ";
        cin >> username;
        cout << "輸入密碼: ";
        cin >> password;
        login.registerUser(username, password);
    } else if (choice == 2) {
        cout << "輸入使用者名稱: ";
        cin >> username;
        cout << "輸入密碼: ";
        cin >> password;
        if (!login.loginUser(username, password)) return 0;
    } else {
        return 0;
    }

    Player player(username);
    Monster monster("哥布林", 1, 50, 50);
    Quest quest("打敗 1 隻哥布林", 100);

    while (true) {
        cout << "1. 戰鬥  2. 商店  3. 任務  4. 退出" << endl;
        cin >> choice;

        if (choice == 1) {
            battle(player, monster);
        } else if (choice == 2) {
            shop.showItems();
            cout << "選擇要購買的物品 (輸入 0 取消): ";
            int itemIndex;
            cin >> itemIndex;
            if (itemIndex > 0) shop.buyItem(player, itemIndex);
        } else if (choice == 3) {
            quest.completeQuest(player);
        } else {
            break;
        }
    }
    return 0;
}

