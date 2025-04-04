int main() {
    LoginSystem login;
    Shop shop;
    shop.addItem(new Weapon("���C", 100, 15));
    shop.addItem(new Armor("�K��", 50, 5));

    int choice;
    string username, password;

    cout << "1. ���U  2. �n�J  3. ���}" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "��J�ϥΪ̦W��: ";
        cin >> username;
        cout << "��J�K�X: ";
        cin >> password;
        login.registerUser(username, password);
    } else if (choice == 2) {
        cout << "��J�ϥΪ̦W��: ";
        cin >> username;
        cout << "��J�K�X: ";
        cin >> password;
        if (!login.loginUser(username, password)) return 0;
    } else {
        return 0;
    }

    Player player(username);
    Monster monster("�����L", 1, 50, 50);
    Quest quest("���� 1 �������L", 100);

    while (true) {
        cout << "1. �԰�  2. �ө�  3. ����  4. �h�X" << endl;
        cin >> choice;

        if (choice == 1) {
            battle(player, monster);
        } else if (choice == 2) {
            shop.showItems();
            cout << "��ܭn�ʶR�����~ (��J 0 ����): ";
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

