#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct MonHoc {
    string maMonHoc;
    string tenMonHoc;
    MonHoc* next;
};

struct NodeMH
{
    MonHoc info;
    NodeMH *next;
};

struct ListMH
{
    NodeMH *Head;
    NodeMH *Tail;
};
//khoi toa list mon hoc
void CreateListMH(ListMH &l)
{
    l.Head = NULL;
    l.Tail = NULL;
}
//tao mon hoc moi
NodeMH *CreateNodeMH(MonHoc data)
{
    NodeMH *p = new NodeMH; //tao node moi
    p->info = data;
    p->next = NULL;
    return p;
}
//them node vao list
void AddHeadMH(ListMH &l, NodeMH *p)
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
int RemoveHeadMH(ListMH &l)
{
    NodeMH *p;
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
//nhap thong tin mon hoc
MonHoc nhapThongTinMonHoc()
{
    MonHoc mh;
    cout << "Nhap thong tin mon hoc" << endl;
    cout << "Nhap ma mon hoc: "<< endl;
    cin >> mh.maMonHoc;
    cout << "Nhap ten mon hoc: "<< endl;
    cin >> mh.tenMonHoc;

    return mh;
}
//ham sua mon hoc
void suatheomaMH(ListMH l, string maMonHoc)
{
    NodeMH *p = l.Head;
    while (p != NULL)
    {
        if (p->info.maMonHoc == maMonHoc)
        {
            p->info = nhapThongTinMonHoc();
            return;
        }
        p = p->next;
    }
}
//lay danh sach
void getlistMHfromfile(ListMH &l)
{
    ifstream ifs;
    ifs.open("monhoc.txt");
    MonHoc mh;
    while (!ifs.eof()) //
    {
        ifs >> mh.maMonHoc;
        ifs >> mh.tenMonHoc;
        AddHeadMH(l, CreateNodeMH(mh));
    }
    RemoveHeadMH(l);
    ifs.close();
}
//in danh sach ra file output
void printlistMHtofile(ListMH l)
{
    ofstream ofs;
    ofs.open("monhoc.txt");
    for (NodeMH *p = l.Head; p != NULL; p = p->next)
    {
        ofs << p->info.maMonHoc << "|" << p->info.tenMonHoc << endl;
    }
    ofs.close();
}
//in thong tin ma mon hoc
void inThongTinMonHoc(MonHoc mh)
{
    cout << mh.maMonHoc << "|" << mh.tenMonHoc << endl;
}
//in danh sach
void PrintListMH(ListMH l)
{
    NodeMH *p = l.Head;
    while (p != NULL)
    {
        inThongTinMonHoc(p->info);
        p = p->next;
    }
}
//xoa
int RemoveMHAfterQ(ListMH &l, NodeMH *q)
{
    NodeMH *p;
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

int RemovemaMH(ListMH &l, string maMonHoc)
{
    NodeMH *p, *q = NULL;
    p = l.Head;
    while ((p != NULL) && (p->info.maMonHoc != maMonHoc))
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
        RemoveMHAfterQ(l, q);
    else
        RemoveHeadMH(l);
    return 1;
}

void findmaMH(ListMH l, string maMonHoc)
{
    NodeMH *p = l.Head;
    while (p != NULL)
    {
        if (p->info.maMonHoc == maMonHoc)
        {
            inThongTinMonHoc(p->info);
            return;
        }
        p = p->next;
    }
}

//sap xep theo maMonHoc
void sapxepMHTheomaMonHoc(ListMH &l)
{
    for (NodeMH *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeMH *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.maMonHoc < q->info.maMonHoc)
            {
                MonHoc tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

//sap xep theo ten mon hoc
void sapxepMHTheotenMonHoc(ListMH &l)
{
    for (NodeMH *p = l.Head; p != NULL; p = p->next)
    {
        for (NodeMH *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.tenMonHoc < q->info.tenMonHoc)
            {
                MonHoc tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}
