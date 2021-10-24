#include "Nhanvien.h"
#include "Item.h"
#include"Hoadon.h"
#include "Password.h"
#include "Thongke.h"
#include<iostream>
#include<Windows.h>
#include<iomanip>
#define N 100
using namespace std;
void TextColor(int x){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , x );
}
void InLine(int n){
    for (int i = 0; i < n; i++) 
        cout<<"=";
}
void menuchinh(){
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
}
void menuManager(){
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
	    cout<<"\n\t\t\t\t|"<<"\t              4.Thong Ke                             |";
	    cout<<"\n\t\t\t\t|"<<"\t                                                     |";
	    cout<<"\n\t\t\t\t|"<<"\t              5.Doi Pass                             |";
	    cout<<"\n\t\t\t\t|"<<"\t                                                     |";
        cout<<"\n\t\t\t\t|"<<"\t              6.Quay Lai                             |";       
        cout<<"\n\t\t\t\t|"<<"\t                                                     |";
	    cout<<"\n\t\t\t\t|"<<"\t              7.Exit                                 |";
	    cout<<"\n\t\t\t\t|"<<"\t                                                     |";
	    cout<<"\n\t\t\t\t+------------------------------------------------------------+";
}
void menuQuanlynhanvien(){
        system("cls");TextColor(14);
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
}
void menuQuanlyItem(){
        system("cls");
        TextColor(14);
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
}
void menuThongke(){
        system("cls");
        cout<<"\n\n\t\t\t\t\t\t\t\t    -Thong Ke-";
        cout<<"\n\t\t\t\t\t*******************************************************************";
        cout<<"\n\t\t\t\t\t*"<<"\t                                                          *";
        cout<<"\n\t\t\t\t\t*"<<"\t               1.Thong Ke Theo Ngay                       *";
        cout<<"\n\t\t\t\t\t*"<<"\t                                                          *";
        cout<<"\n\t\t\t\t\t*"<<"\t               2.Thong Ke Theo Thang                      *";
        cout<<"\n\t\t\t\t\t*"<<"\t                                                          *";
	    cout<<"\n\t\t\t\t\t*"<<"\t               3.Thong Ke Theo Nam                        *";
	    cout<<"\n\t\t\t\t\t*"<<"\t                                                          *";
	    cout<<"\n\t\t\t\t\t*"<<"\t               4.Thong Ke Theo Theo Nhan Vien             *";              
	    cout<<"\n\t\t\t\t\t*"<<"\t                                                          *";
	    cout<<"\n\t\t\t\t\t*"<<"\t               5.Quay Lai                                 *";
	    cout<<"\n\t\t\t\t\t*"<<"\t                                                          *";
	    cout<<"\n\t\t\t\t\t*"<<"\t               6.Exit                                     *";
	    cout<<"\n\t\t\t\t\t*"<<"\t                                                          *";
	    cout<<"\n\t\t\t\t\t*******************************************************************";
}
void menu(){
    Menu:
    menuchinh();
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
            system("cls");
            Manager();
            system("pause");
            Manager:
            menuManager();
            int b;
            cout<<"\n\n\t\t\t\tNhap lua chon :";cin>>b;
            while(b<0||b>7){
            cout<<"\n\n\t\t\t\t\tNhap lua chon :";cin>>b;
            }
            switch (b)
            {
               case 1:
                {
                    Quanlynhanvien:
                    Nhanvien *NV=new Nhanvien[N];
                    menuQuanlynhanvien();
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
                        exit(0);
                        break;
                    }
                }
                case 2:
                {
                    QuanlyItem:
                    Item *x=new Item[N];
                    menuQuanlyItem();
                    int d;
                    cout<<"\n\n\t\t\t\t\tNhap lua chon :";cin>>d;getchar();
                    while(d<0||d>5){
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
                        exit(0);
                        break;
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
                case 4:
                    Thongke:
                    menuThongke();
                    int h;
                    cout<<"\n\n\t\t\t\t\tNhap lua chon :";cin>>h;getchar();
                    while(h<0||h>6){
                    cout<<"\n\n\t\t\t\t\tNhap lua chon :";cin>>h;getchar();
                    }
                    switch (h){
                        case 1:
                        {
                            system("cls");
                            statsDay();
                            system("pause");
                            goto Thongke;
                            break;
                        }
                        case 2:
                        {
                            system("cls");
                            statsMonth();
                            system("pause");
                            goto Thongke;
                            break;
                        }
                        case 3:
                        {
                            system("cls");
                            statsYear();
                            system("pause");
                            goto Thongke;
                            break;
                        }
                        case 4:
                        {
                            system("cls");
                            statsNhanvien();
                            system("pause");
                            goto Thongke;
                            break;
                        }
                        case 5:
                        {
                            goto Manager;
                            break;
                        }
                        case 6:
                            exit(0);
                            break;

                    }
                case 5:{
                    system("cls");
                    resetPass();
                    goto Manager;
                    break;
                }
                case 6:
                   goto Menu;
                   break;
                case 7:
                   exit(0);
                   break;
            }
        }
        case 3:
        exit(0);
        break;
    } 
}
int main(){
    menu();
    return 0;
}