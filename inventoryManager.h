#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <vector>
#include <string>
#include <map>

#include "Item.h"
#include "nonPerishableItem.h"
#include "perishableItem.h"

class InventoryManager
{
    private:
        std::map<std::string, Item*> inventory;
        Item* findItemById(const std::string& id) const;

    public:
        InventoryManager();
        ~InventoryManager();
    
    //CRUD Operations
    
    //Create new item
    void addItem(Item* item);

    //Read (p1) items 
    void listItems() const;

    //Read (p2) items and statusCheck
    void runStatusReport() const;

    //Update items
    void updateStock(const std::string& id, int quantitySold);

    //Delete item
    void removeItem(const std::string& id);

    bool saveInventory (const std:: string& fileName)const;
    bool loadInventory (const std::string& fileName);

};

#endif