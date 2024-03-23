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

struct SinhVien
{
    string maSv;
    string tenSv;
    string diaChi;
    string ngaySinh;
    string ngayVaoHoc;
    string Mon;
    string gioiTinh;
    string sdt;
    double diem;
    SinhVien *next;
};

struct NodeSinhVien
{
    SinhVien info;
    NodeSinhVien *next;
};

struct ListSinhVien
{
    NodeSinhVien *Head;
    NodeSinhVien *Tail;
};

// khoi tao list sinh vien
void CreateListSv(ListSinhVien &l)
{
    l.Head = NULL;
    l.Tail = NULL;
}
// tao node moi
NodeSinhVien *CreateNodeSinhVien(SinhVien data)
{
    NodeSinhVien *p = new NodeSinhVien;
    p->info = data;
    p->next = NULL;
    return p;
}

bool isDateFormatValid(const string &input)
{
    regex dateFormat("^\\d{2}/\\d{2}/\\d{4}$");

    if (regex_match(input, dateFormat))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// them node vao danh sach list
void AddHeadSv(ListSinhVien &l, NodeSinhVien *p)
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
// xoa node danh sach list
int RemoveHeadSv(ListSinhVien &l)
{
    NodeSinhVien *p;
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

// ham nhap thong tin sinh vien
SinhVien nhapSinhVien()
{
    SinhVien sv;
    string strName;
    string ngaysinh;
    cin.ignore();
    cout << "Nhap thong tin sinh vien" << endl;

    cout << "Nhap ma sinh vien: " << endl;
    getline(cin, sv.maSv);

    cout << "Nhap ten sinh vien: " << endl;
    getline(cin, sv.tenSv);

    cout << "Nhap dia chi: " << endl;
    getline(cin, sv.diaChi);

    cout << "Nhap gioi tinh: " << endl;
    getline(cin, sv.gioiTinh);

    cout << "Nhap so dien thoai: " << endl;
    getline(cin, sv.sdt);

    do
    {
        cout << "Nhap Ngay sinh(Dinh dang: dd/MM/yyyy): ";
        cin >> sv.ngaySinh;
        if (!isDateFormatValid(sv.ngaySinh))
        {
            cout << "Ngay sinh khong dung dinh dang. Vui long nhap lai." << endl;
        }

    } while (!isDateFormatValid(sv.ngaySinh));

    do
    {
        cout << "Nhap Nhap Hoc (Dinh dang: dd/MM/yyyy): ";
        cin >> sv.ngayVaoHoc;
        if (!isDateFormatValid(sv.ngayVaoHoc))
        {
            cout << "Ngay Vao Hoc khong dung dinh dang. Vui long nhap lai." << endl;
        }

    } while (!isDateFormatValid(sv.ngayVaoHoc));

    cin.ignore();
    cout << "Nhap Mon: " << endl;
    getline(cin, sv.Mon);
    cout << "Nhap Diem: " << endl;

    cin >> sv.diem;
    return sv;
}

// ham sua thong tin giao vien
void suaThongTinTheoMaSv(ListSinhVien l, string x)
{
    NodeSinhVien *p = l.Head;
    while (p != NULL)
    {
        if (p->info.maSv == x)
        {
            p->info = nhapSinhVien();
            return;
        }
        p = p->next;
    }
}

// in thong tin Sv
void inThongTinSv(SinhVien sv)
{
    cout << sv.maSv << "|" << sv.tenSv << "|" << sv.diaChi << "|" << sv.ngaySinh << "|" << sv.ngayVaoHoc << "|" << sv.sdt << endl;
}

void inDanhSachSv(ListSinhVien l)
{
    NodeSinhVien *p = l.Head;
    while (p != NULL)
    {
        inThongTinSv(p->info);
        p = p->next;
    }
}

// ham lay thong tin Sv tu file
void layDanhSachSvTuFile(ListSinhVien &l)
{
    ifstream ifs;
    ifs.open("sinhvien.txt");
    SinhVien sv;
    while (!ifs.eof())
    {
        ifs >> sv.maSv;
        ifs >> sv.tenSv;
        ifs >> sv.diaChi;
        ifs >> sv.gioiTinh;
        ifs >> sv.diem;
        ifs >> sv.ngaySinh;
        ifs >> sv.ngayVaoHoc;
        ifs >> sv.sdt;
        AddHeadSv(l, CreateNodeSinhVien(sv));
    }
    RemoveHeadSv(l);
    ifs.close();
}

// ghi thong tin Sv ra file
void ghiDanhSachSvVaoFile(ListSinhVien l)
{
    ofstream ofs;
    ofs.open("sinhvien.txt");
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        ofs << p->info.maSv << "|" << p->info.tenSv << "|"
            << p->info.diaChi << "|" << p->info.ngaySinh << "|" << p->info.ngayVaoHoc
            << "|" << p->info.sdt << endl;
    }
    ofs.close();
}

// xoa thong tin sau khi them node
int xoaSvQ(ListSinhVien &l, NodeSinhVien *q) // RemoveKHAfterQ
{
    NodeSinhVien *p;
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

// xoa node theo ma Sv
int XoaMaSv(ListSinhVien &l, string maSv)
{
    NodeSinhVien *p, *q = NULL;
    p = l.Head;
    while ((p != NULL) && (p->info.maSv != maSv))
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
        xoaSvQ(l, q);
    else
        RemoveHeadSv(l);
    return 1;
}

// tim kiem theo maSv
void timKiemMaSv(ListSinhVien l, string maSv)
{
    NodeSinhVien *p = l.Head;
    while (p != NULL)
    {
        if (p->info.maSv == maSv)
        {
            inThongTinSv(p->info);
            return;
        }
        p = p->next;
    }
}

// sap xep sinh vien theo ten
void sapXepSinhVienTheoTen(ListSinhVien &l)
{
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeSinhVien *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.maSv > q->info.maSv)
            {
                SinhVien tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

// Sap xep sinh vien theo diem
void sapXepSinhVienTheoDiem(ListSinhVien &l)
{
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeSinhVien *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.diem > q->info.diem)
            {
                SinhVien tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

// sap xep sinh vien theo mon
void sapXepSinhVienTheoMon(ListSinhVien &l)
{
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeSinhVien *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.Mon > q->info.Mon)
            {
                SinhVien tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

// sap xep sinh vien theo ma sinh vien
void sapXepSinhVienTheoMaSv(ListSinhVien &l)
{
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeSinhVien *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.maSv > q->info.maSv)
            {
                SinhVien tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

// //thong ke Giao vien theo dia chi
// void thongkeGV(ListSinhVien l, string diachi)
// {
//     for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
//     {
//         if ((p->info.diaChi).find(diachi) != string::npos)
//             inThongTinGV(p->info);
//     }
// }

// //thong ke Giao vien
// void thongkeGVKyHD(ListSinhVien l, string namKyHD)
// {
//     for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
//     {
//         if ((p->info.ngayKyHD).find(namKyHD) != string::npos)
//             inThongTinGV(p->info);
//     }
// }

// Tim sinh vien co diem cao nhat
void timSvDiemCaoNhat(ListSinhVien l)
{
    NodeSinhVien *maxDiem = l.Head;
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.diem > maxDiem->info.diem)
            maxDiem = p;
    }
    inThongTinSv(maxDiem->info);
}

// Tim sinh vien co diem thap nhat
void timSvDiemThapNhat(ListSinhVien l)
{
    NodeSinhVien *minDiem = l.Head;
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.diem < minDiem->info.diem)
            minDiem = p;
    }
    inThongTinSv(minDiem->info);
}

// Tim sinh vien co ngay nhap hoc som nhat
void timSVNHSomNhat(ListSinhVien l)
{
    NodeSinhVien *minNS = l.Head;
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.ngayVaoHoc < minNS->info.ngayVaoHoc)
            minNS = p;
    }
    inThongTinSv(minNS->info);
}

// Tim sinh vien co ngay vao hoc muon nhat
void timSVNHMuonNhat(ListSinhVien l)
{
    NodeSinhVien *minHD = l.Head;
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.ngayVaoHoc > minHD->info.ngayVaoHoc)
            minHD = p;
    }
    inThongTinSv(minHD->info);
}

// Tim sinh vien  tre nhat
void timSvTreNhat(ListSinhVien l)
{
    NodeSinhVien *minNS = l.Head;
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.ngaySinh < minNS->info.ngaySinh)
            minNS = p;
    }
    inThongTinSv(minNS->info);
}

// Tim sinh vien lon tuoi nhat
void timSvLonNhat(ListSinhVien l)
{
    NodeSinhVien *minNS = l.Head;
    for (NodeSinhVien *p = l.Head; p != NULL; p = p->next)
    {
        if (p->info.ngaySinh > minNS->info.ngaySinh)
            minNS = p;
    }
    inThongTinSv(minNS->info);
}
