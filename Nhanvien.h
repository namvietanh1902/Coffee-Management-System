#ifndef NHANVIEN_H
#define NHANVIEN_H
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<conio.h>
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
        friend void getInfo(Nhanvien*,int n);
        void setName(string name);
        string getName();
        void display();
        friend void display();
};

#endif