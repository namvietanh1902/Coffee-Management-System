#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
static int maMH;
class Item{
    private:
        int maItem;
        string tenItem;
        int price;
    public:
        Item(){}
        friend std::ostream& operator <<(std::ostream & ,const Item &);
        friend std::istream& operator >>(std::istream &,Item &);
        void setmaIteam(int maIteam);
        int getmaIteam();
        void setTenIteam(string tenIteam);
        string  getTenIteam();
        void setPrice(int price);
        int getprice();
        friend void getInfo(Item*);
        friend void display(Item*);
        friend void Add(Item*);
        friend void Delete(Item*);
};
#endif