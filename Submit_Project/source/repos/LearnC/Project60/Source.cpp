#include<stdio.h>

//Khai  bao nguyen mau ham
void nhap();
void xuat();
void timKiemMaxAm();
void timKiemMinDuong();

int a[100];
int n;

int main() {
	nhap();
	xuat();
	timKiemMaxAm();
	timKiemMinDuong();


	return 0;
}

void nhap() {
	int i;

	printf("Nhap so luong phan tu trong mang: \n");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
}

void xuat() {
	int i;

	printf("a[i] = ");
	for (i = 0; i < n; i++) {
		printf("%4d ", a[i]);
	}
}

void timKiemMaxAm() {
	int i;
	int maxAm = 0;

	for (i = 0; i < n; i++) {
		if (a[i] < 0) {
			maxAm = a[i];
			break;
		}
	}
	if (maxAm != 0) {
		for (i = 0; i < n; i++) {
			if (a[i]<0 && a[i]>maxAm) {
				maxAm = a[i];
			}
		}
		printf("\nPhan tu Am lon nhat trong mang la: %d", maxAm);
	}
	else {
		printf("\nKhong co phan tu am!!!");
	}
}

void timKiemMinDuong() {
	int i;
	int minDuong = 0;

	for (i = 0; i < n; i++) {
		if (a[i] > 0) {
			minDuong = a[i];
			break;
		}
	}
	if (minDuong != 0) {
		for (i = 0; i < n; i++) {
			if (a[i] > 0 && a[i] < minDuong) {
				minDuong = a[i];
			}
		}
		printf("\nPhan tu Duong lon nhat trong mang la: %d", minDuong);
	}
	else {
		printf("\nKhong co phan tu duong!!!");
	}



}