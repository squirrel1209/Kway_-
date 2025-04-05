#include "ItemSystem.h"

Item::Item( const ItemInfo& data ) : info( data ) {}

// ���o���~���R�A���
const ItemInfo& Item::getInfo() const {
    return info; // ��^���~���R�A���
} // end getInfo()

// ��ܪ��~���ԲӸ�T�]�W�١B����B�y�z�B�����O���^
void Item::print() const {
    std::cout << "[Item] " << info.name << " (" << info.id << ")\n";  // ��ܪ��~�W�ٻPID
    std::cout << "Price: " << info.price << "\n";                       // ��ܪ��~����
    std::cout << info.description << "\n";                              // ��ܪ��~�y�z
    std::cout << "Attack: " << info.attack << "\n";                     // ��ܪ��~�������O
} // end print()

// ItemSystem ���O�غc�l�G���J�w�]�����~���
ItemSystem::ItemSystem() {
    // �K�C
    ItemInfo sword;
    sword.id = "sword_iron";
    sword.name = "�K�C";
    sword.description = "���q���K�C�A�A�X�s��ϥΡC";
    sword.price = 50;
    sword.attack = 10;

    // ����
    ItemInfo axe;
    axe.id = "axe_steel";
    axe.name = "����";
    axe.description = "���s�����Y�A�����O�󰪡C";
    axe.price = 80;
    axe.attack = 15;

    // �s���C
    ItemInfo dragonSword;
    dragonSword.id = "sword_dragon";
    dragonSword.name = "�s���C";
    dragonSword.description = "�ǻ������s���C�A�֦������������O�C";
    dragonSword.price = 200;
    dragonSword.attack = 50;

    // ���}
    ItemInfo longBow;
    longBow.id = "bow_long";
    longBow.name = "���}";
    longBow.description = "�A�X���Z�����������}�C";
    longBow.price = 120;
    longBow.attack = 30;

    // ����
    ItemInfo giantHammer;
    giantHammer.id = "hammer_giant";
    giantHammer.name = "����";
    giantHammer.description = "����������A��y���j�j�������C";
    giantHammer.price = 150;
    giantHammer.attack = 40;

    // �N���~��Ʀs�J���~�w�q�]ID -> ItemInfo�^
    itemDefinitions[sword.id] = sword;
    itemDefinitions[axe.id] = axe;
    itemDefinitions[dragonSword.id] = dragonSword;
    itemDefinitions[longBow.id] = longBow;
    itemDefinitions[giantHammer.id] = giantHammer;
} // end ItemSystem()

// �ھڪ��~ID�Ыؤ@�Ӫ��~���
Item* ItemSystem::createItem( const std::string& id ) {
    if ( !itemDefinitions.count(id) ) return nullptr;  // �p�G�S���Ӫ��~ID�A��^ nullptr
    return new Item( itemDefinitions[id] );  // �ھڪ��~ID�Ыت��~��Ҩê�^
}
