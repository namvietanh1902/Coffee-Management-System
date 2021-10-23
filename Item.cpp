#include "Item.h"
#include<iostream>
#include<windows.h>
using namespace std;
void InLine2(int n){
    for (int i = 0; i < n; i++) 
        cout<<"=";
}
void TextColor2(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
std::ostream& operator <<(std::ostream &out ,const Item &p){
    out<<p.maItem<<endl;
    out<<p.tenItem<<endl;
    out<<p.price<<endl;
    return out;
}
std::istream& operator >>(std::istream &in,Item &p){
    cout<<"Nhap ma mat hang: ";getline(cin,p.maItem);
    cout<<"Nhap ten mat hang: ";getline(cin,p.tenItem);
    cout<<"Nhap gia: ";in>>p.price;
    return in;
}
    void Item::setmaItem(string maIteam){
        this->maItem=maIteam;
    }
    string  Item::getmaItem(){
        return maItem;
    }
    void Item::setTenItem(string tenIteam){
        this->tenItem=tenIteam;
    }
    string Item::getTenItem(){
        return tenItem;
    }
    void Item::setPrice(int price){
        this->price=price;
    }
    int  Item::getprice(){
        return price;
    }
int getInfo(Item* p){
    ifstream myFile;
    myFile.open("Item/Item.txt");
    if (!myFile.is_open()){
        cout<<"Khong mo duoc file";
        system("exit");
    }
    int total=0;
    while (!myFile.eof()){
        string line;
        getline(myFile,p[total].maItem);
        getline(myFile,p[total].tenItem);
        getline(myFile,line);
        stringstream geek(line);
        geek>>p[total].price;
        total++;
        continue;
    }
    myFile.close();
    return total;
}
void display(Item* p){
    int n=getInfo(p);cout<<endl;
    InLine2(19);TextColor2(11);
    cout<<"Thuc Don";TextColor2(7);
    InLine2(19); cout<<endl;
    cout<<setw(10)<<left<<"MaMH";
    cout<<setw(30)<<left<<"Ten mon";
    cout<<setw(20)<<left<<"Gia"<<endl;
    for (int i=0;i<n-1;i++){
    cout<<setw(10)<<left<<p[i].maItem;
    cout<<setw(30)<<left<<p[i].tenItem;
    cout<<setw(20)<<left<<p[i].price<<endl;
    }
    cout<<endl;
}
void Add(Item *p){
    cout<<endl;InLine2(19);TextColor2(11);
    cout<<"Them Item";TextColor2(7);
    InLine2(19); cout<<endl;
    Item x;
    ofstream file2;
    file2.open("Item/Item.txt",ios::app);
    if(!file2.is_open()) return;
    cin>>x;
    file2<<x;
    getInfo(p);
    file2.close();
}
void Delete(Item *p){
    Del:
    cout<<endl;InLine2(19);TextColor2(11);
    cout<<"Xoa Item";TextColor2(7);
    InLine2(19); cout<<endl;
    string x;
    cout<<"\nNhap ma cua mat hang ban muon xoa: ";cin>>x;
    cout<<x;
    ifstream is("Item/Item.txt");
    TextColor2(14);cout<<"\n\n\t    -Notification-";TextColor2(7);
    cout<<"\n  +--------------------------------+";
	cout<<"\n  |      1.CO           2.KHONG    |";
	cout<<"\n  +--------------------------------+";
    char a;
    cout<<"\n\nNhap lua chon : ";cin>>a;
    switch (a){
        case '1' :
        {
            ofstream file2;
            file2.open("temp.txt", ofstream::out);
            int n=getInfo(p);
            int i;
            for (i=0;i<n-1;i++){
            if(x==p[i].maItem) break;
                }
            for(int j=0;j<n-1;j++){
            if(j!=i){
            file2<<p[j];
                }
            }
            TextColor2(10);cout<<"\n\n\t  Da xoa thanh cong\n";TextColor2(7);
            file2.close();
            remove("Item/Item.txt");
            rename("temp.txt", "Item/Item.txt");
            break;
        }
        case '2':
        {
        cout<<"\nBan co muon tiep tuc xoa nhan vien (Y/N) :" ;char d;cin>>d;
        if(d=='Y'){
            system("cls");
            goto Del;
           }
           break;
        }
    }
    is.close();
}