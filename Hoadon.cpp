#include "Hoadon.h"
#include "Item.h"
#include "Nhanvien.h"
void read(const string &x){
    ifstream in;
    in.open(x);
    string line;
    while (getline(in,line)){
        cout<<line<<endl;
    }
    in.close();
}
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
    out<<"Ngay thu ngan: "<<p.day<<"/"<<p.month<<"/"<<p.year<<endl;
    out<<"Nhan vien thu ngan: "<<p.maNV<<endl;
    out<<setw(30)<<left<<"Ten mon";
    out<<setw(10)<<left<<"So luong";
    out<<setw(10)<<left<<"Thanh tien"<<endl;
    for (int i=0;i<p.total;i++){
        out<<setw(30)<<left<<p.Menu[i].getTenItem();
        out<<setw(10)<<left<<p.soluong[i];
        out<<setw(10)<<left<<p.soluong[i]*p.Menu[i].getprice()<<endl;
    }
    out<<"Tong gia tien: "<<p.price<<endl;
    return out;
}
void Cashier(Hoadon &p){
    Nhanvien *NV=new Nhanvien[MAX];
    display(NV);
    cout<<"Nhap ngay thu ngan: ";cin>>p.day>>p.month>>p.year;
    cout<<"Nhap ma nhan vien: ";cin>>p.maNV;
    system("cls");
    ofstream log;
    log.open("History/log.txt",ios::app);
    cout<<"Nhap ma hoa don: ";cin>>p.maHD;
    ifstream in;
    ofstream file;
    ofstream out;
    out.open("DSHoaDon.txt",ios::app);
    
    in.open("Hoadon/"+p.maHD+".txt");
    while (in){
        cout<<"Ma da duoc su dung, vui long nhap lai: ";
        cin>>p.maHD;
        in.open("Hoadon/"+p.maHD+".txt");
    }
    out<<p.maHD<<endl;
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
    log<<p.day<<" "<<p.month<<" "<<p.year<<" "<<p.maNV<<" "<<p.maHD<<" "<<p.price<<endl;
    file<<p;
    file.close();
    in.close();
    out.close();
    ifstream in2;
    system("cls");
    read("Hoadon/"+p.maHD+".txt");
    log.close();
}
void display(Hoadon &p){
    ifstream in;
    in.open("history/log.txt");
    int day,month ,year,price;
    string maNV,maHD;
    while(in>>day>>month>>year>>maNV>>maHD>>price){
        cout<<maHD;
        cout<<endl;
    }
    in.close();
    cout<<"\nChon hoa don can xem: ";
    string maHD1;
    cin>>maHD1;
    read("Hoadon/"+maHD1+".txt");
}

        
    
   

