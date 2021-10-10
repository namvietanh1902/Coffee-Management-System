#include "Nhanvien.h"
using namespace std;
int main(){
    int n=1000;
    Nhanvien *NV=new Nhanvien[n];
    getInfo(NV);
       DeleteNV(NV);
    addNhanvien(NV);
    
    display(NV);

    delete [] NV;
    return 0;
}