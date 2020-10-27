#include"Header.h"
#include<string.h>
#include<iostream>
#include<string>
//khởi tạo hàng hóa
hh* taoHH(char mahh[20], char ten[20], int soluong, float dongia)
{
	hh* kq = new hh;
	//gán giá trị
	strcpy_s(kq->mahh, mahh);
	strcpy_s(kq->ten, ten);
	kq->soluong = soluong;
	kq->donGia = dongia;
	
	kq->next = NULL;
	kq->pre = NULL;
	return kq;
}
//khởi tạo loại hàng hóa
loaiHH* taoLoaiHH(char maloai[20], char tenloai[20])
{
	loaiHH* kq = new loaiHH;
	//gán giá trị
	strcpy_s(kq->maloai, maloai);
	strcpy_s(kq->tenloai, tenloai);
	//-------------------------------
	kq->next = NULL;
	kq->pre = NULL;
	kq->firstItem = NULL;
	kq->lastItem = NULL;
	return kq;
}
//khởi tạo danh sách loại hàng hóa
void khoiTaoDSLoaiHH(dsLoaiHH &ds)
{
	ds.first = NULL;
	ds.last = NULL;
}
//Hàm nhập loại hàng hóa
void nhapLoaiHH(dsLoaiHH &ds)
{
	char maloai[20];

	char tenloai[20];

	char luachon[5];

	
	//Nhập giá trị(mã,tên)
	cout << "\n nhap ma loai:";

	cin.getline(maloai, 20);

	cout << "\n nhap ten loai:";

	cin.getline(tenloai, 20);

	
	//nhập lựa chọn: thêm đầu hoặc cuối
	cout << "\n them dau hay cuoi(dau/cuoi):";
	cin >> luachon;
	cin.ignore();
	
	if (strcmp(luachon,"dau")==0)
	{
		themDauLoaiHH(ds, maloai, tenloai);
	}
	
	else if (strcmp(luachon, "cuoi") == 0)
	{
		//themCuoiLoaiHH(ds, maloai, tenloai);
		cout << "a";
	}
	else
	{
		cout << "lua chon sai!";
	}
}
//xuất loại hàng hóa
void xuatLoaiHH(loaiHH* hh)
{
	cout << "\nma loai hang hoa:" << hh->maloai<<endl;
	cout << "\nten loai hang hoa:" << hh->tenloai<<endl;
}
//xuất danh sách loại hàng hóa
void xuatDanhSachLoaiHH(dsLoaiHH ds)
{
	loaiHH* p = ds.first;
	int i = 1;
	while (p != NULL)
	{
		cout << "\nLoai hh:"<<i<<endl;
		xuatLoaiHH(p);
		p = p->next;
		i++;
	}
}
//Thêm đầu loại hàng hóa
void themDauLoaiHH(dsLoaiHH &ds,char maloai[20],char ten[20])
{
	loaiHH* p;
	p = taoLoaiHH(maloai, ten);
	if (ds.first == NULL)
	{
		ds.first = p;
		ds.last = p;
	}
	else
	{
		p->next = ds.first;
		ds.first->pre = p;
		ds.first = p;
	}
}
//sửa loại hàng hóa theo mã
int suaLoaiHHtheoMa(dsLoaiHH &ds, char maloai[20], char maloaiThayDoi[20])
{
	//nếu danh sách rỗng return -1
	if (ds.first == NULL)
		return -1;
	//Tìm trong danh sách
	loaiHH* pointer = ds.first;
	while (pointer !=NULL)       
	{
		//nếu có tồn tại giá trị cần sửa 
		if (strcmp(pointer->maloai,maloai)==0)
		{
			//sửa
			strcpy_s(pointer->maloai, maloaiThayDoi);
			return 1;
		}
		pointer = pointer->next;
	}
	//không tìm thấy return 0
	return 0;
}
//sửa loại hàng hóa theo tên
int suaLoaiHHtheoTen(dsLoaiHH &ds, char ten[20], char tenThayDoi[20])
{
	//nếu danh sách rỗng return -1
	if (ds.first == NULL)
		return -1;
	//Tìm trong danh sách
	loaiHH* pointer = ds.first;
	while (pointer != NULL)
	{
		if (strcmp(pointer->tenloai,ten)==0)
		{
			strcpy_s(pointer->tenloai, ten);
			return 1;
		}
		pointer = pointer->next;
	}
	//không tìm thấy return 0
	return 0;
}
//hàm sửa giá trị theo tên hoặc mã bằng cách nhập lựa chon và gọi 1 trong 2 hàm trên
int suaGiaTriLoaiHH(dsLoaiHH &ds)
{
	char luaChon[4];

	//biến chứa kết quả sau khi sửa

	int ketqua;

	//lựa chọn
	cout << "\n Sua theo ma/ten:";
	cin >> luaChon;
	cin.ignore();
	if (strcmp(luaChon,"ma")==0)
	{
		char ma[20];
		char maThayDoi[20];
		char ten[20];

		cout << "\n nhap ma muon sua:";
		cin.getline(ma, 20);
		cout << "\n nhap noi dung sua:";
		cin >> maThayDoi;

		ketqua = suaLoaiHHtheoMa(ds, ma, maThayDoi);
		return ketqua;
	}
	else if (strcmp(luaChon, "ten")==0)
	{
		char ten[20];
		char tenThayDoi[20];

		cout << "\n nhap ten muon sua:";
		cin >> ten;
		cout << "\n nhap noi dung sua:";
		cin >> tenThayDoi;

		ketqua = suaLoaiHHtheoTen(ds, ten, tenThayDoi);
		return ketqua;
	}
	
}
//tìm loại hàng hóa theo mã
int timLoaiHHTheoMa(dsLoaiHH ds, loaiHH* &loai, char maloai[20])
{
	if (ds.first == NULL)
	{
		return -1;
	}

	loaiHH* tim = ds.first;

	while (tim != NULL)
	{
		if (strcmp(tim->maloai,maloai)==0)
		{
			xuatLoaiHH(tim);
			return 1;
		}
		tim = tim->next;
	}
	return 0;
}
//tìm loại hàng hóa theo tên

