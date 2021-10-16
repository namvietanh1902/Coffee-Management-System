#include "Hoadon.h"
#include "Item.h"
#include "Nhanvien.h"

using namespace std;
Hoadon::Hoadon(){
    Menu=new Item[MAX];
    soluong=new int[MAX];
}
Hoadon::~Hoadon(){
    delete [] Menu;
    delete [] soluong;
}
ostream& operator<<(ostream& out,const Hoadon &p){
    for (int i=0;i<p.total;i++){
        out<<p.Menu[i].getTenItem()<<" "<<p.soluong[i]<<" "<<p.soluong[i]*p.Menu[i].getprice()<<endl;
    }
    out<<p.price<<endl;
    return out;
}
void Cashier(Hoadon &p){
    cout<<"Nhap ma hoa don: ";cin>>p.maHD;
    ifstream in;
    ofstream file;
    in.open("Hoadon/"+p.maHD+".txt");
    while (in){
        cout<<"Ma da duoc su dung, vui long nhap lai: ";
        cin>>p.maHD;
        in.open("Hoadon/"+p.maHD+".txt");
    }
    file.open("Hoadon/"+p.maHD+".txt");
    Cont:
    system("cls");
    Item *x=new Item[MAX];
    display(x);
    int n=getInfo(x);
    cout<<"Nhap ma mat hang: ";
    string line;
    cin>>line;
    for (int i=0;i<n-1;i++){
        if(line==x[i].getmaItem()) {p.Menu[p.total]=x[i];
        break;} 
    }
    cout<<"Nhap so luong: ";cin>>p.soluong[p.total];
    p.price+=p.soluong[p.total]*p.Menu[p.total].getprice();
    p.total++;
    
    cout<<"Thanh tien?\n1.Khong\n2.Co\n";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            goto Cont;
            break;
        case 2:
            break;
            return;
    }
    file<<p;
    file.close();
    in.close();

}
        
    
   

