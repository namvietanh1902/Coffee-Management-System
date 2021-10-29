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
bool check_exist(const Item &x){
    Item* p=new Item[1000];
    int n=getInfo(p);
    for (int i=0;i<n-1;i++){
        if (x.maItem==p[i].maItem) return 1;
    }
    return 0;
    delete [] p;
}
std::istream& operator >>(std::istream &in,Item &p){
    cout<<"Nhap ma mat hang: ";getline(cin,p.maItem);
    while(check_exist(p)){
        cout<<"Ma mat hang da duoc su dung, nhap lai: ";
        getline(cin,p.maItem);
        
    }
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
void displayx(Item*p,string x){
    int total=getInfo(p);cout<<endl;
    for (int i=0;i<total-1;i++){
        if(x==p[i].maItem){
            cout<<setw(10)<<left<<"MaMH";
            cout<<setw(30)<<left<<"Ten mon";
            cout<<setw(20)<<left<<"Gia"<<endl;
            cout<<setw(10)<<left<<p[i].maItem;
            cout<<setw(30)<<left<<p[i].tenItem;
            cout<<setw(20)<<left<<p[i].price<<endl;
        }
    }
}
void display(Item* p){
    int n=getInfo(p);cout<<endl;
    InLine2(21);TextColor2(11);
    cout<<"Thuc Don";TextColor2(7);
    InLine2(23); cout<<endl;
    cout<<"+--------------------------------------------------+\n";
    cout<<setw(10)<<left<<"|  MaMH";
    cout<<setw(26)<<left<<"|         Ten mon";
    cout<<setw(20)<<left<<"|     Gia      |"<<endl;
    cout<<"+--------------------------------------------------+\n";
    for (int i=0;i<n-1;i++){
    cout<<"|  "<<setw(7)<<left<<p[i].maItem;
    cout<<"|   "<<setw(22)<<left<<p[i].tenItem;
    cout<<"|    "<<setw(10)<<left<<p[i].price<<"|"<<endl;
    }
    cout<<"+--------------------------------------------------+\n";
}
void Add(Item *p){
    add:
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
    TextColor2(10);cout<<"\n\t  Da them thanh cong\n";TextColor2(7);
    cout<<"\nBan co muon tiep tuc them Item? (y/n) : ";
    char t;cin>>t;
        if(t=='y'){
            system("cls");
            goto add;
        }

}
int check_maItem(Item *p,string ma){
    int total=getInfo(p);cout<<endl;
    int check=0;
    for (int i=0;i<total-1;i++){
        if(ma==p[i].maItem){
           check=1;
        }
    }
    return check;
}
void Delete(Item *p){
    Del:
    cout<<endl;InLine2(19);TextColor2(11);
    cout<<"Xoa Item";TextColor2(7);
    InLine2(19); cout<<endl;
    string x;
    cout<<"\nNhap ma cua mat hang ban muon xoa: ";cin>>x;
    if(check_maItem(p,x)==0){
        TextColor2(12); cout<<"Ma Item nay khong ton tai";TextColor2(7); 
        cout<<"\n\nBan co muon nhap lai ma Item ? (y/n) : ";
        char t;cin>>t;
            if(t=='y'){
            system("cls");
            goto Del;
            }
    }
    else{
    cout<<"\nThong tin Item muon xoa :";
    displayx(p,x);
    ifstream is("Item/Item.txt");
    cout<<"Ban co chac muon xoa :";
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
            is.close();
            remove("Item/Item.txt");
            rename("temp.txt", "Item/Item.txt");
            cout<<"\nBan co muon tiep tuc xoa Item (y/n) :" ;char d;cin>>d;
            if(d=='y'){
            system("cls");
            goto Del;
           }
            break;
        }
        case '2':
        {
        cout<<"\nBan co muon tiep tuc xoa Item (Y/N) :" ;char d;cin>>d;
        if(d=='Y'){
            system("cls");
            goto Del;
           }
           break;
            }
        }
    }
}
