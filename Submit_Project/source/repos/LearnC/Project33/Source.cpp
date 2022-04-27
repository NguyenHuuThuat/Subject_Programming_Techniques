/*Thực hiện các chức năng sau:
a) Nhập vào giá trị cho n > 0
b) Đếm số chữ số của n
c) Đếm số chữ số lẻ của n
d) Tìm trung bình cộng các chữ số của n*/

#include<stdio.h>

int nhapso();
int demCacCS(int n);
int demCacCSLe(int n);
float trungBinhCong(int);



int main() {
	int n;
	n = nhapso();
	printf("\n%d co %d chu so!!! ", n, demCacCS(n));
	printf("\n%d co %d chu so le!!! ", n, demCacCSLe(n));
	printf("\nTrung binh cong cac chu so cua %d la: %f", n, trungBinhCong(n));
	return 0;
}

int nhapso() {
	int n = 0;
	while (n <= 0) {
		printf("Nhap n > 0: ");
		scanf_s("%d", &n);
	}
	return n;
}
int demCacCS(int n) {
	int m = n;
	int tmp = 0;
	int count = 0;
	while (m > 0) {
		tmp = m % 10;
		count++;
		m /= 10;
		tmp = 0;
	}
	return count;
}

int demCacCSLe(int n) {
	int m = n;
	int tmp = 0;
	int count = 0;
	while (m > 0) {
		tmp = m % 10;
		if (tmp % 2 == 1) {
			count++;
		}
		m /= 10;
		tmp = 0;
	}
	return count;
}
float trungBinhCong(int n) {
	int m = n;
	int tmp = 0;
	int count = 0;
	int sum = 0;

	while (m > 0) {
		tmp = m % 10;
		sum += tmp;
		count++;
		m /= 10;
		tmp = 0;
	}
	return (float)sum / count;
}