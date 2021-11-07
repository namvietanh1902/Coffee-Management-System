#include "PasswordNV.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;
void TextColor7(int x){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , x );
}
void passInput(string &x){
    x="";
    char c;
    do
        {
    c = _getch();

    if (c == 13 || c == ' ' )
    {
        break;
    }
    if((c==8 || c==127) && !x.empty())
    {
        cout<<"\b \b";
        x.erase(x.size()-1);
    }
   else{ x.push_back(c);
    _putch('*');}

}while(c!=13 || c!=' ');
}
std::string Staff(){
    string _Username,_Pass,username,pass;
    ifstream in;
    bool found=false;
    in.open("Password/staff.txt");
    cout<<"\n\n\n";
	cout<<"\t\t\t\t\t\t\t+-------------------+"<<endl;
	cout<<"\t\t\t\t\t\t\t|";TextColor7(14);cout<<"    -LOGIN NOW-    ";TextColor7(7);cout<<"|"<<endl;
	cout<<"\t\t\t\t\t\t\t+-------------------+"<<endl;
	cout<<"\n\n";
    cout<<"\t\t\t\t\t\tUsername : ";cin>>_Username;
    cout<<"\n";
    cout<<"\t\t\t\t\t\tPassword : ";
    passInput(_Pass);
    while(in>>username>>pass){
        if (_Username==username&&pass==_Pass) {
            found =true;
            break;}

    }
    if (found)
    {
        TextColor7(10);cout<<"\n\n\t\t\t\t\t\t\tLogged in successfully!\n";TextColor7(7);
         }
    else {
        TextColor7(12);cout<<"\n\n\t\t\t\t\t\t  Username or Password is incorrect";TextColor7(7);
        cout<<"\n\n\t\t\t\t\t\t\t";TextColor7(14);cout<<"    -Notification-";TextColor7(7);
        cout<<"\n\t\t\t\t\t\t\t+--------------------+";
	    cout<<"\n\t\t\t\t\t\t\t|   1.Login again    |";
	    cout<<"\n\t\t\t\t\t\t\t|   2.Exit           |";
	    cout<<"\n\t\t\t\t\t\t\t+--------------------+";
	    cout<<"\n\n\t\t\t\t\t\tYour choice : ";
    char d;cin>>d;
    switch(d){
        case '1':{
            system("cls");
            Staff();
            break;
        }
        case '2':{
            exit(0);
            break;
        }
    }
    }
    in.close();
    return _Username;
}
void resetPassNV(const string &username){
    string _Pass,_Username,pass,newpass,data;
    ifstream on;
    on.open("Password/staff.txt");
    while(on>>_Username>>pass){
        if (username==_Username) break;
    }
    on.close();
    Reset:
    cout<<"\n\n\n";
	cout<<"\t\t\t\t\t\t\t+--------------------------+"<<endl;
	cout<<"\t\t\t\t\t\t\t|";TextColor7(14);cout<<"     -RESET PASSWORD-     ";TextColor7(7);cout<<"|"<<endl;
	cout<<"\t\t\t\t\t\t\t+--------------------------+"<<endl;
    cout<<"\n\n\t\t\t\t\tPlease input current password : ";
    passInput(_Pass);
    if (_Pass==pass){
        datlai:
        data="";
        newpass="";
        cout<<"\n\n\t\t\t\t\t\t\t New password : ";
        passInput(newpass);
        cout<<"\n\n\t\t\t\t\t     Retype your new password : ";
        passInput(data);
        if (newpass==data){
           
            TextColor7(10);cout<<"\n\n\t\t\t\t\t\t\tSuccessful change\n\n";TextColor7(7);
            ofstream out;
            out.open("Password/temp.txt",ios::out);
            ifstream in;
            in.open("Password/staff.txt");
            while(in>>_Username>>pass){
                if (username==_Username){
                    out<<_Username<<" "<<newpass<<endl;
                }
                else out<<_Username<<" "<<pass<<endl;
            }
            system("pause");
            in.close();
            out.close();
            remove("Password/staff.txt");
            rename("Password/temp.txt","Password/staff.txt");
        }
        else{
             TextColor7(12);cout<<"\n\n\t\t\t\t\t\tNew password is incorrect,try again?";TextColor7(7);
            cout<<"\n\n\t\t\t\t\t\t\t";TextColor7(14);cout<<"       -Notification-";TextColor7(7);
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
        TextColor7(12);cout<<"\n\n\t\t\t\t\t\t  Incorrect Password";TextColor7(7); 
        cout<<"\n\n\t\t\t\t\t\t\t";TextColor7(14);cout<<"      -Notification-";TextColor7(7);
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

}


