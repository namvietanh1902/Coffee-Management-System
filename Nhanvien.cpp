#include<iostream>
#include<fstream>
#include<string>
#include "Nhanvien.h"
#include<conio.h>
using namespace std;
void Nhanvien::setName(string name){
            this->name=name;
        }
string Nhanvien::getName(){
    return name;
        }
void stringCorrect(string &x){
    int i=0;
    while(x[i]==' '){ x.erase(i,i+1);
    i++;} 
}
void getInfo(Nhanvien *p,int n){
    ifstream myFile;
    myFile.open("Nhanvien.txt",ios::in);
    if(!myFile.is_open()){
        cout<<"Khong mo duoc file";

    }
    int i=0;
    while(!myFile.eof()){
        
        getline(myFile,p[i].name);
        stringCorrect(p[i].name);
        getline(myFile,p[i].chucvu);
        stringCorrect(p[i].chucvu);
        myFile>>p[i].age;
        getline(myFile,p[i].address);
        stringCorrect(p[i].address);
        myFile>>p[i].sdt;  
        i++;
        continue;
    }
    myFile.close();

}
std::ostream& operator <<(ostream &out ,const Nhanvien &p){
    
    out<<"Ten: "<<p.name<<endl;
    out<<"Tuoi: "<<p.age<<endl;
    out<<"Chuc vu: "<<p.chucvu<<endl;
    out<<"Dia chi: "<<p.address<<endl;
    out<<"SDT: "<<p.sdt<<endl;
    return out;
}
std::istream& operator>>(istream &in, Nhanvien &p){

    
    getline(std::cin,p.name);
    getline(std::cin,p.chucvu);
    in>>p.age;
    getline(std::cin,p.address);
    in>>p.sdt;
    return in;
}

    
int main(){

    int n=1000;
    Nhanvien *p = new Nhanvien[n];
    getInfo(p,n);
    cout<<p[0];
    cout<<p[1];
    delete [] p;

}
