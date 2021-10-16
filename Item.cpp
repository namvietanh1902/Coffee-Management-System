#include "Item.h"
using namespace std;
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
    int n=getInfo(p);
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
    string x;
    cout<<"Nhap ma cua mat hang ban muon xoa: ";cin>>x;
    cout<<x;

    ifstream is("Item/Item.txt");
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
  
    file2.close();
    is.close();
    remove("Item/Item.txt");

    rename("temp.txt", "Item/Item.txt");
}