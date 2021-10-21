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
    int i=0;
    _Pass="";
    do
{
    c = _getch();

    if (c == 13 || c == ' ' )
    {
        break;
    }
    if((c==8 || c==127) && !_Pass.empty())
    {
        cout<<"\b \b";
        _Pass.erase(_Pass.size()-1);
    }
   else{ _Pass.push_back(c);
    _putch('*');}

}while(c!=13 || c!=' ');
    if (_Username==username&&pass==_Pass) cout<<"\nDang nhap thanh cong\n";
    else {cout<<"\nSai mat khau.\n1.Dang nhap lai\n2.Ket thuc\nNhap lua chon: ";
    char d;cin>>d;
    switch(d){
        case '1':{
            goto Man;
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
    _Pass="";
   do
{
    c = _getch();

    if (c == 13 || c == ' ' )
    {
        break;
    }
    if((c==8 || c==127) && !_Pass.empty())
    {
        cout<<"\b \b";
        _Pass.erase(_Pass.size()-1);
    }
   else{ _Pass.push_back(c);
    _putch('*');}

}while(c!=13 || c!=' ');
    if (_Pass==pass){
        datlai:
        newpass="";
        data="";
        cout<<"\nNhap mat khau moi: ";
       do
    {
        c =   _getch();

    if (c == 13 || c == ' ' )
    {
            break;
    }
    if((c==8 || c==127) && !newpass.empty())
    {
            cout<<"\b \b";
            newpass.erase(newpass.size()-1);
    }
        else{ newpass.push_back(c);
        _putch('*');}

    }while(c!=13 || c!=' ');
        cout<<"\nNhap lai mat khau moi: ";
        do
{
    c = _getch();

    if (c == 13 || c == ' ' )
    {
        break;
    }
    if((c==8 || c==127) && !data.empty())
    {
        cout<<"\b \b";
        data.erase(data.size()-1);
    }
   else{ data.push_back(c);
    _putch('*');}

}while(c!=13 || c!=' ');
        if (newpass==data){
            cout<<"\nDa doi mat khau thanh cong.\n";
            ofstream out;
            out.open("admin/admin.txt",ios::trunc);
            out<<username<<" "<<newpass;
            out.close();
        }
        else{
            cout<<"\nMat khau khong khop, dat lai khong?\n1.Co\n2.Khong\nNhap lua chon: ";
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
