#include "Thongke.h"
#include "Nhanvien.h"
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
    int day,month ,year;
    string maNV,maHD;
    int price;
    unsigned int sum=0;
    ifstream infile;
    string line[1000];
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
    }
    else{
    cout<<"Hoa don trong ngay "<<d<<" thang "<<m<<" nam "<<y<<" la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
    }
    cout<<"Doanh thu ngay nay la: " <<sum<<endl;
        }
    }
}
void statsMonth(){
    Nhapthang:
    int m,y;
    cout<<endl;InLine4(19);TextColor4(11);
    cout<<"Thong ke theo thang";TextColor4(7);
    InLine4(19); cout<<endl;
    cout<<"Nhap thang muon xem: ";cin>>m>>y;
    if(KiemTraThang(m,y)==0) {
        TextColor4(12);cout<<"\nThang hoac nam khong hop le\n";TextColor4(7);
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
    string line[1000];
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
    }
    else{
    cout<<"Hoa don trong thang "<<m<<" nam "<<y<<" la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
    }
    cout<<"Tong doanh thu thang nay la: " <<sum<<endl;
        }
    }
}
void statsYear(){
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
    string line[10000];
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
    }
    else{
    cout<<"Hoa don trong nam "<<y<<" la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
    }
    cout<<"Doanh thu nam nay la: " <<sum<<endl;
        }
    }
}
void statsNhanvien(){
    NhapmaNV:
    cout<<endl;InLine4(19);TextColor4(11);
    cout<<"Thong ke theo nhan vien";TextColor4(7);
    InLine4(19); cout<<endl;
    string ma;
    Nhanvien *NV=new Nhanvien[100];
    cout<<"Nhap ma nhan vien muon xem: ";cin>>ma;
    if(check_maNV(NV,ma)==0){
        TextColor4(12);cout<<"\nMa nhan vien khong hop le\n";TextColor4(7);
        cout<<"\nBan co muon nhap lai ma nhan vien muon xem (y/n) : ";
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
    string line[1000];
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
    }else{
    cout<<"Hoa don do nhan vien nay thuc hien la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
            }
        cout<<"Doang thu cua nhan vien nay la : "<<sum<<endl;    
        }
    }

}