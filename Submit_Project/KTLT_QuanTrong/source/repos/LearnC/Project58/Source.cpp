/*Ex 6.1. Thao tác với phân số:
a) Tạo struct phân số.
b) Viết hàm nhập vào tử số, mẫu số và trả về phân số.
c) Tiến hành rút gọn phân số.
d) Tính tổng và hiệu 2 phân số, viết hàm trả về kết quả là một phân số.
e) Tính tích, thương hai phân số. Viết hàm trả về kết quả là một phân số.
f) Viết menu cho phép người dùng lựa chọn các chức năng tương ứng để thực hiện chương trình*/

#include<stdio.h>

//dinh nghia kieu DL
struct phanSo {
	int tuSo;
	int mauSo;
};

typedef phanSo PhanSo;

//Nguyen mau ham
PhanSo nhap();
void hienThi(PhanSo p);
int UCLN(int a, int b);
void rutGonPhanSo(PhanSo p);
void tongHaiPhanSo(PhanSo p1, PhanSo p2);
void hieuHaiPhanSo(PhanSo p1, PhanSo p2);

int main() {
	int luachon;
	PhanSo p1, p2, a, b;
	do {
		printf("=====MENU=====\n");
		printf("\n1. Nhap vao 2 phan so: ");
		printf("\n2. Rut gon 2 phan so:");
		printf("\nBan chon???");

		scanf_s("%d", &luachon);
		
		switch (luachon) {
			case 0:
				break;
			case 1: 
				printf("Xin moi nhap vao 2 phan so p1, p2: \n");
				p1 = nhap();
				p2 = nhap();
				hienThi(p1);
				hienThi(p2);
				break;
			case 2: 
				rutGonPhanSo(p1);
				rutGonPhanSo(p2);
				break;
			default:
				printf("\nNhap sai!!! vui long nhap lai.\n");
				break;
		}
	} while (luachon != 0);

	return 0;
}

PhanSo nhap() {
	PhanSo p;
	printf("Nhap tu so: \n");
	scanf_s("%d", &p.tuSo);
	while (1) {
		printf("Nhap mau so khac 0!!! :\n");
		scanf_s("%d", &p.mauSo);
		if (p.mauSo != 0) {
			break;
		}
	}
	return p;
}

void hienThi(PhanSo p) {
	printf("Phan so la: %d/%d\n", p.tuSo, p.mauSo);
}

int UCLN(int a, int b) {
	int r = 0;
	while (a != 0) {
		r = a;
		a = b % a;
		b = r;
	}
	return b;
}

void rutGonPhanSo(PhanSo p) {
	int r = UCLN(p.tuSo, p.mauSo);
	p.tuSo = p.tuSo / r;
	p.mauSo = p.mauSo / r;
	hienThi(p);
}

void tongHaiPhanSo(PhanSo p1, PhanSo p2) {
	PhanSo p;
	p.tuSo = p1.tuSo * p2.mauSo + p1.mauSo * p2.tuSo;
	p.mauSo = p1.mauSo * p2.mauSo;
	rutGonPhanSo(p);
	hienThi(p);
}
void hieuHaiPhanSo(PhanSo p1, PhanSo p2) {
	PhanSo p;
	p.tuSo = p1.tuSo * p2.mauSo - p1.mauSo * p2.tuSo;
	p.mauSo = p1.mauSo * p2.mauSo;
	rutGonPhanSo(p);
	hienThi(p);
}