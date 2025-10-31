#include <iostream>
#include <sstream>
#include "perishableItem.h"

using namespace std;

string perishableItem::toFileString() const
{
    std:: stringstream sStream;
    sStream << "P," << id << "," << name << ","
    << price << "," << stockLevel << "," << expiryDate;
    return sStream.str();
}

void perishableItem::checkStatus() const
{
    cout<< "--- Item: " << name << " (ID: " << id << ") ---" << endl;
    cout<< "  Type: Perishable" << endl;
    cout<< "  Stock: " << stockLevel << endl;
    cout<< "  Expiry Date: " << expiryDate << endl;

    if (stockLevel <= 5) {
        cout<< "  >> STATUS: WARNING - Low stock!" << endl;
    } else {
        cout << "  >> STATUS: OK" << endl;
    }
    cout<< "==================================="<< endl;            
}