#include "Nhanvien.h"
#include "Item.h"
using namespace std;
int main(){
    int n=1000;
    Item *Menu=new Item[n];
    Nhanvien *NV=new Nhanvien[n];
    getInfo(NV);
    getInfo(Menu);
    display(Menu);
    display(NV);
    Delete(Menu);
    //display(NV);
    display(Menu);
    delete [] NV;
    delete [] Menu;
    return 0;
}