int timLoaiHHTheoTen(dsLoaiHH ds, loaiHH*& loai, char tenloai[20])
{
	if (ds.first == NULL)
	{
		return -1;
	}
	loaiHH* tim = ds.first;
	while (tim != NULL)
	{
		if (strcmp(tim->tenloai,tenloai)==0)
		{
			xuatLoaiHH(tim);
			return 1;
		}
		tim = tim->next;
	}
	return 0;
}

int timLoaiHH(dsLoaiHH ds,loaiHH*& loai)
{
	char luaChon[5];
	int ketqua;
	cout << "\n Tim theo ma/ten:";
	cin >> luaChon;
	cin.ignore();
	if (strcmp(luaChon, "ma") == 0)
	{
		char maCanTim[20];

		cout << "\n nhap ma muon tim:";
		cin >> maCanTim;
		ketqua = timLoaiHHTheoMa(ds, loai, maCanTim);
		return ketqua;
	}
	else if (strcmp(luaChon, "ten")==0)
	{
		char tenCanTim[20];

		cout << "\n nhap ten muon tim:";
		cin.getline(tenCanTim, 20);
		ketqua = timLoaiHHTheoTen(ds, loai, tenCanTim);
		return ketqua;
	}
	else
		cout << "lua chon sai"<<luaChon;
}
int xoaDauHH(dsLoaiHH ds)
{
	if (ds.first == NULL)
	{
		return -1;
	}
	ds.first = ds.first->next;
	ds.first->pre = NULL;
	return 1;

}
int xoaCuoiHH(dsLoaiHH ds)
{
	if (ds.first == NULL)
	{
		return -1; 
	}
	ds.last = ds.last->pre;
	ds.last->pre = NULL;
		return 1;

}
