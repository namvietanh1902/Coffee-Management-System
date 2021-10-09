#include "Nhanvien.h"
using namespace std;
int main(){
    int n=1000;
    Nhanvien *p=new Nhanvien[n];
    getInfo(p,n);
    cout<<p[0];
    cout<<p[1];
    delete [] p;
}