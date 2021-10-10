#include "Nhanvien.h"
using namespace std;
int main(){
    int n=1000;
    Nhanvien *NV=new Nhanvien[n];
    getInfo(NV);
    display(NV);
    DeleteNV(NV);
    display(NV);
    addNhanvien(NV);
    display(NV);
    delete [] NV;
    return 0;
}