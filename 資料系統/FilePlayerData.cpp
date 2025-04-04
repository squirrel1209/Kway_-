#include "FilePlayerData.h"


void FilePlayerData::savePlayerData( const Character& player )  {
    ofstream file( player.getName() + ".txt" );  // �H���a�W�٩R�W�ɮ�
    if ( file.is_open() ) {
        file << player.toString();  // �x�s���a���
        file.close();
    } // end if
    
    else {
        cout << "�L�k�x�s��ơI" << endl;
    } // end else
} // end savePlayerData()

Character FilePlayerData::loadPlayerData( const string& username )  {
    ifstream file( username + ".txt" );  // �ھڥΤ�W��Ū���ɮ�
    stringstream ss;
    string line;
    if ( file.is_open() ) {
        while ( getline( file, line ) ) {
            ss << line << "\n";  // ���ɮ׸�ƥ[�i stringstream
        } // end while
    
        file.close();
        return Character::fromString( ss.str() );  // �ϧǦC�Ƹ�ƨê�^���a����
    } // end if 
    
    else {
        cout << "���a����ɮפ��s�b�I" << endl;
        return Character();  // �p�G�ɮפ��s�b�A��^�@�ӪŪ� Character
    } // end else
} // end loadPlayerData
