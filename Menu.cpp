#include "Menu.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<conio.h>
#include<windows.h>
using namespace std;
void TextColor3(int x){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , x );
}

void Manager(){
    string _Username,_Pass,username,pass;
    ifstream in;
    in.open("admin/admin.txt");
    in>>username>>pass;
    char c;
    
    Man:
    cout<<"\n\n\n";
	cout<<"\t\t\t\t\t\t\t+-------------------+"<<endl;
	cout<<"\t\t\t\t\t\t\t|";TextColor3(14);cout<<"    -LOGIN NOW-    ";TextColor3(7);cout<<"|"<<endl;
	cout<<"\t\t\t\t\t\t\t+-------------------+"<<endl;
	cout<<"\n\n";
    cout<<"\t\t\t\t\t\tUsername : ";cin>>_Username;
    cout<<"\n";
    cout<<"\t\t\t\t\t\tPassword : ";
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
    if (_Username==username&&pass==_Pass)
    {
        TextColor3(10);cout<<"\n\n\t\t\t\t\t\t\tLogged in successfully!\n";TextColor3(7);
         }
    else {
        TextColor3(12);cout<<"\n\n\t\t\t\t\t\t  Username or Password is incorrect";TextColor3(7);
        cout<<"\n\n\t\t\t\t\t\t\t";TextColor3(14);cout<<"    -Notification-";TextColor3(7);
        cout<<"\n\t\t\t\t\t\t\t+--------------------+";
	    cout<<"\n\t\t\t\t\t\t\t|   1.Login again    |";
	    cout<<"\n\t\t\t\t\t\t\t|   2.Exit           |";
	    cout<<"\n\t\t\t\t\t\t\t+--------------------+";
	    cout<<"\n\n\t\t\t\t\t\tYour choice : ";
    char d;cin>>d;
    switch(d){
        case '1':{
            system("cls");
            goto Man;
            break;
        }
        case '2':{
            exit(0);
            break;
        }
    }
    }
    in.close();
}
void resetPass(){
    string _Pass,username,pass,newpass,data;
    ifstream in;
    in.open("admin/admin.txt");
    in>>username>>pass;
    Reset:
    cout<<"\n\n\n";
	cout<<"\t\t\t\t\t\t\t+--------------------------+"<<endl;
	cout<<"\t\t\t\t\t\t\t|";TextColor3(14);cout<<"     -RESET PASSWORD-     ";TextColor3(7);cout<<"|"<<endl;
	cout<<"\t\t\t\t\t\t\t+--------------------------+"<<endl;
    cout<<"\n\n\t\t\t\t\tPlease input current password : ";
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
        cout<<"\n\n\t\t\t\t\t\t\t New password : ";
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
        cout<<"\n\n\t\t\t\t\t     Retype your new password : ";
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
           
            TextColor3(10);cout<<"\n\n\t\t\t\t\t\t\tSuccessful change\n\n";TextColor3(7);
            ofstream out;
            out.open("admin/admin.txt",ios::trunc);
            out<<username<<" "<<newpass;
            system("pause");
            out.close();
        }
        else{
             TextColor3(12);cout<<"\n\n\t\t\t\t\t\tNew password is incorrect,try again?";TextColor3(7);
            cout<<"\n\n\t\t\t\t\t\t\t";TextColor3(14);cout<<"       -Notification-";TextColor3(7);
             cout<<"\n\t\t\t\t\t\t\t   +--------------------+";
	         cout<<"\n\t\t\t\t\t\t\t   |   1.Yes            |";
	         cout<<"\n\t\t\t\t\t\t\t   |   2.No             |";
	         cout<<"\n\t\t\t\t\t\t\t   +--------------------+";
	         cout<<"\n\n\t\t\t\t\t\tYour choice ";
            char d; cin>>d;
            switch(d){
                case '1':{
                    system("cls");
                    goto Reset;
                    break;
                }
                case '2':{
                    system("cls");//thoat ra
                    break;
                }
            }            
        }
    }
    else{
        TextColor3(12);cout<<"\n\n\t\t\t\t\t\t  Incorrect Password";TextColor3(7); 
        cout<<"\n\n\t\t\t\t\t\t\t";TextColor3(14);cout<<"      -Notification-";TextColor3(7);
        cout<<"\n\t\t\t\t\t\t\t   +---------------------+";
	    cout<<"\n\t\t\t\t\t\t\t   |     1.Try again     |";
	    cout<<"\n\t\t\t\t\t\t\t   |     2.Return        |";
	    cout<<"\n\t\t\t\t\t\t\t   +---------------------+";
	    cout<<"\n\n\t\t\t\t\t\tYour choice : ";
        char t; cin>>t;
          switch(t){
        case '1':{
            system("cls");
            goto Reset;
            break;
        }
        case '2':{
            system("exit");
            break;
        }
    }
    }
    in.close();
}
void statsMonth(){
    int m,y;
    cout<<"Nhap thang muon xem: ";cin>>m>>y;
    int day,month ,year;
    string maNV,maHD;
    int price;
    int sum=0;
    ifstream infile;
    string line[1000];
    int tot=0;
    infile.open("history/log.txt");
    while(infile>>day>>month>>year>>maNV>>maHD>>price){
        if(month==m&&year==y){
            line[tot++]=maHD;
            sum+=price;
        }
    }
    cout<<"Hoa don trong thang "<<m<<" nam "<<y<<" la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
    }
    cout<<"Tong doanh thu thang nay la: " <<sum;

}
void statsDay(){
    int d,m,y;
    cout<<"Nhap ngay muon xem: ";cin>>d>>m>>y;
    int day,month ,year;
    string maNV,maHD;
    int price;
    int sum=0;
    ifstream infile;
    string line[1000];
    int tot=0;
    infile.open("history/log.txt");
    while(infile>>day>>month>>year>>maNV>>maHD>>price){
        if(day==d&&month==m&&year==y){
            line[tot++]=maHD;
            sum+=price;
        }
    }
    cout<<"Hoa don trong ngay "<<d<<" thang "<<m<<" nam "<<y<<" la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
    }
    cout<<"Doanh thu thang nay la: " <<sum;

}
void statsYear(){
    int y;
    cout<<"Nhap nam muon xem: ";cin>>y;
    int day,month ,year;
    string maNV,maHD;
    int price;
    int sum=0;
    ifstream infile;
    string line[1000];
    int tot=0;
    infile.open("history/log.txt");
    while(infile>>day>>month>>year>>maNV>>maHD>>price){
        if(year==y){
            line[tot++]=maHD;
            sum+=price;
        }
    }
    cout<<"Hoa don trong nam "<<y<<" la:\n";
    for(int i=0;i<tot;i++){
        cout<<line[i]<<endl;
    }
    cout<<"Doanh thu nam nay la: " <<sum;

}
int main(){
    statsYear();
}