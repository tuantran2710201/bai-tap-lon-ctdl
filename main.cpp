#include "SinhVien.h"
#include "MonHoc.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_set>
#include <limits>
#include <sstream>
#include <fstream>

using namespace std;

void xulymenu(ListSinhVien &l, ListMH &h);

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

void Menu1(ListSinhVien &l, ListMH &h) // menu cho lua chon 1
{
    system("cls"); // menu man hinh
    int n;
    cout << "1. Nhap thong tin sinh vien" << endl;
    cout << "2. In danh sach sinh vien" << endl;
    cout << "3. Luu danh sach sinh vien vao file sinhvien.txt" << endl;
    cout << "4. Nhap thong tin Khoa phong" << endl;
    cout << "5. In danh sach Khoa phong" << endl;
    cout << "6. Luu danh sach Khoa phong vao file monhoc.txt" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(6);
        switch (chon)
        {
        case 1: // Nhap thong tin sinh vien
            cout << "Nhap thong tin sinh vien can nhap: ";
            cin >> n;
            for (int i = 0; i < n; i++)
                // nhap thong tin
                AddHeadSv(l, CreateNodeSinhVien(nhapSinhVien()));
            break;
        case 2: // In danh sach sinh vien
            inDanhSachSv(l);
            break;
        case 3: // Luu danh sach sinh vien vao file quanao.out
            ghiDanhSachSvVaoFile(l);
            break;
        case 4: // Nhap thong tin mon hoc
            cout << "Nhap so luong mon hoc: ";
            cin >> n;
            for (int i = 0; i < n; i++)

                AddHeadMH(h, CreateNodeMH(nhapThongTinMonHoc()));
            break;
        case 5: // In danh sach mon hoc
            PrintListMH(h);
            break;
        case 6: // Luu danh sach mon hoc vao file monhoc.txt
            printlistMHtofile(h);
            break;
        case 0: // thoat
            xulymenu(l, h);
            break;
        }
    }
}

void Menu2(ListSinhVien &l, ListMH &h) // menu cho chuc nang 2
{
    system("cls");
    string maSv;
    string maMH;
    cout << "1. Them sinh vien moi" << endl;
    cout << "2. Sua thong tin sinh vien" << endl;
    cout << "3. Xoa sinh vien" << endl;
    cout << "4. Them moi mon hoc" << endl;
    cout << "5. Sua thong tin mon hoc" << endl;
    cout << "6. Xoa thong tin moc" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(6);
        switch (chon)
        {
        case 1: // them moi sinh vien
            AddHeadSv(l, CreateNodeSinhVien(nhapSinhVien()));
            break;
        case 2: // sua thong tin sinh vien
            cout << "Nhap ma sinh vien can sua: ";
            cin >> maSv; // nhap ma sinh vien can sua
            suaThongTinTheoMaSv(l, maSv);
            break;
        case 3: // xoa thong tin sinh vien
            cout << "Nhap ma sinh vien can xoa: ";
            cin >> maSv; // ma sinh vien can xoa
            XoaMaSv(l, maSv);
            break;
        case 4: // them khoa phong moi
            AddHeadMH(h, CreateNodeMH(nhapThongTinMonHoc()));
            break;
        case 5: // sua thong tin khoa phong
            cout << "Nhap ma Khoa phong can sua: ";
            cin >> maMH; // nhap ma khoa phong co san
            suatheomaMH(h, maMH);
            break;
        case 6: // xoa khoa phong
            cout << "Nhap ma Khoa phong can xoa: ";
            cin >> maMH;
            RemovemaMH(h, maMH);
            break;
        case 0: // thoat menu chinh
            xulymenu(l, h);
            break;
        }
    }
}

