#ifndef NHANVIEN_H
#define NHANVIEN_H
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<conio.h>
#include<iomanip>
using namespace std;
class Nhanvien{
    private:
        string maNV;
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
        friend int getInfo(Nhanvien*);
        void setmaNV(string maNV);
        string getmaNV();
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
        void display();
        friend void displaydel(Nhanvien*p,string del);
        friend bool check_exist(const Nhanvien &x);
        friend void display(Nhanvien*);
        friend void Add(Nhanvien *p);
        friend void Delete(Nhanvien*p);
        friend int check_maNV(Nhanvien *p,string ma);
};

#endif