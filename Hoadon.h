#ifndef HOADON_H
#define HOADON_H
#include "Item.h"
#include "Nhanvien.h"
#define MAX 1000
using namespace std;
class Item;
class Hoadon{
    private:
        string maHD;
        string maNV;
        Item *Menu;
        int *soluong;
        int price=0;
        int total=0;
    public:
        Hoadon();
        ~Hoadon();
        friend void Cashier(Hoadon &p);
        void display();
        friend ostream& operator<<(ostream& out,const Hoadon &p);
       
};
#endif
