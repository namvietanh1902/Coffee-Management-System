#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<iomanip>
#include "Hoadon.h"
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
        friend bool check_exist(const Item &x);
        friend int getInfo(Item*);
        friend void displayx(Item*p,string x);
        friend void display(Item*);
        friend void Add(Item*);
        friend void Delete(Item*);
        friend int check_maItem(Item *p,string ma);        
};
#endif