#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include "Nhanvien.h"
using namespace std;
std::ostream& operator <<(std::ostream &out ,const Nhanvien &p){
    out<<"Ma Nhan Vien: "<<p.maNV<<endl;
    out<<"Ten: "<<p.name<<endl;
    out<<"Tuoi: "<<p.age<<endl;
    out<<"Dia chi: "<<p.address<<endl;
    out<<"SDT: "<<p.sdt<<endl;
    return out;
}
std::istream& operator >>(std::istream &in,Nhanvien &p){
    cout<<"Nhap ten: ";getline(cin,p.name);
    cout<<"Nhap tuoi: ";cin>>p.age;
    cout<<"Nhap chuc vu: ";getline(cin,p.chucvu);
    cout<<"Nhap dia chi: ";getline(cin,p.address);
    cout<<"Nhap so dien thoai:";getline(cin,p.sdt);
    return in;
}
void getInfo(Nhanvien* p,int n){
    ifstream myFile;
    myFile.open("Nhanvien/Nhanvien.txt");
    if (!myFile.is_open()){
        cout<<"Khong mo duoc file";
        return;
    }
    int i=0;
    while (!myFile.eof()){
        p[i].maNV=++ma;
        getline(myFile,p[i].name);
        getline(myFile,p[i].chucvu);
        myFile>>p[i].age;
        getline(myFile,p[i].address);
        getline(myFile,p[i].sdt);
        i++;
        continue;
    }
}
