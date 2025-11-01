#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
//===========Saving==============
bool InventoryManager::saveInventory(const string& filename) const
{
    ofstream outFile(filename);

    if (!outFile.is_open())
    {
        cout<<"The file for saving failed to open: "<< filename<<endl;
        return false;
    }
    for (Item* item : inventory)
    {
        outFile<<item-> toFileString()<<endl;
    }

    outFile.close();
    cout<<"\nInventory saved to'"<< filename<<"'"<<endl;
    return true;
}

//=============Load Inventory================
bool InventoryManager::loadInventory(const string& filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open())
    {
        cout<<"Could not open file for loading."<<endl;
        return false;
    }
    for (Item* item : inventory)
    {
        delete item;
    }
    inventory.clear();

    string line;
    while (getline(inFile, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);
        string segment;
        vector<string>data;

        while (getline(ss, segment, ','))
        {
            if (!segment.empty()&& segment.front()==' ')
            {
                segment.erase(0,1);
            }
            data.push_back(segment);
        }

        if (data.size()<5) continue;

        string type= data[0];
        string id= data[1];
        string name= data [2];

        try 
        {
            double price= stod(data[3]);
            int stockLevel= stoi(data[4]);
            Item* newItem= nullptr;

            if (type=="NP")
            {
                newItem= new nonPerishableItem(id, name, price, stockLevel);
            }
            else if (type =="P" && data.size()>=6)
            {
                string expiryDate= data[5];
                newItem= new perishableItem(id, name, price, stockLevel, expiryDate);
            }
            else
            {
                cout<<"Unknown item type or insufficient data: "<< line<< endl;
                continue;
            }

            if (newItem != nullptr)
            {
                inventory.push_back(newItem);
            }
        }

        catch (const std:: exception& e)
        {
            cout<<"Failed to convert string to number in line: "<< line<< "("<< e.what()<<")"<<endl;
        }
    }
        

    inFile.close();
    cout<<"Inventory successfully loaded from '"<<filename<<"'"<<endl;
    return true;
}