#include "Nhanvien.h"
#include "Item.h"
using namespace std;
int main(){
    int n=1000;
    Item *Menu=new Item[n];
    Nhanvien *NV=new Nhanvien[n];
    Add(NV);
    Delete(NV);
    display(NV);
    delete [] NV;
    delete [] Menu;
    return 0;
}