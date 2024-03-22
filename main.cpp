#include "GiaoVien.h"
#include "KhoaPhong.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_set>
#include <limits>
#include <sstream>
#include <fstream>


using namespace std;

void xulymenu(ListGiaoVien &l, ListKP &h);

int chonmenu(int yc) // ham chon menu
{
    int n = 0;
    cout << "Moi chon: ";
    cin >> n;
    if (n >= 0 && n <= yc)
        return n; //
    else
        return chonmenu(yc);
}

void Menu1(ListGiaoVien &l, ListKP &h) //menu cho lua chon 1
{
    system("cls"); // menu man hinh
    int n;
    cout << "1. Nhap thong tin giao vien" << endl;
    cout << "2. In danh sach giao vien" << endl;
    cout << "3. Luu danh sach giao vien vao file giaovien.txt" << endl;
    cout << "4. Nhap thong tin Khoa phong" << endl;
    cout << "5. In danh sach Khoa phong" << endl;
    cout << "6. Luu danh sach Khoa phong vao file khoaphong.txt" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(6);
        switch (chon)
        {
        case 1: //Nhap thong tin giao vien
            cout << "Nhap so luong giao vien can nhap: ";
            cin >> n;
            for (int i = 0; i < n; i++)
                //nhap thong tin
                AddHeadGV(l, CreateNodeGiaoVien(nhapGiaoVien()));
            break;
        case 2: //In danh sach giao vien
            inDanhSachGV(l);
            break;
        case 3: //Luu danh sach giao vien vao file quanao.out
            ghiDanhSachGVVaoFile(l);
            break;
        case 4: //Nhap thong tin khoa phong
            cout << "Nhap so luong Khoa phong: ";
            cin >> n;
            for (int i = 0; i < n; i++)
                
                AddHeadKP(h, CreateNodeKP(nhapThongTinKhoa()));
            break;
        case 5: //In danh sach khoa phong
            PrintListKP(h);
            break;
        case 6: //Luu danh sach khoa phong vao file khoaphong.txt
            printlistKPtofile(h);
            break;
        case 0: //thoat
            xulymenu(l, h);
            break;
        }
    }
}

void Menu2(ListGiaoVien &l, ListKP &h) //menu cho chuc nang 2
{
    system("cls");
    string maGV;
    string maKP;
    cout << "1. Them Giao vien moi" << endl;
    cout << "2. Sua thong tin Giao vien" << endl;
    cout << "3. Xoa Giao vien" << endl;
    cout << "4. Them moi Khoa phong" << endl;
    cout << "5. Sua thong tin khoa phong" << endl;
    cout << "6. Xoa thong tin khoa phong" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(6);
        switch (chon)
        {
        case 1: //them moi giao vien
            AddHeadGV(l, CreateNodeGiaoVien(nhapGiaoVien()));
            break;
        case 2: //sua thong tin giao vien
            cout << "Nhap ma giao vien can sua: ";
            cin >> maGV; //nhap ma giao vien can sua
            suaThongTinTheoMaGV(l, maGV);
            break;
        case 3: //xoa thong tin giao vien
            cout << "Nhap ma giao vien can xoa: ";
            cin >> maGV; //ma giao vien can xoa
            XoaMaGV(l, maGV);
            break;
        case 4: //them khoa phong moi
            AddHeadKP(h, CreateNodeKP(nhapThongTinKhoa()));
            break;
        case 5: //sua thong tin khoa phong
            cout << "Nhap ma Khoa phong can sua: ";
            cin >> maKP; //nhap ma khoa phong co san
            suatheomaKP(h, maKP);
            break;
        case 6: // xoa khoa phong
            cout << "Nhap ma Khoa phong can xoa: ";
            cin >> maKP;
            RemovemaKP(h, maKP);
            break;
        case 0: //thoat menu chinh
            xulymenu(l, h);
            break;
        }
    }
}


void Menu3(ListGiaoVien &l, ListKP &h) //menu chuc nang 3
{
    system("cls");
    string maGV;
    string maKP;
    cout << "1. Tim Giao vien theo ma giao vien" << endl;
    cout << "2. Tim khoa phong theo ma khoa phong" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(2);
        switch (chon)
        {
        case 1: //tim ma san pham
            cout << "Nhap ma giao vien can tim: ";
            cin >> maGV;
            timKiemMaGV(l, maGV);
            break;
        case 2: //tim kiem thong tin Khach hang
            cout << "Nhap ma khoa phong can tim: ";
            cin >> maKP;
            findMaKP(h, maKP);
            break;
        case 0: //thoat
            xulymenu(l, h);
            break;
        }
    }
}

