#include<iostream>
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

void khoiTaoDSLoaiHH(dsLoaiHH ds);

void nhapLoaiHH(dsLoaiHH &ds);

void themDauLoaiHH(dsLoaiHH ds,char maloai[20], char ten[20]);

