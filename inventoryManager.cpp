#include <iostream>
#include <vector>
#include <string>
#include "inventoryManager.h"

using namespace std;

InventoryManager::InventoryManager()
{
    //Function is called on manager creation
}

InventoryManager::~InventoryManager()
{
    cout<< "\nShutting down. Cleaning up memory..." << endl;
    for (Item* item : inventory) 
    {
        delete item; // Free the memory for each item
    }
    inventory.clear();
    cout<< "Memory clear."<<endl;       

}

//=========Create==========
void InventoryManager::addItem(Item* item)
{
    inventory.push_back(item);
    cout<< "Added '"<<item->getName()
    <<"' to inventory."<<endl;
}

//=========Read P1=============
void InventoryManager::listItems() const
{
    cout<< "\n--- Full Inventory List ---"<<endl;
    if (inventory.empty())
    {
        cout<<"Inventory is empty."<<endl;
        return;
    }

    for (Item* item : inventory)
    {
        cout<< " - ID: "<< item->getID()
            << ". Name: "<< item->getName()
            << ", Stock: "<< item->getStock()<<endl;
    }
}

//==========Read P2==========
void InventoryManager::runStatusReport() const
{
    cout<<"\n--- Running Inventory Status Report ---";
    cout<< endl;

    if (inventory.empty())
    {
        cout<<"Inventory is empty."<<endl;
        return;
    }

    for (Item* item : inventory)
    {
        item->checkStatus();
    }
}

//===========Update============
void InventoryManager::updateStock(const string& id, int quantitySold)
{
    Item* item = findItemById(id);

    if (item == nullptr) //Check if the item is found
    {
        cout<<"ERROR: Item with ID '"<<id<<"' not found."<<endl;
        return;
    }

    int currentStock = item->getStock();
    if (quantitySold>currentStock)
    {
        cout<<"ERROR: Not enough stock. Only "<<currentStock
            <<" available."<<endl;
    }
    else
    {
        item->setStock(currentStock-quantitySold);
        cout<<"Sold "<<quantitySold<<" of '"<<item->getName()
            <<"' New stock: "<<item->getStock()<<endl;
    }
}
// ============Delete============
void InventoryManager::removeItem(const string& id) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        
        // *it refers to the pointer in the vector
        if ((*it)->getID() == id) 
        { 
            cout << "SUCCESS: Removing '" << (*it)->getName() << "'..." << endl;
            delete *it; //Delete the pointer
            inventory.erase(it);
            return;
        }
    }
    cout << "ERROR: Item with ID '" << id << "' not found." << endl;
}


Item* InventoryManager::findItemById(const string& id)const
 {
    for (Item* item : inventory) {
        if (item->getID() == id) {
            return item;
        }
    }
    return nullptr;
}