#include "Nhanvien.h"
using namespace std;
int main(){
    int n=1000;
    Nhanvien *p=new Nhanvien[n];
    getInfo(p);
    display(p);
    addNhanvien(p);
    display(p);
    DeleteNV(p);
    display(p);
    delete [] p;
}