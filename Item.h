#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <sstream>

class Item
{
    protected:
        std::string id;
        std::string name;
        double price;
        int stockLevel;

    public:
    //Function for a new item being created
    Item(std::string id, std::string name, double price, int stockLevel)
    : id(id), name(name), price(price), stockLevel(stockLevel)
    {

    }

    virtual ~Item(){}

    virtual std::string toFileString()const = 0; //Format the data for a .txt

    virtual void checkStatus() const = 0; //Check low stock

    std::string getID() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stockLevel; }

    void setStock (int newStock)//Updating stock level
    {
        if (newStock>=0)
        {
            stockLevel = newStock;
        }
        else
        {
            stockLevel = 0;
        }
    }
};

#endif
