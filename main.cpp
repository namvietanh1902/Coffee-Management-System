#include "Nhanvien.h"
#include "Item.h"
#include"Hoadon.h"
#include "PasswordQL.h"
#include "PasswordNV.h"
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
    cout<<"\n\t\t\t\t\t\t||"<<"\t       1.Staff                ||";
    cout<<"\n\t\t\t\t\t\t||"<<"\t                              ||";
    cout<<"\n\t\t\t\t\t\t||"<<"\t       2.Manager              ||";
	cout<<"\n\t\t\t\t\t\t||"<<"\t                              ||";
	cout<<"\n\t\t\t\t\t\t||"<<"\t       3.Exit                 ||";
	cout<<"\n\t\t\t\t\t\t||"<<"\t                              ||";
	cout<<"\n\t\t\t\t\t\t========================================";
}
void menuStaff(){
    system("cls");TextColor(14);
	        cout<<"\n\n\t\t\t\t\t\t     -STAFF-";TextColor(7);
	        cout<<"\n\t\t\t+---------------------------------------------------------------+";
	        cout<<"\n\t\t\t|"<<"                                                     \t\t|";
	        cout<<"\n\t\t\t|"<<"                1.Hien Thi Danh Sach Nhan Vien       \t\t|";
	        cout<<"\n\t\t\t|"<<"                                                     \t\t|";
            cout<<"\n\t\t\t|"<<"                2.Hien Thi Danh Sach Item            \t\t|";
	        cout<<"\n\t\t\t|"<<"                                                     \t\t|";
	        cout<<"\n\t\t\t|"<<"                3.Them Hoa Don                       \t\t|";
		    cout<<"\n\t\t\t|"<<"                                                     \t\t|";
		    cout<<"\n\t\t\t|"<<"                4.Doi Pass                           \t\t|";
		    cout<<"\n\t\t\t|"<<"                                                     \t\t|";
	        cout<<"\n\t\t\t|"<<"                5.Quay Lai                           \t\t|";       
	        cout<<"\n\t\t\t|"<<"                                                     \t\t|";
		    cout<<"\n\t\t\t|"<<"                6.Exit                               \t\t|";
		    cout<<"\n\t\t\t|"<<"                                                     \t\t|";
		    cout<<"\n\t\t\t+---------------------------------------------------------------+";
}
void menuManager(){
        system("cls");TextColor(14);
        cout<<"\n\n\t\t\t\t\t\t\t -MANAGER-";TextColor(7);
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
        cout<<"\n\n\t\t\t\t\t\t\t   -QUAN LY NHAN VIEN-";TextColor(7);
        cout<<"\n\t\t\t\t\t*********************************************************";
        cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
        cout<<"\n\t\t\t\t\t*"<<"\t         1.Hien Thi Danh Sanh Nhan Vien         *";
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
        cout<<"\n\n\t\t\t\t\t\t\t   -QUAN LY THUC DON-";TextColor(7);
        cout<<"\n\t\t\t\t\t*********************************************************";
        cout<<"\n\t\t\t\t\t*"<<"\t                                                *";
        cout<<"\n\t\t\t\t\t*"<<"\t             1.Hien Thi Thuc Don                *";
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
        system("cls");TextColor(14);
        cout<<"\n\n\t\t\t\t\t\t\t\t    -THONG KE-";TextColor(7);
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
            string maNV=Staff();
            system("pause");
            Staff:
            menuStaff();
            int k;
            cout<<"\n\n\t\t\tNhap lua chon :";cin>>k;
            while(k<0||k>6){
            cout<<"\n\n\t\t\tNhap lua chon :";cin>>k;
            }
            switch (k){
                case 1:
                {
                    Nhanvien *nv=new Nhanvien[N];
                    system("cls");
                    display(nv);
                    system("pause");
                    delete [] nv;
                    goto Staff;
                    break;
                }
                case 2:
                {
                    Item *x=new Item[N];
                    system("cls");
                    display(x);
                    system("pause");
                    delete [] x;
                    goto Staff;
                    break;
                }
                case 3:
                {
                    system("cls");
                    Hoadon p;
                    Cashier(p,maNV);
                    system("pause");
                    goto Staff;
                    break;
                }
                case 4:
                {
                    system("cls");
                    resetPassNV(maNV);
                    goto Staff;
                    break;
                }
                case 5:
                    goto Menu;
                    break;
                case 6:
                    exit(0);
                    break;
            }  
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
            cout<<"\n\n\t\t\t\tNhap lua chon :";cin>>b;
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
                    delete [] NV;
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
                    delete [] x;
                    }
                case 3:
                { 
                    system("cls");
                    cout<<endl;InLine(21);TextColor(11);
                    cout<<"Danh Sach Hoa Don";TextColor(7);
                    InLine(21); cout<<endl;
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
                case 5:
                {
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