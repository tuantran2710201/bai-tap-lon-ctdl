#include "giaovien.h"
#include "khoaphong.h"
#include <string>


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
        int chon = chonmenu(8);
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
        case 3: //Luu danh sach san pham vao file quanao.out
            ghiDanhSachGVVaoFile(l);
            break;
        case 4: //Nhap thong tin khach hang thu cong
            cout << "Nhap so luong Khoa phong: ";
            cin >> n;
            for (int i = 0; i < n; i++)
                
                AddHeadKP(h, CreateNodeKP(nhapThongTinKhoa()));
            break;
        case 5: //In danh sach khach hang
            PrintListKP(h);
            break;
        case 6: //Luu danh sach khach hang vao file khachhang.out
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
        case 1: //them moi san pham
            AddHeadGV(l, CreateNodeGiaoVien(nhapGiaoVien()));
            break;
        case 2: //sua san pham
            cout << "Nhap ma giao vien can sua: ";
            cin >> maGV; //lay ma san pham can sua
            suaThongTinTheoMaGV(l, maGV);
            break;
        case 3: //xoa san pham
            cout << "Nhap ma giao vien can xoa: ";
            cin >> maGV; //ma quan ao can xoa
            XoaMaGV(l, maGV);
            break;
        case 4: //them khach hang moi
            AddHeadKP(h, CreateNodeKP(nhapThongTinKhoa()));
            break;
        case 5: //sua thong tin khach hang
            cout << "Nhap ma Khoa phong can sua: ";
            cin >> maKP; //lay ma khach hang co san
            suatheomaKP(h, maKP);
            break;
        case 6: // xoa khach hang
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
    cout << "1. Tim quan ao theo ma san pham" << endl;
    cout << "2. Tim khach hang theo ma khach hang" << endl;
    cout << "0. Quay lai Menu chinh" << endl;
    while (1)
    {
        int chon = chonmenu(2);
        switch (chon)
        {
        case 1: //tim ma san pham
            cout << "Nhap ma quan ao can tim: ";
            cin >> maGV;
            timKiemMaGV(l, maGV);
            break;
        case 2: //tim kiem thong tin Khach hang
            cout << "Nhap ma khach hang can tim: ";
            cin >> maKP;
            findMaKP(h, maKP);
            break;
        case 0: //thoat 
            xulymenu(l, h);
            break;
        }
    }
}

int main()
{
    ListGiaoVien l;
    ListKP h;
//    CreateListSP(l); //khoi tao list quan ao
//    CreateListKH(h); //khoi tao list khach hang
    while (1)
    {
        xulymenu(l, h);
    }
    return 0;
}
