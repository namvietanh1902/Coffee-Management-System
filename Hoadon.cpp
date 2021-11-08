#include "Hoadon.h"
#include "Item.h"
#include "Nhanvien.h"
#include "Thongke.h"
#include<windows.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
void TextColor5(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void read(const string &x){
    ifstream in;
    in.open(x);
    string line;
    while (getline(in,line)){
        cout<<line<<endl;
    }
    in.close();
}

Hoadon::Hoadon(){
    Menu=new Item[MAX];
    soluong=new int[MAX];
}
Hoadon::~Hoadon(){
    delete [] Menu;
    delete [] soluong;
}
bool check_exist(const string &x){
    ifstream in;
    in.open("Hoadon/"+x+".txt");
    if(in){
        return 1;
    }
    in.close();
    return 0;
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
void Cashier(Hoadon &p,const string &maNV){
    Nhapngay:
    cout<<"Nhap ngay thu ngan: ";cin>>p.day>>p.month>>p.year;
    if(KiemTraNgay(p.day,p.month,p.year)==0){
        TextColor5(12);cout<<"\nNgay,thang,nam khong hop le\n";TextColor5(7);
        cout<<"\nBan co muon nhap lai ngay thu ngan (y/n) : ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto Nhapngay;
        }
    }
    else{
    ofstream log;
    p.maNV=maNV;
    log.open("History/log.txt",ios::app);
    cout<<"Nhap ma hoa don: ";cin>>p.maHD;
    ofstream file; 
    while (check_exist(p.maHD)){
        cout<<"Ma da duoc su dung, vui long nhap lai: ";
        cin>>p.maHD;
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
    if(check_maItem(x,line)==0){
        TextColor5(12); cout<<"Ma Item nay khong ton tai";TextColor5(7); 
        cout<<"\n\nBan co muon nhap lai ma Item ? (y/n) : ";
        char t;cin>>t;
            if(t=='y'){
            system("cls");
            goto Cont;
            }
    }
    else{
    for (int i=0;i<n-1;i++){
        if(line==x[i].getmaItem()) {p.Menu[p.total]=x[i];
        break;} 
    }
    cout<<"Nhap so luong: ";cin>>p.soluong[p.total];
    for(int i=0;i<p.total;i++){
        if (p.Menu[i].getmaItem()==p.Menu[p.total].getmaItem()){
            p.soluong[i]+=p.soluong[p.total];
            p.total--;
        }
    }

 //   p.price+=p.soluong[p.total]*p.Menu[p.total].getprice();
 
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
    for (int i=0;i<p.total-1;i++){
        p.price+=p.soluong[i]*p.Menu[i].getprice();
    }
    log<<p.day<<" "<<p.month<<" "<<p.year<<" "<<p.maNV<<" "<<p.maHD<<" "<<p.price<<endl;
    file<<p;
    file.close();
    ifstream in2;
    system("cls");
    read("Hoadon/"+p.maHD+".txt");
    log.close();
        }
        }
    }

void display(Hoadon &p){
    hoadon:
    ifstream in;
    in.open("history/log.txt");
    int day,month ,year,price;
    string maNV,maHD;
    cout<<"";
   	cout<<"+----------------------------------------------------------+\n";
	cout<<"|  Ma Hoa Don"<<"\t|\t"<<"Thoi gian thuc hien giao dich      |\n";
	cout<<"+----------------------------------------------------------+\n";
    while(in>>day>>month>>year>>maNV>>maHD>>price){
    
        if(day<10&&month<10){
            cout<<"|  "<<maHD<<"\t|\t"<<day<<"/"<<month<<"/"<<setw(21)<<left<<year<<setw(11)<<right<<"|"<<endl;
        }
        else if(day<10){
            cout<<"|  "<<maHD<<"\t|\t"<<day<<"/"<<month<<"/"<<setw(21)<<left<<year<<setw(10)<<right<<"|"<<endl;
        }
        else if(month<10){
            cout<<"|  "<<maHD<<"\t|\t"<<day<<"/"<<month<<"/"<<setw(21)<<left<<year<<setw(10)<<right<<"|"<<endl;
        }
        else cout<<"|  "<<maHD<<"\t|\t"<<day<<"/"<<month<<"/"<<setw(20)<<left<<year<<setw(10)<<right<<"|"<<endl;
    }
    cout<<"+----------------------------------------------------------+\n";
    in.close();
    cout<<"\nChon hoa don can xem: ";
    string maHD1;
    cin>>maHD1;
    if(!check_exist(maHD1)){
        TextColor5(12); cout<<"\nHoa don nay khong ton tai"; TextColor5(7);
        cout<<"\nBan co muon tiep tuc xem hoa don? (y/n) : ";
        char t;cin>>t;getchar();
        if(t=='y'){
            system("cls");
            goto hoadon;
        }
    }
    else{
    read("Hoadon/"+maHD1+".txt");
    cout<<"Ban co muon tiep tuc xem hoa don? (y/n) : ";
     char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto hoadon;
        }
    }
}

        
    
   

