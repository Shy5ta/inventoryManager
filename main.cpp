#include <iostream>
#include "InventoryManager.h"

using namespace std;

int main() {
    InventoryManager manager;

    //Create
    manager.addItem(new nonPerishableItem("np-001", "Soap", 15.99, 20));
    manager.addItem(new perishableItem("p-001", "Bread", 12.99, 10, "2025-10-30"));
    manager.addItem(new perishableItem("p-002", "Milk", 25.50, 5, "2025-11-02"));

    // read
    manager.listItems();
    manager.runStatusReport();

    // Update
    cout << "\n--- Testing Update ---" << endl;
    manager.updateStock("p-001", 3);  
    manager.updateStock("np-001", 30); 
    manager.updateStock("xx-001", 1); 

    // Delete
    cout << "\n--- Testing Delete ---" << endl;
    manager.removeItem("p-002"); 
    manager.removeItem("xx-001"); 
    cout << "\n--- Final Report After All Operations ---" << endl;
    manager.runStatusReport();
    return 0;
}