#include <iostream>
#include <sstream>
#include "nonPerishableItem.h"

using namespace std;

nonPerishableItem::~nonPerishableItem()
{

}

string nonPerishableItem::toFileString() const
{
    stringstream sStream;
    sStream<<"NP,"<<id<<","<<name<<","<<price<<","<<stockLevel;

    return sStream.str();
}

void nonPerishableItem::checkStatus() const
{
    cout << "--- Item: " << name << " (ID: " << id << ") ---" << endl;
    cout << "  Type: Non-Perishable" << endl;
    cout << "  Stock: " << stockLevel << endl;

    if (stockLevel <= 5) {
        cout << "  >> STATUS: WARNING - Low stock!" << endl;
    } else {
        cout << "  >> STATUS: OK" << endl;
    }
    cout << "-----------------------------------" << endl;
}