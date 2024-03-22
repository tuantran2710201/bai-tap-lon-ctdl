#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct KhoaPhong {
    string maKhoa;
    string tenKhoa;
    KhoaPhong* next;
};

struct NodeKP
{
    KhoaPhong info;
    NodeKP *next;
};

struct ListKP
{
    NodeKP *Head;
    NodeKP *Tail;
};
//khoi toa list san pham
void CreateListKP(ListKP &l)
{
    l.Head = NULL;
    l.Tail = NULL;
}
//tao node moi san pham
NodeKP *CreateNodeKP(KhoaPhong data)
{
    NodeKP *p = new NodeKP; //tao node moi
    p->info = data;
    p->next = NULL;
    return p;
}
//them node vao list
void AddHeadKP(ListKP &l, NodeKP *p)
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
//xoa node khoi list
int RemoveHeadKP(ListKP &l)
{
    NodeKP *p;
    if (l.Head != NULL)
    {
        p = l.Head;
        l.Head = l.Head->next;
        delete p;
        if (l.Head == NULL)
            l.Tail = NULL;
        return 1;
    }
    return 0;
}
//nhap thong tin san pham
KhoaPhong nhapThongTinKhoa()
{
    KhoaPhong kp;
    cout << "Nhap thong tin Khoa phong" << endl;
    cout << "Nhap ma khoa: "<< endl;
    cin >> kp.maKhoa;
    cout << "Nhap ten khoa: "<< endl;
    cin >> kp.tenKhoa;

    return kp;
}
//ham sua san pham
void suatheomaKP(ListKP l, string maKhoa)
{
    NodeKP *p = l.Head;
    while (p != NULL)
    {
        if (p->info.maKhoa == maKhoa)
        {
            p->info = nhapThongTinKhoa();
            return;
        }
        p = p->next;
    }
}
//lay danh sach
void getlistKPfromfile(ListKP &l)
{
    ifstream ifs;
    ifs.open("khoaphong.txt");
    KhoaPhong kp;
    while (!ifs.eof()) //
    {
        ifs >> kp.maKhoa;
        ifs >> kp.tenKhoa;
        AddHeadKP(l, CreateNodeKP(kp));
    }
    RemoveHeadKP(l);
    ifs.close();
}
//in danh sach ra file output
void printlistKPtofile(ListKP l)
{
    ofstream ofs;
    ofs.open("khoaphong.txt");
    for (NodeKP *p = l.Head; p != NULL; p = p->next)
    {
        ofs << p->info.maKhoa << "|" << p->info.tenKhoa << endl;
    }
    ofs.close();
}
//in thong tin quan ao
void inThongTinKhoaPhong(KhoaPhong kp)
{
    cout << kp.maKhoa << "|" << kp.tenKhoa << endl;
}
//in danh sach
void PrintListKP(ListKP l)
{
    NodeKP *p = l.Head;
    while (p != NULL)
    {
        inThongTinKhoaPhong(p->info);
        p = p->next;
    }
}
//xoa
int RemoveKPAfterQ(ListKP &l, NodeKP *q)
{
    NodeKP *p;
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

int RemovemaKP(ListKP &l, string maKhoa)
{
    NodeKP *p, *q = NULL;
    p = l.Head;
    while ((p != NULL) && (p->info.maKhoa != maKhoa))
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
        RemoveKPAfterQ(l, q);
    else
        RemoveHeadKP(l);
    return 1;
}

void findMaKP(ListKP l, string maKhoa)
{
    NodeKP *p = l.Head;
    while (p != NULL)
    {
        if (p->info.maKhoa == maKhoa)
        {
            inThongTinKhoaPhong(p->info);
            return;
        }
        p = p->next;
    }
}

//sap xep theo maKhoa
void sapxepKPTheoMaKhoa(ListKP &l)
{
    for (NodeKP *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeKP *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.maKhoa < q->info.maKhoa)
            {
                KhoaPhong tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

//sap xep theo maKhoa
void sapxepKPTheoTenKhoa(ListKP &l)
{
    for (NodeKP *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeKP *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.tenKhoa < q->info.tenKhoa)
            {
                KhoaPhong tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}
