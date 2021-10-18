#include "Nhanvien.h"
#include "Item.h"
#include"Hoadon.h"
#include<iostream>
#define N 100
using namespace std;
void menu(){
    Menu:
    system("cls");
    cout<<"MENU"<<endl;
    cout<<"1.Cashier"<<endl;
    cout<<"2.Manager"<<endl;
    int a;
    cout<<"Nhap lua chon :";cin>>a;
    if(a>2&&a<0){
         cout<<"Nhap lua chon :";cin>>a;
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
            system("cls");
            cout<<"1.Quan Ly Nhan Vien"<<endl;
            cout<<"2.Quan Ly Thuc Don"<<endl;
            cout<<"3.Quan Ly Hoa Don"<<endl;
            cout<<"4.Doi pass"<<endl;
            cout<<"4.Quay lai"<<endl;
            int b;
            cout<<"Nhap lua chon :";cin>>b;
            if(b>3&&b<0){
            cout<<"Nhap lua chon :";cin>>b;
            }
            switch (b)
            {
               case 1:
                {
                    Quanlynhanvien:
                    system("cls");
                    Nhanvien *NV=new Nhanvien[N];
                    cout<<"1.Show Danh Sanh Nhan Vien"<<endl;
                    cout<<"2.Them Nhan Vien"<<endl;
                    cout<<"3.Xoa Nhan Vien"<<endl;
                    cout<<"4.Quay lai"<<endl;
                    int c;
                    cout<<"Nhap lua chon :";cin>>c;getchar();
                    if(c>3&&c<0){
                    cout<<"Nhap lua chon :";cin>>c;getchar();
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
                    }
                }
                case 2:
                {
                    QuanlyItem:
                    system("cls");
                    Item *x=new Item[N];
                    cout<<"1.Show Danh Sanh Item"<<endl;
                    cout<<"2.Them Item"<<endl;
                    cout<<"3.Xoa Item"<<endl;
                    cout<<"4.Quay lai"<<endl;
                    int c;
                    cout<<"Nhap lua chon :";cin>>c; getchar();
                    if(c>3&&c<0){
                    cout<<"Nhap lua chon :";cin>>c; getchar();
                    }
                    switch (c)
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
                    }
                }
                case 3:
                {
                    system("cls");
                    Hoadon a;
                    display(a);
                    system("pause");
                    goto Manager;
                    break;
                }
                case 4:
                    goto Menu;
                    break;
            }
        }
    } 
}

int main(){
    
  menu();
  
    return 0;
}