#include "FilePlayerData.h"


void FilePlayerData::savePlayerData( const Character& player ) override {
    ofstream file( Character.getName() + ".txt" );  // �H���a�W�٩R�W�ɮ�
    if ( file.is_open() ) {
        file << Character.toString();  // �x�s���a���
        file.close();
    } // end if
    
    else {
        cout << "�L�k�x�s��ơI" << endl;
    } // end else
} // end savePlayerData()

Character FilePlayerData::loadPlayerData( const string& username ) override {
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
        return Player("");  // �p�G�ɮפ��s�b�A��^�@�ӪŪ� Player
    } // end else
} // end loadPlayerData
