#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_set>
#include <limits>
#include <sstream>
#include <fstream>
#include <regex>

using namespace std;



struct GiaoVien {
    string maGV;
    string tenGV;
    string diaChi;
    string ngaySinh;
    string ngayKyHD;
    string khoa;
    string chucVu;
    string gioiTinh;
    string sdt;
    double luong;
    GiaoVien* next;
};

struct NodeGiaoVien {
    GiaoVien info;
    NodeGiaoVien* next;
};

struct ListGiaoVien {
    NodeGiaoVien *Head;
    NodeGiaoVien *Tail;
};

//khoi tao list giao vien
void CreateListGV(ListGiaoVien &l)
{
    l.Head = NULL;
    l.Tail = NULL;
}
//tao node moi
NodeGiaoVien *CreateNodeGiaoVien(GiaoVien data)
{
    NodeGiaoVien *p = new NodeGiaoVien;
    p->info = data;
    p->next = NULL;
    return p;
}

bool isDateFormatValid(const string& input) {
    regex dateFormat("^\\d{2}/\\d{2}/\\d{4}$");

    if (regex_match(input, dateFormat)) {
        return true;
    } else {
        return false;
    }
}

//them node vao danh sach list
void AddHeadGV(ListGiaoVien &l, NodeGiaoVien *p)
{
    if (l.Head == NULL)
    {
        l.Head = p;
        l.Tail = l.Head;
    }
    else
    {
        p->next = l.Head;
        l.Head = p;
    }
}
//xoa node danh sach list
int RemoveHeadGV(ListGiaoVien &l)
{
    NodeGiaoVien *p;
    if (l.Head != NULL)
    {
        p = l.Head;
        ;
        l.Head = l.Head->next;
        delete p;
        if (l.Head == NULL)
            l.Tail = NULL;
        return 1;
    }
    return 0;
}

//ham nhap thong tin giao vien
GiaoVien nhapGiaoVien()
{
    GiaoVien gv;
//    bool validGV = false;
    string strName;
    string ngaysinh;
    cin.ignore();
    cout << "Nhap thong tin giao vien" <<endl;
    
    cout << "Nhap ma giao vien: "<<endl;
    getline(cin, gv.maGV);
    
    cout << "Nhap ten giao vien: "<<endl;
    getline(cin, gv.tenGV);
    
    cout << "Nhap dia chi: "<<endl;
    getline(cin, gv.diaChi);
    
    cout << "Nhap gioi tinh: "<<endl;
    getline(cin, gv.gioiTinh);
    
    cout << "Nhap so dien thoai: "<<endl;
    getline(cin, gv.sdt);
    
    do {
        cout << "Nhap Ngay sinh(Dinh dang: dd/MM/yyyy): ";
        cin >>gv.ngaySinh;
        if (!isDateFormatValid(gv.ngaySinh)) {
            cout << "Ngay sinh khong dung dinh dang. Vui long nhap lai." << endl;
        }
        
    } while (!isDateFormatValid(gv.ngaySinh));
    
        do {
        cout << "Nhap Ngay ky HD(Dinh dang: dd/MM/yyyy): ";
        cin >>gv.ngayKyHD;
        if (!isDateFormatValid(gv.ngayKyHD)) {
            cout << "Ngay Ngay ky HD khong dung dinh dang. Vui long nhap lai." << endl;
        }
        
    } while (!isDateFormatValid(gv.ngayKyHD));

    cin.ignore();
    cout << "Nhap Khoa: "<<endl;
    getline(cin, gv.khoa);
    cout << "Nhap Chuc vu: "<<endl;
    getline(cin, gv.chucVu);
    cout << "Nhap luong: "<<endl;
    
    cin >> gv.luong;
    return gv;
}

//ham sua thong tin giao vien
void suaThongTinTheoMaGV(ListGiaoVien l, string x)
{
    NodeGiaoVien *p = l.Head;
    while (p != NULL)
    {
        if (p->info.maGV == x)
        {
            p->info = nhapGiaoVien();
            return;
        }
        p = p->next;
    }
}

// in thong tin GV
void inThongTinGV(GiaoVien gv)
{
    cout << gv.maGV << "|" << gv.tenGV << "|" << gv.diaChi << "|" << gv.ngaySinh << "|" << gv.ngayKyHD<< "|" << gv.sdt << endl;
}

void inDanhSachGV(ListGiaoVien l)
{
    NodeGiaoVien *p = l.Head;
    while (p != NULL)
    {
        inThongTinGV(p->info);
        p = p->next;
    }
}

//ham lay thong tin GV tu file
void layDanhSachGVTuFile(ListGiaoVien &l)
{
    ifstream ifs;
    ifs.open("giaovien.txt");
    GiaoVien gv;
    while (!ifs.eof())
    {
        ifs >> gv.maGV;
        ifs >> gv.tenGV;
        ifs >> gv.diaChi;
        ifs >> gv.chucVu;
        ifs >> gv.gioiTinh;
        ifs >> gv.luong;
        ifs >> gv.khoa;
        ifs >> gv.ngaySinh;
        ifs >> gv.ngayKyHD;
        ifs >> gv.sdt;
        AddHeadGV(l, CreateNodeGiaoVien(gv));
    }
    RemoveHeadGV(l);
    ifs.close();
}

