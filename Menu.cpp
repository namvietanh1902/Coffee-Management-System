#include "Menu.h"
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
void Manager(){
    string _Username,_Pass,username,pass;
    ifstream in;
    in.open("admin/admin.txt");
    in>>username>>pass;
    char c;
    Man:
    cout<<"Enter your username: ";cin>>_Username;
    cout<<"Enter your password: ";
    while ((c=_getch()) !=13)
{
    _Pass.push_back(c);
    _putch('*');
}
    if (_Username==username&&pass==_Pass) cout<<"\nDang nhap thanh cong\n";
    else {cout<<"\nSai mat khau.\n1.Dang nhap lai\n2.Ket thuc\nNhap lua chon: ";
    char d;cin>>d;
    switch(d){
        case '1':{
            Manager();
            break;
        }
        case '2':{
            system("exit");
            break;
        }
    }}
    in.close();
}
void resetPass(){
    string _Pass,username,pass,newpass,data;
    ifstream in;
    in.open("admin/admin.txt");
    in>>username>>pass;
    cout<<"Vui long nhap mat khau cu: ";
    char c;
    while ((c=_getch()) !=13)
{
    _Pass.push_back(c);
    _putch('*');
}
    if (_Pass==pass){
        datlai:
        cout<<"\nNhap mat khau moi: ";
          while ((c=_getch()) !=13)
        {
        newpass.push_back(c);
        _putch('*');
        }
        cout<<"\nNhap lai mat khau moi: ";
         while ((c=_getch()) !=13)
        {
        data.push_back(c);
        _putch('*');
        }
        if (newpass==data){
            cout<<"\nDa doi mat khau thanh cong.\n";
            ofstream out;
            out.open("admin/admin.txt",ios::trunc);
            out<<username<<" "<<newpass;
            out.close();
        }
        else{
            cout<<"Mat khau khong khop, dat lai khong?\n1.Co\n2.Khong\nNhap lua chon: ";
            char d; cin>>d;
            switch(d){
                case '1':{
                    goto datlai;
                    break;
                }
                case '2':{
                    system("exit");//thoat ra
                    break;
                }
            }
            
        }
        

    }
    else{
        cout<<"\nSai mat khau\n";
    }
    in.close();


}
int main(){
    Manager();
    resetPass();
}