#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

class Item{
    private:
        string maItem;
        string tenItem;
        int price;
    public:
        Item(){}
        friend std::ostream& operator <<(std::ostream & ,const Item &);
        friend std::istream& operator >>(std::istream &,Item &);
        void setmaItem(string maIteam);
        string getmaItem();
        void setTenItem(string tenItem);
        string  getTenItem();
        void setPrice(int price);
        int getprice();
        friend int getInfo(Item*);
        friend void display(Item*);
        friend void Add(Item*);
        friend void Delete(Item*);
};
#endif