#ifndef NHANVIEN
#define NHANVIEN
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<conio.h>
using namespace std;
class Nhanvien{
    private:
        string chucvu;
        string name;
        int age;
        string address;
        string sdt;
    public:
        Nhanvien(){}
        friend std::ostream& operator <<(std::ostream & ,const Nhanvien &);
        friend std::istream& operator >>(std::istream &,Nhanvien &);
        friend void getInfo(Nhanvien*,int n);
        void setName(string name);
        string getName();

};
void stringCorrect(string &);
#endif