void Menu() //menu chinh
{
//    system("cls");
    cout << "Chuong trinh quan ly giao vien" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "MENU\n";
    cout << "1. Nhap, In danh sach\n";
    cout << "2. Them, sua, xoa\n";
    cout << "3. Tim kiem doi tuong\n";
    cout << "4. Sap xep doi tuong\n";
    cout << "5. Cac yeu cau tim phan tu lon nhat, nho nhat\n";
//    cout << "6. Cac yeu cau tinh tong, trung binh, dem\n";
//    cout << "7. Cac yeu cau thong ke theo dieu kien\n";
    cout << "0. Thoat chuong trinh\n";
}

void Menu4(ListGiaoVien &l, ListKP &h) //menu cho chuc nang 4
{
//    system("cls");
    string maGV;
    cout << "1. Sap xep giao vien theo luong tang dan" << endl;
    cout << "2. Sap xep danh sach giao vien theo ten" << endl;
    cout << "3. Sap xep giao vien theo khoa" << endl;
    cout << "4. Sap xep khoa phong theo maKhoa" << endl;
    cout << "5. Sap xep khoa phong theo tenKhoa" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(5);
        switch (chon)
        {
        case 1: //sap xep giao vien theo luong tang dan
            sapXepGiaoVienTheoLuong(l);
            inDanhSachGV(l);
            break;
        case 2: //sap xep danh sach giao vien theo ten
            sapXepGVTheoTen(l);
            inDanhSachGV(l);
            break;
        case 3: //sap xep giao vien theo khoa
            sapXepGVTheoKhoa(l);
            inDanhSachGV(l);
            break;
        case 4: //sap xep khoa phong theo maKhoa
            sapxepKPTheoMaKhoa(h);
            PrintListKP(h);
            break;
        case 5: //sap xep khoa phong theo tenKhoa
            sapxepKPTheoTenKhoa(h);
            PrintListKP(h);
            break;
        case 0: //thoat
            xulymenu(l, h);
            break;
        }
    }
}

void Menu5(ListGiaoVien &l, ListKP &h) //tim kiem thong tin
{
    system("cls");
    string maSP;
    cout << "1. Tim giao vien co luong cao nhat" << endl;
    cout << "2. Tim giao vien co luong thap nhat" << endl;
    cout << "3. Tim giao vien it tuoi nhat" << endl;
    cout << "4. Tim giao vien lon tuoi nhat" << endl;
    cout << "5. Tim giao vien ky hop dong som nhat" << endl;
    cout << "6. Tim giao vien ky hop dong muon nhat" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(6);
        switch (chon)
        {
        case 1: //tim giao vien co luong cao nhat
            timGVLuongCaoNhat(l);
            break;
        case 2: //tim giao vien co luong
            timGVLuongThapNhat(l);
            break;
        case 3: //tim giao vien it tuoi nhat
            timGVTreNhat(l);
            break;
        case 4: //tim giao vien lon tuoi nhat
            timGVLonNhat(l);
            break;
        case 5: //tim giao ky HD som nhat
            timGVHDSomNhat(l);
            break;
        case 6: //tim giao vien ky HD muon nhat
            timGVHDMuonNhat(l);
            break;
        case 0: //thoat
            xulymenu(l, h);
            break;
        }
    }
}

void xulymenu(ListGiaoVien &l, ListKP &h) //
{
//    int n;
//    string id, name;
//    float gpa;
//    string maSP;
    Menu(); //hien thi chuc nang menu
    int chon = chonmenu(7);
    switch (chon)
    {
    case 1:
        Menu1(l, h);
        break;
    case 2:
        Menu2(l, h);
        break;
    case 3:
        Menu3(l, h);
        break;
    case 4:
        Menu4(l, h);
        break;
    case 5:
        Menu5(l, h);
        break;
//    case 6:
//        Menu6(l, h);
//        break;
//    case 7:
//        Menu7(l, h);
//        break;
    case 0:
        exit(1);
        break;
    }
}

int main()
{
    ListGiaoVien l;
    ListKP h;
    while (1)
    {
        xulymenu(l, h);
    }
    return 0;
}