// ghi thong tin GV ra file
void ghiDanhSachGVVaoFile(ListGiaoVien l)
{
    ofstream ofs;
    ofs.open("giaovien.txt");
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        ofs << p->info.maGV << "|" << p->info.tenGV << "|"
        << p->info.diaChi << "|" << p->info.ngaySinh << "|" << p->info.ngayKyHD
        << "|" << p->info.sdt << endl;
    }
    ofs.close();
}

// xoa thong tin sau khi them node
int xoaGVQ(ListGiaoVien &l, NodeGiaoVien *q)//RemoveKHAfterQ
{
    NodeGiaoVien *p;
    if (q != NULL)
    {
        p = q->next;
        if (p != NULL)
        {
            if (p == l.Tail)
                l.Tail = q;
            q->next = p->next;
            delete p;
        }
        return 1;
    }
    else
        return 0;
}

// xoa node theo ma GV
int XoaMaGV(ListGiaoVien &l, string maGV)
{
    NodeGiaoVien *p, *q = NULL;
    p = l.Head;
    while ((p != NULL) && (p->info.maGV != maGV))
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
        xoaGVQ(l, q);
    else
        RemoveHeadGV(l);
    return 1;
}

//tim kiem theo maGV
void timKiemMaGV(ListGiaoVien l, string maGV)
{
    NodeGiaoVien *p = l.Head;
    while (p != NULL)
    {
        if (p->info.maGV == maGV)
        {
            inThongTinGV(p->info);
            return;
        }
        p = p->next;
    }
}

// sap xep Giao vien theo ten
void sapXepGVTheoTen(ListGiaoVien &l)
{
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeGiaoVien *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.maGV > q->info.maGV)
            {
                GiaoVien tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

//Sap xep giao vien theo luong
void sapXepGiaoVienTheoLuong(ListGiaoVien &l)
{
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeGiaoVien *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.luong > q->info.luong)
            {
                GiaoVien tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

// sap xep Giao vien khoa
void sapXepGVTheoKhoa(ListGiaoVien &l)
{
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeGiaoVien *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.khoa > q->info.khoa)
            {
                GiaoVien tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

// sap xep Giao vien theo ma
void sapXepGVTheoMaGV(ListGiaoVien &l)
{
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeGiaoVien *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.maGV > q->info.maGV)
            {
                GiaoVien tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

//thong ke Giao vien theo dia chi
void thongkeGV(ListGiaoVien l, string diachi)
{
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        if ((p->info.diaChi).find(diachi) != string::npos)
            inThongTinGV(p->info);
    }
}

//thong ke Giao vien
void thongkeGVKyHD(ListGiaoVien l, string namKyHD)
{
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        if ((p->info.ngayKyHD).find(namKyHD) != string::npos)
            inThongTinGV(p->info);
    }
}

//Tim giao vien co luong cao nhat
void timGVLuongCaoNhat(ListGiaoVien l)
{
    NodeGiaoVien *maxLuong = l.Head;
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.luong > maxLuong->info.luong)
            maxLuong = p;
    }
    inThongTinGV(maxLuong->info);
}

//Tim giao vien co luong cao nhat
void timGVLuongThapNhat(ListGiaoVien l)
{
    NodeGiaoVien *minLuong = l.Head;
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.luong < minLuong->info.luong)
            minLuong = p;
    }
    inThongTinGV(minLuong->info);
}

//Tim giao vien ky HD som nhat
void timGVHDSomNhat(ListGiaoVien l)
{
    NodeGiaoVien *minNS = l.Head;
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.ngayKyHD < minNS->info.ngayKyHD)
            minNS = p;
    }
    inThongTinGV(minNS->info);
}


//Tim giao vien co ngay ky HD muon nhat
void timGVHDMuonNhat(ListGiaoVien l)
{
    NodeGiaoVien *minHD = l.Head;
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.ngayKyHD > minHD->info.ngayKyHD)
            minHD = p;
    }
    inThongTinGV(minHD->info);
}

//Tim giao vien tre nhat
void timGVTreNhat(ListGiaoVien l)
{
    NodeGiaoVien *minNS = l.Head;
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.ngaySinh < minNS->info.ngaySinh)
            minNS = p;
    }
    inThongTinGV(minNS->info);
}

//Tim giao vien lon tuoi nhat
void timGVLonNhat(ListGiaoVien l)
{
    NodeGiaoVien *minNS = l.Head;
    for (NodeGiaoVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.ngaySinh > minNS->info.ngaySinh)
            minNS = p;
    }
    inThongTinGV(minNS->info);
}
