int main() {
    LoginSystem system;
    int choice;
    cout << "1. ���U\n2. �n�J\n���: ";
    cin >> choice;
    if (choice == 1) {
        system.registerUser();
    } else if (choice == 2) {
        system.loginUser();
    } else {
        cout << "�L�Ī����!\n";
    }
    return 0;
}
