#include "Inventory.h"

// 建構函數，初始化背包最大容量
Inventory::Inventory(int max) : maxSlots( max ) {}

// 向背包中添加物品
bool Inventory::addItem( Item* item, int quantity ) {
    std::string itemId = item -> getInfo().id;

    if ( items.size() < maxSlots ) {
        auto it = items.find( itemId );
        if ( it != items.end() ) {
            it -> second.quantity += quantity;  // 更新數量
        } // end if 
        
        else {
            items[itemId] = { item, quantity };  // 新增物品
        } // end else

        return true;
    } // end if

    return false;
} // end addItem()


// 從背包中移除指定數量的物品
bool Inventory::removeItem( const std::string& itemId, int quantity ) {
    auto it = items.find( itemId );

    if ( it != items.end() ) {
        if ( it -> second.quantity >= quantity ) {
            it -> second.quantity -= quantity;

            if ( it -> second.quantity == 0 ) {
                items.erase( it );  // 刪除物品
            } // end if

            return true;
        } // end if
    } // end if

    return false;
} // end removeItem()

void Inventory::showInventory() const {
    for ( const auto& pair : items ) {
        if ( pair.second.item != nullptr ) {
            pair.second.item -> print();  // 呼叫 Item 的 printf()
            std::cout << " 數量: " << pair.second.quantity << std::endl;
        } // end if
        
        else {
            std::cout << "未知物品 ID: " << pair.first << " 數量: " << pair.second.quantity << std::endl;
        } // end else
    } // end for
} // end showInventory()


std::string Inventory::serialize() const {
    std::ostringstream oss;

    for ( const auto& entry : items ) {
        const ItemInfo& itemInfo = entry.second.item -> getInfo();
        oss << itemInfo.id << "," << entry.second.quantity << "\n";  // 格式為 "itemId,quantity"
    } // end for

    return oss.str();
} // end serialize()

// Inventory 類別的反序列化函式：將字串形式的資料還原為物品與數量，並加入玩家背包中
bool Inventory::deserialize( const std::string& data ) {
    // 使用 istringstream 來處理整段資料的輸入串流
    std::istringstream iss( data );
    std::string line;
    ItemSystem itemSystem;

    // 一行一行地讀取資料（每行代表一個物品）
    while ( std::getline( iss, line ) ) {
        // 使用 istringstream 解析單行資料（格式為 "itemId,quantity"）
        std::istringstream itemStream( line );
        std::string itemId;
        int quantity;

        // 分別讀取 itemId 與數量，逗號作為分隔符
        if ( std::getline( itemStream, itemId, ',' ) && itemStream >> quantity ) {
            // 透過 itemSystem 建立對應的 item 物件
            Item* item = itemSystem.createItem( itemId );

            if ( item ) {
                // 若 item 建立成功，加入背包中
                addItem( item, quantity );
            } // end if
            
            else {
                // 若找不到該 itemId，顯示錯誤訊息並回傳 false
                std::cerr << "無法找到物品：" << itemId << std::endl;
                return false;
            } // end else
        } // end if
        // 若格式錯誤（例如少逗號或數量非整數），這行會被忽略
    } // end while

    // 所有物品成功加入背包，返回 true
    return true;
} // end deserialize()


Item* Inventory::getItemById(const std::string& id) {
    auto it = items.find( id );
    if ( it != items.end() ) {
        return it -> second.item;  // 找到對應的物品，返回指標
    } // end if

    return nullptr;  // 如果找不到物品，返回 nullptr
} // end getItemById()