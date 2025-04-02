int main() {
    LoginSystem system;
    int choice;
    cout << "1. 註冊\n2. 登入\n選擇: ";
    cin >> choice;
    if (choice == 1) {
        system.registerUser();
    } else if (choice == 2) {
        system.loginUser();
    } else {
        cout << "無效的選擇!\n";
    }
    return 0;
}
