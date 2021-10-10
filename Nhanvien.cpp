#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include "Nhanvien.h"
using namespace std;
void stringCorrect(string &x){
    if(x[0]==' ') x.erase(0,1);
}
std::ostream& operator <<(std::ostream &out ,const Nhanvien &p){

    out<<p.name<<endl;
    out<<p.chucvu<<endl;
    out<<p.age<<p.address<<endl;
    out<<p.sdt<<endl;
    return out;
}
std::istream& operator >>(std::istream &in,Nhanvien &p){
    cout<<"Nhap ten: ";getline(cin,p.name);
    cout<<"Nhap tuoi: ";cin>>p.age;getchar();
    cout<<"Nhap chuc vu: ";getline(cin,p.chucvu);
    cout<<"Nhap dia chi: ";getline(cin,p.address);
    cout<<"Nhap so dien thoai:";getline(cin,p.sdt);
    return in;
}
void Nhanvien:: setmaNV(int maNV){ 
    this->maNV=maNV;
}
int Nhanvien:: getmaNV(){
    return maNV;
}
void Nhanvien:: setChucvu(string chucvu){
    this->chucvu=chucvu;
}
string Nhanvien:: getChucvu(){
    return chucvu;
}
void Nhanvien:: setName(string name){
    this->name=name;
}
string Nhanvien:: getName(){
    return name;
}
void Nhanvien:: setAge(int age){
    this->age=age;
}
int Nhanvien:: getAge(){
    return age;
}
void Nhanvien:: setAddress(string address){
    this->address=address;
}
string Nhanvien:: getAddress(){
    return address;
}
void Nhanvien:: setSDT(string sdt){
    this->sdt=sdt;
}
string Nhanvien:: getSDT(){
    return sdt;
}
void getInfo(Nhanvien* p){
    ifstream myFile;
    myFile.open("Nhanvien/Nhanvien.txt");
    if (!myFile.is_open()){
        cout<<"Khong mo duoc file";
        return;
    }
    int i=0;
    ma=0;
    while (!myFile.eof()){
        p[i].maNV=++ma;
        getline(myFile,p[i].name);
        getline(myFile,p[i].chucvu);
        myFile>>p[i].age;
        getline(myFile,p[i].address);
        stringCorrect(p[i].address);
        getline(myFile,p[i].sdt);
        i++;
        continue;
    }
}
void display(Nhanvien* p){
    getInfo(p);
    cout<<setw(10)<<left<<"MaNV";
    cout<<setw(30)<<left<<"Ten";
    cout<<setw(20)<<left<<"Chuc vu";
    cout<<setw(11)<<left<<"Tuoi";
    cout<<setw(24)<<left<<"Dia chi";
    cout<<setw(15)<<left<<"So dien thoai"<<endl;
    for (int i=0;i<ma-1;i++){
    cout<<setw(10)<<left<<p[i].maNV;
    cout<<setw(30)<<left<<p[i].name;
    cout<<setw(20)<<left<<p[i].chucvu;
    cout<<setw(10)<<left<<p[i].age;
    cout<<setw(25)<<left<<p[i].address;
    cout<<setw(15)<<left<<p[i].sdt<<endl;
    }
    cout<<endl;
}
void addNhanvien(Nhanvien* p){
    Nhanvien x;
    ofstream file2;
    file2.open("Nhanvien/Nhanvien.txt",ios::app);
    if(!file2.is_open()) return;
    cin>>x;
    file2<<x;
    getInfo(p);
    file2.close();
}
void DeleteNV(Nhanvien *p){
    int i;
    cout<<"Nhap ma cua nhan vien ban muon xoa: ";cin>>i;getchar();

    ifstream is("Nhanvien/Nhanvien.txt");
    ofstream file2;
    file2.open("Nhanvien/temp.txt", ofstream::out);

    getInfo(p);
    for(int j=0;j<ma-1;j++){
        if(j!=i-1){

     file2<<p[j];
        }
    }
  
    file2.close();
    is.close();
    remove("Nhanvien/Nhanvien.txt");

    rename("Nhanvien/temp.txt", "Nhanvien/Nhanvien.txt");
    getInfo(p);
}

