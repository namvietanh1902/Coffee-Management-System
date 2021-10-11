#include "Item.h"
using namespace std;
std::ostream& operator <<(std::ostream &out ,const Item &p){
    out<<p.tenItem<<endl;
    out<<p.price<<endl;
    return out;
}
std::istream& operator >>(std::istream &in,Item &p){
    cout<<"Nhap ten mat hang: ";getline(cin,p.tenItem);
    cout<<"Nhap gia: ";in>>p.price;
    return in;
}
    void Item::setmaItem(int maIteam){
        this->maItem=maIteam;
    }
    int  Item::getmaItem(){
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
void getInfo(Item* p){
    ifstream myFile;
    myFile.open("Item/Item.txt");
    if (!myFile.is_open()){
        cout<<"Khong mo duoc file";
        return;
    }
    int i=0;
    maMH=0;
    while (!myFile.eof()){
        string line;
        p[i].maItem=++maMH;
        getline(myFile,p[i].tenItem);
        getline(myFile,line);
        stringstream geek(line);
        geek>>p[i].price;
        i++;
        continue;
    }
    myFile.close();
}
void display(Item* p){
    getInfo(p);
    cout<<setw(10)<<left<<"MaMH";
    cout<<setw(30)<<left<<"Ten mon";
    cout<<setw(20)<<left<<"Gia"<<endl;
  
    for (int i=0;i<maMH-1;i++){
    cout<<setw(10)<<left<<p[i].maItem;
    cout<<setw(30)<<left<<p[i].tenItem;
    cout<<setw(20)<<left<<p[i].price<<endl;
   
    }
    cout<<endl;
}
void Add(Item *p){
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
    int i;
    cout<<"Nhap ma cua mat hang ban muon xoa: ";cin>>i;getchar();

    ifstream is("Item/Item.txt");
    ofstream file2;
    file2.open("temp.txt", ofstream::out);

    getInfo(p);
    for(int j=0;j<maMH-1;j++){
        if(j!=i-1){

     file2<<p[j];
        }
    }
  
    file2.close();
    is.close();
    remove("Item/Item.txt");

    rename("temp.txt", "Item/Item.txt");
    getInfo(p);
}