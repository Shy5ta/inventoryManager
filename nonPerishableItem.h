#ifndef NONPERISHABLEITEM_H
#define NONPERISHABLEITEM_H

#include "Item.h"

class nonPerishableItem: public Item
{
    public:
    nonPerishableItem(std::string id, std::string name, double price,
        int stockLevel)
    : Item(id, name, price, stockLevel)
    {

    }

    virtual std::string toFileString() const override;

    virtual void checkStatus() const override;
};
#endif