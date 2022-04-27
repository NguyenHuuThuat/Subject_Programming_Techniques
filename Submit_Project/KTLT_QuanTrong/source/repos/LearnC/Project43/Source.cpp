/*Bài 3.12. Thực hiện chương trình với các chức năng sau:
a) Nhập vào số nguyên dương n
b) Liệt kê các ước của n
c) Đếm số ước của n
d) Liệt kê các ước nguyên tố của n*/


#include<stdio.h>
#include<math.h>
#include<stdbool.h>


int nhap();
bool kiemTraNT(int n);
void timUoc(int n);
void demUoc(int n);
void kiemTraNguyenTo(int n);


int main() {
	int n;
	n = nhap();
	timUoc(n);
	demUoc(n);
	kiemTraNguyenTo(n);
	return 0;


}

int nhap() {
	int n = 0;
	while (n <= 0) {
		printf("Nhap n > 0!!!");
		scanf_s("%d", &n);
	}
	return n;
}

bool kiemTraNT(int n) {
	int i;
	if (n < 2) {
		return false;
	}
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}




void timUoc(int n) {
	int i;
	printf("\nCac uoc cua n la: ");
	for (i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			printf("%5d", i);
			printf("%5d", n / i);

		}
	}
}

void demUoc(int n) {
	int i;
	int count = 0;
	printf("\nso uoc cua n la: ");
	for (i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			count += 2;
		}
	}
	printf("%d", count);
}

void kiemTraNguyenTo(int n) {
	int i;
	printf("\nuoc nguyen to cua n la: ");
	for (i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (kiemTraNT(i)) {
				printf("%5d", i);
			}
			if (kiemTraNT(n / i)) {
				printf("%5d", n / i);
			}
		}
	}
}