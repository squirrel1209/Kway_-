#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

// ���~���R�A��Ƶ��c
struct ItemInfo {
    std::string id;          // ���~ID
    std::string name;        // ���~�W��
    std::string description; // ���~�y�z
    int price = 0;           // ���~����
    int attack = 0;          // ���~�������O�]�ߤ@�ݩʡ^ 
};

// ���~���O�A�N��C��������@���~���
class Item {
private:
    ItemInfo info;    

public:
    // �غc�l�G�ǤJ���~��ƨê�l��
    Item( const ItemInfo& data );

    // ���o���~�R�A���
    const ItemInfo& getInfo() const;

    // ��ܪ��~���ԲӸ�T
    void print() const;
};

// ���~�޲z�t�ΡA�t�d���~�����J�M�Ы�
class ItemSystem {
private:
    std::unordered_map<std::string, ItemInfo> itemDefinitions;

public:
    ItemSystem();  // �b�غc�l�̸��J�w�]���~���
    
    // �ھڪ��~ID�Ыت��~���
    Item* createItem( const std::string& id );
};
