#include "Inventory.h"
#include <iostream>
#include <sstream>

// 建構子
Inventory::Inventory(int max) : maxSlots(max) {}

bool Inventory::addItem(Item* item, int quantity) {
    if ( items.size() >= maxSlots ) return false;  // 超過最大容量

    if (items.find(item->getInfo().id) != items.end()) {
        items[item->getInfo().id].quantity += quantity;
    } 

    else {
        items[item->getInfo().id] = { item, quantity };
    }
    return true;
}

bool Inventory::removeItem(const std::string& itemId, int quantity) {
    if (items.find(itemId) == items.end()) return false;

    if (items[itemId].quantity < quantity) return false;

    items[itemId].quantity -= quantity;
    if (items[itemId].quantity == 0) {
        items.erase(itemId);
    }
    return true;
}

void Inventory::showInventory() const {
    for (const auto& entry : items) {
        std::cout << entry.first << ": " << entry.second.quantity << "\n";
    }
}

std::string Inventory::serialize() const {
    std::ostringstream oss;
    for (const auto& entry : items) {
        const ItemInfo& itemInfo = entry.second.item->getInfo();
        oss << itemInfo.id << "," << entry.second.quantity << "\n";  // 格式為 "itemId,quantity"
    }
    return oss.str();
}

bool Inventory::deserialize(const std::string& data, ItemSystem& itemSystem) {
    std::istringstream iss(data);
    std::string line;
    while (std::getline(iss, line)) {
        std::istringstream itemStream(line);
        std::string itemId;
        int quantity;
        if (std::getline(itemStream, itemId, ',') && itemStream >> quantity) {
            Item* item = itemSystem.createItem(itemId);
            if (item) {
                addItem(item, quantity);
            } else {
                std::cerr << "無法找到物品：" << itemId << std::endl;
                return false;
            }
        }
    }
    return true;
}
