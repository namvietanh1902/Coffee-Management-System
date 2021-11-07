#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<windows.h>
#include "Nhanvien.h"
#define N 100
using namespace std;
void InLine1(int n){
    for (int i = 0; i < n; i++) 
        cout<<"=";
}
void TextColor1(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
std::ostream& operator <<(std::ostream &out ,const Nhanvien &p){
    out<<p.maNV<<endl;
    out<<p.name<<endl;
    out<<p.chucvu<<endl;
    out<<p.age<<endl;
    out<<p.address<<endl;
    out<<p.sdt<<endl;
    return out;
}
bool check_exist(const Nhanvien &x){
    Nhanvien* p=new Nhanvien[1000];
    int n=getInfo(p);
    for (int i=0;i<n-1;i++){
        if (x.maNV==p[i].maNV) return 1;
    }
    return 0;
    delete [] p;
}
std::istream& operator >>(std::istream &in,Nhanvien &p){
    cout<<"Nhap ma nhan vien: ";getline(cin,p.maNV);
    while(check_exist(p)){
        cout<<"Ma nhan vien da ton tai, nhap lai: ";getline(cin,p.maNV);
    }
    cout<<"Nhap ten: ";getline(cin,p.name);
    cout<<"Nhap tuoi: ";cin>>p.age;getchar();
    cout<<"Nhap chuc vu: ";getline(cin,p.chucvu);
    cout<<"Nhap dia chi: ";getline(cin,p.address);
    cout<<"Nhap so dien thoai: ";getline(cin,p.sdt);
    return in;
}
void Nhanvien:: setmaNV(string maNV){ 
    this->maNV=maNV;
}
string Nhanvien:: getmaNV(){
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

int getInfo(Nhanvien* p){
    ifstream myFile;
    myFile.open("Nhanvien/Nhanvien.txt");
    if (!myFile.is_open()){
        cout<<"Khong mo duoc file";
        system("exit");
    }
    int total=0;
    
    while (!myFile.eof()){
        string line;
        getline(myFile,p[total].maNV);
        getline(myFile,p[total].name);
        getline(myFile,p[total].chucvu);
        getline(myFile,line);
        stringstream geek(line);
        geek>>p[total].age;
        getline(myFile,p[total].address);
        getline(myFile,p[total].sdt);
        total++;
        continue;
    }
    return total;
}
int check_maNV(Nhanvien *p,string ma){
    int total=getInfo(p);cout<<endl;
    int check=0;
    for (int i=0;i<total-1;i++){
        if(ma==p[i].maNV){
           check=1;
        }
    }
    return check;
}
void displaydel(Nhanvien*p,string del){
    int total=getInfo(p);cout<<endl;
    for (int i=0;i<total-1;i++){
        if(del==p[i].maNV){
            cout<<setw(10)<<left<<"MaNV";
            cout<<setw(30)<<left<<"Ten";
            cout<<setw(20)<<left<<"Chuc vu";
            cout<<setw(10)<<left<<"Tuoi";
            cout<<setw(25)<<left<<"Dia chi";
            cout<<setw(15)<<left<<"So dien thoai"<<endl;
            cout<<setw(10)<<left<<p[i].maNV;
            cout<<setw(30)<<left<<p[i].name;
            cout<<setw(20)<<left<<p[i].chucvu;
            cout<<setw(10)<<left<<p[i].age;
            cout<<setw(25)<<left<<p[i].address;
            cout<<setw(15)<<left<<p[i].sdt<<endl;
        }
    }
}
void display(Nhanvien* p){
    int total=getInfo(p);cout<<endl;
    InLine1(47);TextColor1(11);
    cout<<"Danh Sach Nhan Vien";TextColor1(7);
    InLine1(48);cout<<endl;
    cout<<"+----------------------------------------------------------------------------------------------------------------+\n";
    cout<<setw(10)<<left<<"|  MaNV";
    cout<<setw(30)<<left<<"|         Ho va ten";
    cout<<setw(20)<<left<<"|      Chuc vu";
    cout<<setw(10)<<left<<"|  Tuoi";
    cout<<setw(25)<<left<<"|        Dia chi";
    cout<<setw(15)<<left<<"|  So dien thoai  |"<<endl;
    cout<<"+----------------------------------------------------------------------------------------------------------------+\n";

    for (int i=0;i<total-1;i++){
    cout<<"|  "<<setw(7)<<left<<p[i].maNV;
    cout<<"|   "<<setw(26)<<left<<p[i].name;
    cout<<"|      "<<setw(13)<<left<<p[i].chucvu;
    cout<<"|   "<<setw(6)<<left<<p[i].age;
    cout<<"|  "<<setw(22)<<left<<p[i].address;
    cout<<"|   "<<setw(14)<<left<<p[i].sdt<<"|"<<endl;
    }
    cout<<"+----------------------------------------------------------------------------------------------------------------+\n";
}
void Add(Nhanvien* p){
    add:
    string pass;
    ofstream out;
    out.open("Password/staff.txt",ios::app);
    cout<<endl;InLine1(45);TextColor1(11);
    cout<<"Them  Nhan Vien";TextColor1(7);
    InLine1(45);cout<<endl;
    Nhanvien x;
    ofstream file2;
    file2.open("Nhanvien/Nhanvien.txt",ios::app);
    if(!file2.is_open()) return;
    cin>>x;
    cout<<"Nhap mat khau cho nhan vien nay: ";cin>>pass;
    out<<x.maNV<<" "<<pass<<endl;
    file2<<x;
    getInfo(p);
    file2.close();
    out.close();
    TextColor1(10);cout<<"\n\t  Da them thanh cong\n";TextColor1(7);
    cout<<"\nBan co muon tiep tuc them nhan vien?(y/n) : ";
    char t;cin>>t;getchar();
        if(t=='y'){
            system("cls");
            goto add;
        }

}
void Delete(Nhanvien *p){
    DEL:
    cout<<endl;InLine1(45);TextColor1(11);
    cout<<"Xoa Nhan Vien";TextColor1(7);
    InLine1(45);cout<<endl;
    string del;
    cout<<"\nNhap ma cua nhan vien ban muon xoa: ";cin>>del;
    if(check_maNV(p,del)==0){
        TextColor1(12); cout<<"Ma nhan vien nay khong ton tai";TextColor1(7); 
        cout<<"\n\nBan co muon nhap lai ma nhan vien ? (y/n) : ";
        char t;cin>>t;
            if(t=='y'){
            system("cls");
            goto DEL;
            }
    }
    else{
    cout<<"\nThong tin nhan vien muon xoa :";
    displaydel(p,del);
    ifstream is("Nhanvien/Nhanvien.txt");
    cout<<"Ban co chac muon xoa :";
    TextColor1(14);cout<<"\n\n\t    -Notification-";TextColor1(7);
    cout<<"\n  +--------------------------------+";
	cout<<"\n  |      1.CO           2.KHONG    |";
	cout<<"\n  +--------------------------------+";
    char a;
    cout<<"\n\nNhap lua chon : ";cin>>a;
    switch (a){
        case '1' :
        {   
            ofstream out;
            ifstream in;
            string username,pass;

            in.open("Password/staff.txt");
            out.open("Password/temp.txt");
            ofstream file2;
            file2.open("Nhanvien/temp.txt", ofstream::out);
            while(in>>username>>pass){
                if(username!=del) out<<username<<" "<<pass<<endl;
            }
            int n=getInfo(p);
            int i;      
            for ( i=0;i<n-1;i++){
            if (del==p[i].maNV) {
            break;
                }
            }
            for(int j=0;j<n-1;j++){
            if(j!=i){
            file2<<p[j];
                }
            }
            TextColor1(10);cout<<"\n\n\t  Da xoa thanh cong\n";TextColor1(7);
            file2.close();
            is.close();
            in.close();
            out.close();
            remove("Password/staff.txt");
            rename("Password/temp.txt","Password/staff.txt");
            remove("Nhanvien/Nhanvien.txt");
            rename("Nhanvien/temp.txt", "Nhanvien/Nhanvien.txt");
            cout<<"\nBan co muon tiep tuc xoa nhan vien (y/n) :" ;
            char d;cin>>d;
            if(d=='y'){
            system("cls");
            goto DEL;
            }
            break;
        }
        case '2':
        {
        cout<<"\nBan co muon tiep tuc xoa nhan vien (y/n) :" ;char d;cin>>d;
        if(d=='y'){
            system("cls");
            goto DEL;
           }
           break;
            }
        }
    }
}




