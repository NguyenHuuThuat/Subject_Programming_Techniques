/*Cho mảng số nguyên gồm n phần tử tùy ý nhập từ bàn phím hoặc file.
Nhập thêm giá trị nguyên x và đếm số lần xuất hiện của x trong mảng.*/

#include<stdio.h>

void nhapMang(int* arr, int *n);
void hienThi(int* arr, int *n);
void dem(int* arr, int *n, int x);


int main() {
	int n  ;
	int arr[100];
	int x;
	printf("Nhap x = \n");
	scanf_s("%d", &x);

	nhapMang(arr, &n);
	hienThi(arr, &n);
	dem(arr, &n, x);
	return 0;



}

void nhapMang(int* arr, int *n) {
	int i;
	*n = 0;
	while (*n <= 0) {
		printf("Nhap n > 0 \n");
		scanf_s("%d", n);
	}
	for (i = 0; i < *n; i++) {
		printf("a[%d] = \n", i);
		scanf_s("%d", &arr[i]);
	}
}

void hienThi(int* arr, int *n) {
	int i;
	printf("Mang la: ");
	for (i = 0; i < *n; i++) {
		printf("%5d", arr[i]);
	}
}

void dem(int* arr, int *n, int x) {
	int i;
	int count = 0;
	for (i = 0; i < *n; i++) {
		if (arr[i] == x) {
			count++;
		}
	}
	printf("\nSo lan xuat hien cua %d la %d", x, count);
}