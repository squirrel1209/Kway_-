// main.cpp

#include "itemSystem.h"


int main() {

    // 創建一個 ItemSystem 物件，會自動加載物品資料
    ItemSystem itemSystem;

    // 根據物品ID創建多個物品實例
    Item* sword = itemSystem.createItem( "sword_iron" );
    Item* axe = itemSystem.createItem( "axe_steel" );
    Item* dragonSword = itemSystem.createItem( "sword_dragon" );
    Item* longBow = itemSystem.createItem( "bow_long" );
    Item* giantHammer = itemSystem.createItem( "hammer_giant" );

    // 測試物品的資料是否正確
    if ( sword != nullptr ) {
        std::cout << "Created Item: " << sword -> getInfo().name << std::endl;
        sword -> print(); // 顯示物品詳細資訊
    } // end if 
    
    else {
        std::cout << "Item 'sword_iron' not found." << std::endl;
    } // end else

    if ( axe != nullptr ) {
        std::cout << "Created Item: " << axe->getInfo().name << std::endl;
        axe->print(); // 顯示物品詳細資訊
    } // end if 
    
    else {
        std::cout << "Item 'axe_steel' not found." << std::endl;
    } // end else

    if ( dragonSword != nullptr ) {
        std::cout << "Created Item: " << dragonSword->getInfo().name << std::endl;
        dragonSword->print(); // 顯示物品詳細資訊
    } // end if 
    
    else {
        std::cout << "Item 'sword_dragon' not found." << std::endl;
    } // end else

    if ( longBow != nullptr ) {
        std::cout << "Created Item: " << longBow->getInfo().name << std::endl;
        longBow->print(); // 顯示物品詳細資訊
    } // end if
    
    else {
        std::cout << "Item 'bow_long' not found." << std::endl;
    } // end else

    if ( giantHammer != nullptr ) {
        std::cout << "Created Item: " << giantHammer->getInfo().name << std::endl;
        giantHammer->print(); // 顯示物品詳細資訊
    } // end if 
    
    else {
        std::cout << "Item 'hammer_giant' not found." << std::endl;
    } // end else

    // 清理記憶體
    delete sword;
    delete axe;
    delete dragonSword;
    delete longBow;
    delete giantHammer;
    
    system( "pause" );
    return 0;
}

