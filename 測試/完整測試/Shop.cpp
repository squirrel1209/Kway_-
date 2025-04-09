#include "Shop.h"
#include <iomanip>  // for std::setw
// ANSI 顏色碼
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define WHITE   "\033[37m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

Shop::Shop( ItemSystem& system ) : itemSystem( system ) {}  // 傳入 ItemSystem 參考作為建構子

// 判斷中文字元（簡單判定 UTF-8 開頭位元）
bool isChineseChar(unsigned char c) {
    return (c & 0x80);
}

// 計算中文字實際寬度（中文字當作寬度2）
int getVisualWidth( const std::string& str ) {
    int width = 0;
    for  ( size_t i = 0; i < str.size(); ) {
        if ( ( unsigned char )str[i] >= 0x80 ) {
            width += 2;
            // UTF-8 中文通常為 3 bytes
            i += 3;
        } // end if 
        
        else {
            width += 1;
            i += 1;
        } // end else
    } // end for

    return width;
} // end

// 補空格到固定視覺寬度
std::string padRight( const std::string& str, int totalWidth ) {
    int visualWidth = getVisualWidth(str);
    int padding = totalWidth - visualWidth;
    return str + std::string(padding, ' ');
}

void Shop::showItems() const {
    std::cout << BOLD << CYAN << "\n========== 商店物品清單 ==========" << RESET << "\n\n";

    std::cout << BOLD << WHITE
              << padRight( "物品ID", 16 )
              << padRight( "名稱", 10 )
              << padRight( "描述", 40 )
              << padRight( "攻擊力", 10 )
              << "價格" << RESET << "\n";

    std::cout << "--------------------------------------------------------------------------\n";

    for (const auto& pair : itemSystem.itemDefinitions) {
        const ItemInfo& item = pair.second;

        std::cout << GREEN
                  << padRight(item.id, 16)
                  << padRight(item.name, 10)
                  << padRight(item.description, 40)
                  << padRight( std::to_string( item.attack ), 10 )
                  << item.price
                  << RESET << "\n";
    }

    std::cout << CYAN << "\n===================================" << RESET << "\n";
}

void Shop::buyItem( Character& player, const std::string& itemId ) {
    auto it = itemSystem.itemDefinitions.find( itemId );

    if ( it != itemSystem.itemDefinitions.end() ) {
        const ItemInfo& item = it->second;
        // 假設有方法處理購物邏輯
        std::cout << player.getName() << " 購買了 " << item.name << "，價格為 " << item.price << "。\n";
    } // end if
    
    else {
        std::cout << "找不到物品，請確認物品ID。\n";
    } // end else
} // end buyItem()

void Shop::sellItem( Character& player, const Item& item ) {
    // 假設有方法處理賣出邏輯
    std::cout << player.getName() << " 賣出了 " << item.getInfo().name << "。\n";
} // end sellItem()
