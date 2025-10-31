#ifndef PERISHABLEITEM_H
#define PERISHABLEITEM_H

#include "Item.h"

class perishableItem: public Item
{
    protected:
        std::string expiryDate;

    public:
        perishableItem(std::string id, std::string name, double price,
        int stockLevel, std::string expiryDate)
            :Item(id, name, price, stockLevel), expiryDate(expiryDate)
            {}
        
        virtual std::string toFileString() const override;
        virtual void checkStatus() const override;   

};
#endif