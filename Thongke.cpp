#include "Thongke.h"
#include "Nhanvien.h"
#include "Hoadon.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<conio.h>
#include<windows.h>
using namespace std;
void InLine4(int n){
    for (int i = 0; i < n; i++) 
        cout<<"=";
}
void TextColor4(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void read1(const string &x){
    ifstream in;
    in.open(x);
    string line;
    while (getline(in,line)){
        cout<<line<<endl;
    }
    in.close();
}
int KiemTraNam(int y,int m){
    bool check;
    if(y%400==0 || (y%4==0 && y%100!=0)){
        check=0;
    }
    else check=1;
    return check;
}
int KiemTraThang(int m,int y){
    bool check;
    if(m>=1&&m<=12&&y>0){
        check=1;
    }
    else check=0;
    return check;
}
void SoNgayTrongThang(int y,int m,int a[13]){
    int i;
    for(i=1;i<=12;i++){
        if(i<=7)
            if(i%2!=0) a[i]=31;
            else a[i]=30;
        if(i>=8)
            if(i%2==0) a[i]=31;
            else a[i]=30;
        if(i==2)
            if(KiemTraNam(y,m)==0) a[i]=29;
            else a[i]=28;
    }
}
int KiemTraNgay(int d,int m,int y){
    bool check;
    int a[13];
    SoNgayTrongThang(y,m,a);
    if(d<=a[m] && d>0)
        check=1;
    else check=0;
    return check;
}
void statsDay(){
    Nhapngay:
    string *line=new string[1000];
    cout<<endl;InLine4(19);TextColor4(11);
    cout<<"Thong ke theo ngay";TextColor4(7);
    InLine4(19); cout<<endl;
    int d,m,y;
    cout<<"Nhap ngay muon xem: ";cin>>d>>m>>y;
    if(KiemTraNgay(d,m,y)==0){
        TextColor4(12);cout<<"\nNgay,thang,nam khong hop le\n";TextColor4(7);
        cout<<"\nBan co muon nhap lai ngay muon xem (y/n) : ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto Nhapngay;
        }
    }
    else{
    again:
    int day,month ,year;
    string maNV,maHD;
    int price;
    unsigned int sum=0;
    ifstream infile;
    int tot=0;
    infile.open("history/log.txt");
    while(infile>>day>>month>>year>>maNV>>maHD>>price){
        if(day==d&&month==m&&year==y){
            line[tot++]=maHD;
            sum+=price;
        }
    }
    if(tot==0){
        cout<<"Ngay "<<d<<" thang "<<m<<" nam "<<y<<" khong co hoa don nao\n";
        cout<<"\nBan co muon tiep tuc thao tac thong ke doanh thu theo ngay ? (y/n) :  ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto Nhapngay;
        }
    }
    else{
    cout<<"Hoa don trong ngay "<<d<<" thang "<<m<<" nam "<<y<<" la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
    }
    cout<<"Doanh thu ngay nay la: " <<sum<<endl;
    cout<<"\nBan co muon xem chi tiet hoa don ngay "<<d<<" thang "<<m<<" nam "<<y<<" khong (y/n) ? : ";
    char v;cin>>v;
        if(v=='y'){
            hoadon1:
            cout<<"\nChon hoa don can xem: ";
            string maHD1;
            cin>>maHD1;
            int dem=0;
            for(int i=0;i<tot;i++){
            if(maHD1==line[i]){
                dem++;   
                read1("Hoadon/"+maHD1+".txt");
                cout<<"\nBan co muon tiep tuc xem hoa don (y/n) ? : ";
                char p;cin>>p;
                if(p=='y'){
                    goto hoadon1;
                    }
                }
            }
            if(dem==0){ 
                cout<<"\nMa hoa don khong ton tai hoac ngay "<<d<<" thang "<<m<<" nam "<<y<<" khong thu ngan hoa don nay";
                cout<<"\nBan co muon tiep tuc xem hoa don (y/n) ? : ";
                char y;cin>>y;
                if(y=='y'){
                    goto hoadon1;
                }
            }

        }
    cout<<"\nBan co muon tiep tuc thao tac thong ke doanh thu theo ngay ? (y/n) :  ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto Nhapngay;
             }
        }
    }
    delete [] line;
}
void statsMonth(){
    string *line=new string[1000];
    Nhapthang:
    int m,y;
    cout<<endl;InLine4(19);TextColor4(11);
    cout<<"Thong ke theo thang";TextColor4(7);
    InLine4(19); cout<<endl;
    cout<<"Nhap thang muon xem: ";cin>>m>>y;
    if(KiemTraThang(m,y)==0) {
        TextColor4(12);cout<<"\nThang hoac thang khong hop le\n";TextColor4(7);
        cout<<"\nBan co muon nhap lai thang muon xem (y/n) : ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto Nhapthang;
        } 
    }
    else{
    int day,month ,year;
    string maNV,maHD;
    int price;
    unsigned int sum=0;
    ifstream infile;
    int tot=0;
    infile.open("history/log.txt");
    while(infile>>day>>month>>year>>maNV>>maHD>>price){
        if(month==m&&year==y){
            line[tot++]=maHD;
            sum+=price;
        }
    }
    if(tot==0){
        cout<<"Thang "<<m<<" nam "<<y<<" khong co hoa don nao\n";
        cout<<"\nBan co muon tiep tuc thao tac thong ke doanh thu theo thang ? (y/n) :  ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto Nhapthang;
        }
    }
    else{
    cout<<"Hoa don trong thang "<<m<<" nam "<<y<<" la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
    }
    cout<<"Tong doanh thu thang nay la: " <<sum<<endl;
    cout<<"\nBan co muon xem chi tiet hoa don thang "<<m<<" nam "<<y<<" khong (y/n) ? : ";
    char v;cin>>v;
        if(v=='y'){
            hoadon2:
            cout<<"\nChon hoa don can xem: ";
            string maHD1;
            cin>>maHD1;
            int dem=0;
            for(int i=0;i<tot;i++){
            if(maHD1==line[i]){
                dem++;   
                read1("Hoadon/"+maHD1+".txt");
                cout<<"\nBan co muon tiep tuc xem hoa don (y/n) ? : ";
                char p;cin>>p;
                if(p=='y'){
                    goto hoadon2;
                    }
                }
            }
            if(dem==0){ 
                cout<<"\nMa hoa don khong ton tai hoac thang "<<m<<" nam "<<y<<" khong thu ngan hoa don nay";
                cout<<"\nBan co muon tiep tuc xem hoa don (y/n) ? : ";
                char y;cin>>y;
                if(y=='y'){
                    goto hoadon2;
                }
            }

        }
    cout<<"\nBan co muon tiep tuc thao tac thong ke doanh thu theo nam ? (y/n) :  ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto Nhapthang;
            }
        }
    }
    delete [] line;
}
void statsYear(){
    string *line=new string[10000];
    Nhapnam:
    cout<<endl;InLine4(19);TextColor4(11);
    cout<<"Thong ke theo nam";TextColor4(7);
    InLine4(19); cout<<endl;
    int y;
    cout<<"Nhap nam muon xem: ";cin>>y;
    if(y<0){
        TextColor4(12);cout<<"\nNam khong hop le\n";TextColor4(7);
        cout<<"\nBan co muon nhap lai nam muon xem (y/n) : ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto Nhapnam;
        }
    }
    else{
    int day,month ,year;
    string maNV,maHD;
    int price;
    unsigned  int sum=0;
    ifstream infile;
    int tot=0;
    infile.open("history/log.txt");
    while(infile>>day>>month>>year>>maNV>>maHD>>price){
        if(year==y){
            line[tot++]=maHD;
            sum+=price;
        }
    }
    if(tot==0){
        cout<<"Nam "<<y<<" khong co hoa don nao\n";
        cout<<"\nBan co muon tiep tuc thao tac thong ke doanh thu theo nam ? (y/n) :  ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto Nhapnam;
        }
    }
    else{
    cout<<"Hoa don trong nam "<<y<<" la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
    }
    cout<<"Doanh thu nam nay la: " <<sum<<endl;
    cout<<"\nBan co muon xem chi tiet hoa don nam "<<y<<" khong (y/n) ? : ";
    char v;cin>>v;
        if(v=='y'){
            hoadon3:
            cout<<"\nChon hoa don can xem: ";
            string maHD1;
            cin>>maHD1;
            int dem=0;
            for(int i=0;i<tot;i++){
            if(maHD1==line[i]){
                dem++;   
                read1("Hoadon/"+maHD1+".txt");
                cout<<"\nBan co muon tiep tuc xem hoa don (y/n) ? : ";
                char p;cin>>p;
                if(p=='y'){
                    goto hoadon3;
                    }
                }
            }
            if(dem==0){ 
                cout<<"\nMa hoa don khong ton tai hoac nam "<<y<<" khong thu ngan hoa don nay";
                cout<<"\nBan co muon tiep tuc xem hoa don (y/n) ? : ";
                char y;cin>>y;
                if(y=='y'){
                    goto hoadon3;
                }
            }

        }
    cout<<"\nBan co muon tiep tuc thao tac thong ke doanh thu theo nam ? (y/n) :  ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto Nhapnam;
        }
        }
    }
    delete [] line;
}
void statsNhanvien(){
    string *line=new string[1000];
    NhapmaNV:
    cout<<endl;InLine4(19);TextColor4(11);
    cout<<"Thong ke theo nhan vien";TextColor4(7);
    InLine4(19); cout<<endl;
    string ma;
    Nhanvien *NV=new Nhanvien[100];
    cout<<"Nhap ma nhan vien muon xem: ";cin>>ma;
    if(check_maNV(NV,ma)==0){
        TextColor4(12);cout<<"\nMa nhan vien khong hop le\n";TextColor4(7);
        cout<<"\nBan co muon nhap lai ma nhan vien muon xem ?(y/n) : ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto NhapmaNV;
        }
    }
    else{
    int day,month ,year;
    string maNV,maHD;
    int price;
    unsigned int sum=0;
    ifstream infile;
    int tot=0;
    infile.open("history/log.txt");
    while(infile>>day>>month>>year>>maNV>>maHD>>price){
        if(ma==maNV){
            line[tot++]=maHD;
            sum+=price;
        }
    }
    if(tot==0){
        cout<<"Nhan vien nay khong co hoa don nao\n";
        cout<<"\nBan co muon tiep tuc thao tac thong ke doanh thu theo nhan vien ? (y/n) :  ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto NhapmaNV;
        }
    }else{
    cout<<"Hoa don do nhan vien nay thuc hien la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
            }
        cout<<"Doang thu cua nhan vien nay la : "<<sum<<endl;
        cout<<"\nBan co muon xem chi tiet hoa don cua nhan vien co ma la "<<ma<<" khong (y/n) ? : ";
        char v;cin>>v;
        if(v=='y'){
            hoadon1:
            cout<<"\nChon hoa don can xem: ";
            string maHD1;
            cin>>maHD1;
            int dem=0;
            for(int i=0;i<tot;i++){
            if(maHD1==line[i]){
                dem++;   
                read1("Hoadon/"+maHD1+".txt");
                cout<<"\nBan co muon tiep tuc xem hoa don (y/n) ? : ";
                char p;cin>>p;
                if(p=='y'){
                    goto hoadon1;
                    }
                }
            }
            if(dem==0){ 
                cout<<"\nMa hoa don khong ton tai hoac nhan vien co ma la "<<ma<<" khong thu ngan hoa don nay";
                cout<<"\nBan co muon tiep tuc xem hoa don (y/n) ? : ";
                char y;cin>>y;
                if(y=='y'){
                    goto hoadon1;
                }
            }

        } 
        cout<<"\nBan co muon tiep tuc thao tac thong ke doanh thu theo nhan vien ? (y/n) :  ";
        char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto NhapmaNV;
            }   
        }
    }
    delete [] line;
}