void Menu3(ListSinhVien &l, ListMH &h) // menu chuc nang 3
{
    system("cls");
    string maSv;
    string maMH;
    cout << "1. Tim sinh vien theo ma sinh vien vien" << endl;
    cout << "2. Tim mon hoc theo ma mon hoc" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(2);
        switch (chon)
        {
        case 1: // tim ma sinh vien
            cout << "Nhap ma sinh vien can tim: ";
            cin >> maSv;
            timKiemMaSv(l, maSv);
            break;
        case 2: // tim kiem thong tin mon hoc
            cout << "Nhap ma mon hoc can tim: ";
            cin >> maMH;
            findmaMH(h, maMH);
            break;
        case 0: // thoat
            xulymenu(l, h);
            break;
        }
    }
}

void Menu() // menu chinh
{
    cout << "Chuong trinh quan ly sinh vien" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "MENU\n";
    cout << "1. Nhap, In danh sach\n";
    cout << "2. Them, sua, xoa\n";
    cout << "3. Tim kiem doi tuong\n";
    cout << "4. Sap xep doi tuong\n";
    cout << "5. Cac yeu cau tim phan tu lon nhat, nho nhat\n";
    cout << "0. Thoat chuong trinh\n";
}

void Menu4(ListSinhVien &l, ListMH &h) // menu cho chuc nang 4
{
    string maGV;
    cout << "1. Sap xep sinh vien theo diem tang dan" << endl;
    cout << "2. Sap xep danh sach sinh vien theo ten" << endl;
    cout << "3. Sap xep sinh vien theo mon hoc" << endl;
    cout << "4. Sap xep mon hoc  theo maMonHoc" << endl;
    cout << "5. Sap xep tenMonhoc theo tenMonHoc" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(5);
        switch (chon)
        {
        case 1: // sap xep sinh vien theo luong tang dan
            sapXepSinhVienTheoDiem(l);
            inDanhSachSv(l);
            break;
        case 2: // sap xep danh sach sinh vien theo ten
            sapXepSinhVienTheoTen(l);
            inDanhSachSv(l);
            break;
        case 3: // sap xep sinh vien theo khoa
            sapXepSinhVienTheoMaSv(l);
            inDanhSachSv(l);
            break;
        // case 4: //sap xep mon hoc theo ma mon hoc
        //     sapXepSinhVienTheoMaMonHoc(h);
        //     PrintListMH(h);
        //     break;
        // case 5: //sap xep khoa phong theo tenKhoa
        //     sapxepKPTheoTenKhoa(h);
        //     PrintListKP(h);
        //     break;
        case 0: // thoat
            xulymenu(l, h);
            break;
        }
    }
}

void Menu5(ListSinhVien &l, ListMH &h) // tim kiem thong tin
{
    system("cls");
    string maSP;
    cout << "1. Tim sinh vien co diem cao nhat" << endl;
    cout << "2. Tim sinh vien co diem thap nhat" << endl;
    cout << "3. Tim sinh vien it tuoi nhat" << endl;
    cout << "4. Tim sinh vien lon tuoi nhat" << endl;
    cout << "5. Tim sinh vien vao hoc som nhat" << endl;
    cout << "6. Tim sinh vien vao hoc muon nhat" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(6);
        switch (chon)
        {
        case 1: // tim sinh vien co diem cao nhat
            timSvDiemCaoNhat(l);
            break;
        case 2: // tim sinh vien co diem thap nhat
            timSvDiemThapNhat(l);
            break;
        case 3: // tim sinh vien it tuoi nhat
            timSvTreNhat(l);
            break;
        case 4: // tim sinh vien lon tuoi nhat
            timSvLonNhat(l);
            break;
        case 5: // tim sinh vien vao hoc som nhat
            timSVNHSomNhat(l);
            break;
        case 6: // tim sinh vien vao hoc muon nhat
            timSVNHMuonNhat(l);
            break;
        case 0: // thoat
            xulymenu(l, h);
            break;
        }
    }
}

void xulymenu(ListSinhVien &l, ListMH &h) //
{
    //    int n;
    //    string id, name;
    //    float gpa;
    //    string maSP;
    Menu(); // hien thi chuc nang menu
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
    ListSinhVien l;
    ListMH h;
    while (1)
    {
        xulymenu(l, h);
    }
    return 0;
}
