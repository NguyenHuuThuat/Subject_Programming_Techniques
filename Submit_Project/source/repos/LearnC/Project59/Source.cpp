/*Ex 6.2. Số phức:
a) Tạo struct số phức với phần thực và phần ảo.
b) Viết hàm nhập vào thông số của số phức và trả về một số phức.
c) Viết hàm tính tổng, hiệu, tích, thương của 2 số phức và trả về kết quả là số phức.
d) Tạo menu cho phép người dùng lựa chọn các chức năng. Trong đó nhấn ESC sẽ kết
thúc chương trình.*/

#include<stdio.h>

struct soPhuc {
	int soThuc;
	int soAo;
};

typedef struct soPhuc SoPhuc;

//Khai bao nguyen mau ham
SoPhuc nhap();
void hienThi(SoPhuc z);
SoPhuc tongHaiSoPhuc(SoPhuc z1, SoPhuc z2);
SoPhuc hieuHaiSoPhuc(SoPhuc z1, SoPhuc z2);
SoPhuc tichHaiSoPhuc(SoPhuc z1, SoPhuc z2);

int main() {
	int luachon;
	SoPhuc z1, z2;
	z1.soAo = 0;
	z1.soThuc = 0;
	z2.soAo = 0;
	z2.soThuc = 0;
	do {
		printf("======MENU======\n");
		printf("\n1. Nhap 2 so phuc.");
		printf("\n2. Tinh tong 2 so phuc vua nhap");
		printf("\n3. Tinh hieu 2 so phuc vua nhap");
		printf("\n4. Tinh tich 2 so phuc vua nhap");
		printf("\n0. Thoat!!!");
		printf("\n\tBan chon  ???");

		scanf_s("%d", &luachon);


		switch (luachon) {
		case 0:
			break;
		case 27:
			luachon = 0;
			break;
		case 1:
			printf("Nhap 2 so phuc: \n");
			printf("So phuc thu nhat: \n");
			z1 = nhap();
			printf("So phuc thu hai: \n");
			z2 = nhap();
			printf("Hai so phuc vua nhap la: \n");
			hienThi(z1);
			hienThi(z2);
			break;

		case 2:
			printf("Tong hai so phuc la: \n");
			hienThi(tongHaiSoPhuc(z1, z2));
			break;

		case 3:
			printf("Hieu hai so phuc la: \n");
			hienThi(hieuHaiSoPhuc(z1, z2));
			break;

		case 4:
			printf("Tich hai so phuc la: \n");
			hienThi(tichHaiSoPhuc(z1, z2));
			break;

		default:
			printf("\nNhap sai. Vui long nhap lai!!!");
			break;
		}
	} while (luachon != 0);
	return 0;
}

SoPhuc nhap() {
	SoPhuc z;
	printf("Nhap phan thuc cua so phuc: \n");
	scanf_s("%d", &z.soThuc);
	printf("Nhap phan ao cua so phuc: \n");
	scanf_s("%d", &z.soAo);
	return z;
}

void hienThi(SoPhuc z) {
	printf("So phuc co phan thuc la: %d va phan ao la %d la: \n", z.soThuc, z.soAo);
	printf("z = %d + %di ", z.soThuc, z.soAo);
}

SoPhuc tongHaiSoPhuc(SoPhuc z1, SoPhuc z2) {
	SoPhuc z;
	z.soThuc = z1.soThuc + z2.soThuc;
	z.soAo = z1.soAo + z2.soAo;
	return z;
}

SoPhuc hieuHaiSoPhuc(SoPhuc z1, SoPhuc z2) {
	SoPhuc z;
	z.soThuc = z1.soThuc - z2.soThuc;
	z.soAo = z1.soAo - z2.soAo;
	return z;
}

SoPhuc tichHaiSoPhuc(SoPhuc z1, SoPhuc z2) {
	SoPhuc z;
	z.soThuc = z1.soThuc * z2.soThuc - z1.soAo * z2.soAo;
	z.soAo = z1.soThuc * z2.soAo + z2.soThuc * z1.soAo;
	return z;
}




