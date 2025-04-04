#include "FilePlayerData.h"


int main() {
    // �Ыؤ@�� Character ����A����ܥ�����l���A
    Character player("Player1", "password123", 5, 80, 1000);
    cout << "Original Player:" << endl;
    player.showStatus();
    cout << endl;

    // �x�s���a��ƨ��ɮ�
    FilePlayerData fileData;
    fileData.savePlayerData(player);

    // ���J���a���
    Character loadedPlayer = fileData.loadPlayerData("Player1");

    // ��ܸ��J�����a���
    cout << "Loaded Player:" << endl;
    loadedPlayer.showStatus();
    
    system( "pause" );
    return 0;
}
