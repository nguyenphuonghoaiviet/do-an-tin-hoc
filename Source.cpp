#include"Header.h"
hh* taoHH(char mahh[20], char ten[20], int soluong, float dongia)
{
	hh* kq = new hh;
	for (int i = 0; i < strlen(mahh); i++)
	{
		kq->mahh[i] = mahh[i];
		kq->ten[i] = ten[i];	
	}
	
	kq->soluong = soluong;
	kq->donGia = dongia;
	kq->next = NULL;
	kq->pre = NULL;
	return kq;
}

loaiHH* taoLoaiHH(char maloai[20], char tenloai[20])
{
	loaiHH* kq = new loaiHH;
	for (int i = 0; i < strlen(maloai); i++)
	{
		kq->maloai[i] = maloai[i];
		kq->tenloai[i] = tenloai[i];
	}
	kq->next = NULL;
	kq->pre = NULL;
	kq->firstItem = NULL;
	kq->lastItem = NULL;
	return kq;
}
void khoiTaoDSLoaiHH(dsLoaiHH ds)
{
	ds.first = NULL;
	ds.last = NULL;
}
void nhapLoaiHH(dsLoaiHH &ds)
{
	char maloai[20];
	char tenloai[20];
	char luachon[4];
	cout << "\n nhap ma loai:";
	cin >> maloai;
	cout << "\n nhap ten loai:";
	cin >> tenloai;
	cout << "\n them dau hay cuoi(dau/cuoi):";
	cin >> luachon;
	if (luachon == "dau")
	{
		themDauLoaiHH(ds, maloai, tenloai);
	}
	else if (luachon == "cuoi")
	{
		//themCuoiLoaiHH(ds, maloai, tenloai);
	}
	else
	{
		cout << "lua chon sai!";
	}
}
void xuatLoaiHH(loaiHH hh)
{
	cout << "\nma loai hang hoa:" << hh.maloai;
	cout << "\nten loai hang hoa:" << hh.tenloai;
}

void themDauLoaiHH(dsLoaiHH ds,char maloai[20],char ten[20])
{

}