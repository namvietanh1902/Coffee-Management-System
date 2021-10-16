#include "Nhanvien.h"
#include "Item.h"
#include "Hoadon.h"
using namespace std;
int main(){
    Item *Menu=new Item[100];
    Add(Menu);
    Hoadon p;
    Cashier(p);
    delete [] Menu;
    return 0;
    
}