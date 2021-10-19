#include "Nhanvien.h"
#include "Item.h"
#include"Hoadon.h"
#include<iostream>
#include<iomanip>
#include<windows.h>
#define N 100
using namespace std;
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void InLine(int n){
    for (int i = 0; i < n; i++) 
        cout<<"=";
}
void menu(){
    Menu:
    system("cls");TextColor(14);
    cout<<"\n\n\t\t\t\t\t\t\t\t-MENU-";TextColor(7);
    cout<<"\n\t\t\t\t\t\t========================================";
    cout<<"\n\t\t\t\t\t\t||"<<"\t                              ||";
    cout<<"\n\t\t\t\t\t\t||"<<"\t       1.Cashier              ||";
    cout<<"\n\t\t\t\t\t\t||"<<"\t                              ||";
    cout<<"\n\t\t\t\t\t\t||"<<"\t       2.Manager              ||";
	cout<<"\n\t\t\t\t\t\t||"<<"\t                              ||";
	cout<<"\n\t\t\t\t\t\t||"<<"\t       3.Exit                 ||";
	cout<<"\n\t\t\t\t\t\t||"<<"\t                              ||";
	cout<<"\n\t\t\t\t\t\t========================================";
    int a;
    cout<<"\n\n\t\t\t\t\t\tNhap lua chon :";cin>>a;
    while(a<0||a>3){
        cout<<"\n\n\t\t\t\t\t\tNhap lua chon :";cin>>a;   
    }
    switch (a)
    {
        case 1:
        {
            system("cls");
            Hoadon p;
            Cashier(p);
            system("pause");
            goto Menu;
            break;
        }
        case 2:
        {
            Manager:
            system("cls");TextColor(14);
            cout<<"\n\n\t\t\t\t\t\t\t -Manager-";TextColor(7);
            cout<<"\n\t\t\t\t+------------------------------------------------------------+";
            cout<<"\n\t\t\t\t|"<<"\t                                                     |";
            cout<<"\n\t\t\t\t|"<<"\t              1.Quan Ly Nhan Vien                    |";
            cout<<"\n\t\t\t\t|"<<"\t                                                     |";
            cout<<"\n\t\t\t\t|"<<"\t              2.Quan Ly Thuc Don                     |";
	        cout<<"\n\t\t\t\t|"<<"\t                                                     |";
            cout<<"\n\t\t\t\t|"<<"\t              3.Quan Ly Hoa Don                      |";
            cout<<"\n\t\t\t\t|"<<"\t                                                     |";
	        cout<<"\n\t\t\t\t|"<<"\t              4.Doi Pass                             |";
	        cout<<"\n\t\t\t\t|"<<"\t                                                     |";
	        cout<<"\n\t\t\t\t|"<<"\t              5.Quay Lai                             |";
	        cout<<"\n\t\t\t\t|"<<"\t                                                     |";
	        cout<<"\n\t\t\t\t|"<<"\t              6.Exit                                 |";
	        cout<<"\n\t\t\t\t|"<<"\t                                                     |";
	        cout<<"\n\t\t\t\t+------------------------------------------------------------+";
            int b;
            cout<<"\n\n\t\t\t\tNhap lua chon :";cin>>b;
            while(b<0||b>6){
            cout<<"\n\n\t\t\t\t\tNhap lua chon :";cin>>b;
            }
            switch (b)
            {
               case 1:
                {
                    Quanlynhanvien:
                    system("cls");
                    Nhanvien *NV=new Nhanvien[N];TextColor(14);
                    cout<<"\n\n\t\t\t\t\t\t\t   -Quan Ly Nhan Vien-";TextColor(7);
                    cout<<"\n\t\t\t\t\t*********************************************************";
                    cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
                    cout<<"\n\t\t\t\t\t*"<<"\t         1.Show Danh Sanh Nhan Vien             *";
                    cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
                    cout<<"\n\t\t\t\t\t*"<<"\t         2.Them Nhan Vien                       *";
	                cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
	                cout<<"\n\t\t\t\t\t*"<<"\t         3.Xoa Nhan Vien                        *";
	                cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
	                cout<<"\n\t\t\t\t\t*"<<"\t         4.Quay Lai                             *";
	                cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
	                cout<<"\n\t\t\t\t\t*"<<"\t         5.Exit                                 *";
	                cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
	                cout<<"\n\t\t\t\t\t*********************************************************";
                    int c;
                    cout<<"\n\n\t\t\t\t\tNhap lua chon :";cin>>c;getchar();
                    while(c<0||c>5){
                    cout<<"\n\n\t\t\t\t\tNhap lua chon :";cin>>c;getchar();
                    }
                    switch (c)
                    {
                        case 1:
                        {
                            system("cls");
                            display(NV);
                            system("pause");
                            goto Quanlynhanvien;
                            break;
                        }
                        case 2:
                        {
                            system("cls");
                            Add(NV);
                            system("pause");
                            goto Quanlynhanvien;
                            break;
                        }
                        case 3:
                        {
                            system("cls");
                            Delete(NV);
                            system("pause");
                            goto Quanlynhanvien;
                            break;
                        }
                        case 4:
                        goto Manager;
                        break;
                        case 5:
                        system("exit");
                    }
                }
                case 2:
                {
                    QuanlyItem:
                    system("cls");
                    Item *x=new Item[N];TextColor(14);
                    	cout<<"\n\n\t\t\t\t\t\t\t   -Quan Ly Thuc Don-";TextColor(7);
                        cout<<"\n\t\t\t\t\t*********************************************************";
                        cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
                        cout<<"\n\t\t\t\t\t*"<<"\t             1.Show Thuc Don                    *";
                        cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
                        cout<<"\n\t\t\t\t\t*"<<"\t             2.Them Item                        *";
	                    cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
	                    cout<<"\n\t\t\t\t\t*"<<"\t             3.Xoa Item                         *";
	                    cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
	                    cout<<"\n\t\t\t\t\t*"<<"\t             4.Quay Lai                         *";
	                    cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
	                    cout<<"\n\t\t\t\t\t*"<<"\t             5.Exit                             *";
	                    cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
	                    cout<<"\n\t\t\t\t\t*********************************************************";
                    int d;
                    cout<<"\n\n\t\t\t\t\tNhap lua chon :";cin>>d;getchar();
                    while(d<0||d>4){
                    cout<<"\n\n\t\t\t\t\tNhap lua chon :";cin>>d;getchar();
                    }
                    switch (d)
                    {
                        case 1:
                        {
                            system("cls");
                            display(x);
                            system("pause");
                            goto QuanlyItem;
                            break;
                        }
                        case 2:
                        {
                            system("cls");
                            Add(x);
                            system("pause");
                            goto QuanlyItem;
                            break;
                        }
                        case 3:
                        {
                            system("cls");
                            Delete(x);
                            system("pause");
                            goto QuanlyItem;
                            break;
                        }
                        case 4:
                        goto Manager;
                        break;
                        case 5:
                        system("exit");
                    }
                    }
                case 3:
                { 
                    system("cls");
                    cout<<endl;InLine(30);TextColor(11);
                    cout<<"Danh Sach Hoa Don";TextColor(7);
                    InLine(30); cout<<endl;
                    Hoadon a;
                    display(a);
                    system("pause");
                    goto Manager;
                    break;
                }
                case 5:
                    goto Menu;
                    break;
                case 6:
                   system("exit");
            }
        }
        case 3:
        system("exit");
    } 
}


int main(){

    InLine(200);
    menu();
  
    return 0;
}