#include <iostream>
#include <limits>
#include <string>
#include "InventoryManager.h"
#include "nonPerishableItem.h"
#include "perishableItem.h"

using namespace std;

// Define a constant for the filename
const string INVENTORY_FILE = "inventory.txt";

// Helper function to handle menu display and robust input
int showMenu() {
    int choice;
    cout << "\n===================================" << endl;
    cout << "       Inventory Manager Menu " << endl;
    cout << "===================================" << endl;
    cout << "1. List All Items (Read P1)" << endl;
    cout << "2. Run Status Report (Read P2)" << endl;
    cout << "3. Update Item Stock (Sell)" << endl;
    cout << "4. Remove Item" << endl;
    cout << "5. Add New Item (Simple)" << endl;
    cout << "0. Save and Exit" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Enter your choice (0-5): ";
    
    // Robust input validation loop
    while (!(cin >> choice) || choice < 0 || choice > 5) {
        cout << "Invalid input. Please enter a number between 0 and 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

void handleAddNewItem(InventoryManager& manager) {
    string type, id, name, expiryDate;
    double price;
    int stock;

    std::cout << "--- Add New Item ---" << endl;
    std::cout << "Enter Item Type (P for Perishable, NP for Non-Perishable): ";
    cin >> type;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Enter Item ID: ";
    getline(cin, id);

    std::cout << "Enter Item Name (can contain spaces): ";
    getline(cin, name);

    std::cout << "Enter Price: ";
    while (!(cin >> price))
    {
        cout << "Invalid input. Please enter a numerical price: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // FIX 1: ADDED PROMPT AND INPUT FOR STOCK LEVEL
    std::cout << "Enter Initial Stock Level: ";
    while (!(cin >> stock))
    {
        cout << "Invalid input. Please enter a numerical stock level: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // FIX 2: Clear buffer AFTER reading the last number (stock)
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    if (type == "P" || type == "p") {
        std::cout << "Enter Expiry Date (DD-MM-YYYY): ";
        // Read the date, assuming DD-MM-YYYY format will be used for display/parsing
        getline(cin, expiryDate); 
        manager.addItem(new perishableItem(id, name, price, stock, expiryDate));
    } else if (type == "NP" || type == "np") {
        manager.addItem(new nonPerishableItem(id, name, price, stock));
    } else {
        cout << "ERROR: Invalid item type specified." << endl;
    }
}

int main() {
    InventoryManager manager;

    // --- File Persistence Load ---
    cout << "--- Attempting to load inventory from " << INVENTORY_FILE << " ---" << endl;
    bool loadSuccessful = manager.loadInventory(INVENTORY_FILE);

    // Initial items only added if load failed (e.g., first run)
    if (!loadSuccessful) { 
        cout << "\n--- Adding initial items for first-time use ---" << endl;
        manager.addItem(new nonPerishableItem("np-001", "Soap", 15.99, 20));
        manager.addItem(new perishableItem("p-001", "Bread", 12.99, 10, "2025-10-30"));
        manager.addItem(new perishableItem("p-002", "Milk", 25.50, 5, "2025-11-02"));
    }

    int choice;
    string id;
    int quantity;
    // --- START OF THE INTERACTIVE LOOP ---
    do {
        choice = showMenu();
        
        // FIX 3: Removed redundant cin.ignore here, as showMenu cleans the buffer.
        // It's added back into the switch-case for choices that use cin >> 
        
        switch (choice) {
            case 1: // List Items
                manager.listItems();
                break;
            case 2: // Run Status Report
                manager.runStatusReport();
                break;
            case 3: // Update Stock (Sell)
                cout << "Enter Item ID to update stock: ";
                // Clear buffer only when reading numbers right after cin >> id
                cin >> id; 
                cout << "Enter quantity sold: ";
                cin >> quantity;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer after last number
                manager.updateStock(id, quantity);
                break;
            case 4: // Remove Item
                cout << "Enter Item ID to remove: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer after cin >> id
                manager.removeItem(id);
                break;
            case 5: // Add New Item
                handleAddNewItem(manager);
                break;
            case 0: // Save and Exit
                cout << "Shutting down and saving data..." << endl;
                break;
            default:
                cout << "Invalid menu choice. Please try again." << endl;
        }

    } while (choice != 0);
    // --- END OF THE INTERACTIVE LOOP ---

    // --- File Persistence Save ---
    manager.saveInventory(INVENTORY_FILE);
    
    return 0;
}