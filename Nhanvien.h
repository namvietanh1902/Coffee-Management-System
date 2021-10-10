#ifndef NHANVIEN_H
#define NHANVIEN_H
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<conio.h>
#include<iomanip>
using namespace std;
static int ma=0;

class Nhanvien{

    private:
      int maNV;
        string chucvu;
        string name;
        int age;
        string address;
        string sdt;
    public:
        
        Nhanvien(){
       
           
        }
        friend std::ostream& operator <<(std::ostream & ,const Nhanvien &);
        friend std::istream& operator >>(std::istream &,Nhanvien &);
        friend void getInfo(Nhanvien*);
        void setmaNV(int maNV);
        int getmaNV();
        void setChucvu(string chucvu);
        string getChucvu();
        void setName(string name);
        string getName();
        void setAge(int age);
        int getAge();
        void setAddress(string address);
        string getAddress();
        void setSDT(string sdt);
        string getSDT();
        friend void display(Nhanvien*);
        friend void Add(Nhanvien *p);
        friend void Delete(Nhanvien*p);
};

#endif