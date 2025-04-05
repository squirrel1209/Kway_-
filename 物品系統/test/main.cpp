// main.cpp

#include "itemSystem.h"


int main() {

    // �Ыؤ@�� ItemSystem ����A�|�۰ʥ[�����~���
    ItemSystem itemSystem;

    // �ھڪ��~ID�Ыئh�Ӫ��~���
    Item* sword = itemSystem.createItem( "sword_iron" );
    Item* axe = itemSystem.createItem( "axe_steel" );
    Item* dragonSword = itemSystem.createItem( "sword_dragon" );
    Item* longBow = itemSystem.createItem( "bow_long" );
    Item* giantHammer = itemSystem.createItem( "hammer_giant" );

    // ���ժ��~����ƬO�_���T
    if ( sword != nullptr ) {
        std::cout << "Created Item: " << sword -> getInfo().name << std::endl;
        sword -> print(); // ��ܪ��~�ԲӸ�T
    } // end if 
    
    else {
        std::cout << "Item 'sword_iron' not found." << std::endl;
    } // end else

    if ( axe != nullptr ) {
        std::cout << "Created Item: " << axe->getInfo().name << std::endl;
        axe->print(); // ��ܪ��~�ԲӸ�T
    } // end if 
    
    else {
        std::cout << "Item 'axe_steel' not found." << std::endl;
    } // end else

    if ( dragonSword != nullptr ) {
        std::cout << "Created Item: " << dragonSword->getInfo().name << std::endl;
        dragonSword->print(); // ��ܪ��~�ԲӸ�T
    } // end if 
    
    else {
        std::cout << "Item 'sword_dragon' not found." << std::endl;
    } // end else

    if ( longBow != nullptr ) {
        std::cout << "Created Item: " << longBow->getInfo().name << std::endl;
        longBow->print(); // ��ܪ��~�ԲӸ�T
    } // end if
    
    else {
        std::cout << "Item 'bow_long' not found." << std::endl;
    } // end else

    if ( giantHammer != nullptr ) {
        std::cout << "Created Item: " << giantHammer->getInfo().name << std::endl;
        giantHammer->print(); // ��ܪ��~�ԲӸ�T
    } // end if 
    
    else {
        std::cout << "Item 'hammer_giant' not found." << std::endl;
    } // end else

    // �M�z�O����
    delete sword;
    delete axe;
    delete dragonSword;
    delete longBow;
    delete giantHammer;
    
    system( "pause" );
    return 0;
}

