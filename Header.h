#include<iostream>
#include<string.h>
#include<cstdlib>
#include <stdio.h>
#include<string>
using namespace std;
struct hh
{
	char mahh[20];
	char ten[20];
	int soluong;
	float donGia;
	hh* next;
	hh* pre;
};
struct loaiHH
{
	char maloai[20];
	char tenloai[20];
	loaiHH* next;
	loaiHH* pre;
	hh* firstItem;
	hh* lastItem;
};
struct dsLoaiHH
{
	loaiHH* first;
	loaiHH* last;
};
hh* taoHH(char mahh[20], char ten[20], int soluong, float dongia);

loaiHH* taoLoaiHH(char maloai[20], char tenloai[20]);

void khoiTaoDSLoaiHH(dsLoaiHH &ds);

void nhapLoaiHH(dsLoaiHH &ds);

void themDauLoaiHH(dsLoaiHH &ds,char maloai[20], char ten[20]);
//------------------------------------------------------------------
int suaLoaiHHtheoMa(dsLoaiHH &ds, char maloai[20],char maloaiThayDoi[20]);
int suaLoaiHHtheoTen(dsLoaiHH &ds, char ten[20], char tenThayDoi[20]);
int suaGiaTriLoaiHH(dsLoaiHH& ds);
//--------------------------------------------------------------
int timLoaiHHTheoMa(dsLoaiHH ds,loaiHH* &loai, char maloai[20]);
int timLoaiHHTheoTen(dsLoaiHH ds, loaiHH*& loai, char tenloai[20]);
int timLoaiHH(dsLoaiHH ds, loaiHH*& loai);
//------------------------------------
void xuatDanhSachLoaiHH(dsLoaiHH ds);
void xuatLoaiHH(loaiHH* hh);
