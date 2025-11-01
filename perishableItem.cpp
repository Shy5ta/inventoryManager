#include <iostream>
#include <sstream>
#include <ctime>
#include<chrono>
#include <cstdio>

#include "perishableItem.h"

using namespace std;

perishableItem::~perishableItem()
{

}

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

    //Validate expiry date
    int expYear, expMonth, expDay;
    sscanf(expiryDate.c_str(), "%d-%d-%d", &expDay, &expMonth, &expYear);

    struct tm expiryTime={0};

    expiryTime.tm_year= expYear-1900;
    expiryTime.tm_mon= expMonth-1;
    expiryTime.tm_mday= expDay;
    time_t expirySeconds= mktime(&expiryTime);
    time_t currentSeconds= time(nullptr);

    if (expirySeconds<currentSeconds)
    {
        cout<<" >> EXPIRED!"<<endl;
    }

    if (stockLevel <= 5) {
        cout<< "  >> WARNING - Low stock!" << endl;
    } else {
        cout << "  >> STOCK LEVEL OK" << endl;
    }
    cout<< "==================================="<< endl;            
}