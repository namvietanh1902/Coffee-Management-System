#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
class Nhanvien{
    private:
        int stt;
        string name;
        int age;
        string address;
        string sdt;
    public:
        Nhanvien(){}
        friend std::ostream& operator <<(std::ostream & ,const Nhanvien &);
        friend std::istream& operator >>(std::istream &,Nhanvien &);
        friend void getInfo(Nhanvien*,int n);
};
void getInfo(Nhanvien *p,int n){
    ifstream myFile;
    myFile.open("Nhanvien.txt",ios::in);
    if(myFile.is_open()){
        cout<<"Mo thanh cong";

    }
    int i=0;
    while(!myFile.eof()){
        myFile>>p[i].stt;
        getline(myFile,p[i].name);
        myFile>>p[i].age;
        getline(myFile,p[i].address);
        myFile>>p[i].sdt;  
        i++;
        continue;
    }
    myFile.close();

}
std::ostream& operator <<(ostream &out ,const Nhanvien &p){
    out<<"STT: "<<p.stt<<endl;
    out<<"Ten: "<<p.name<<endl;
    out<<"Tuoi: "<<p.age<<endl;
    out<<"Dia chi: "<<p.address<<endl;
    out<<"SDT: "<<p.sdt<<endl;
    return out;
}
std::istream& operator>>(istream &in, Nhanvien &p){

    in>>p.stt;
    getline(std::cin,p.name);
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
