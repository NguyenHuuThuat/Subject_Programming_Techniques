/*Cho mảng số nguyên gồm n phần tử được nhập vào từ bàn phím hoặc
file. Hãy tìm phần tử thỏa mãn:
a) Là giá trị lớn thứ hai trong mảng
b) Là giá trị nhỏ thứ hai trong mảng*/

#include<stdio.h>

void nhap(int* n, int* arr);
void minMax(int* arr, int n, int* min, int* max);
void minMax2(int* arr, int n, int* min2, int* max2);
void ketQua(int min2, int max2);

int main() {
	int n = 0;
	int arr[100];
	int min2, max2;
	nhap(&n, arr);
	minMax2(arr, n, &min2, &max2);
	return 0;
}

void nhap(int* n, int* arr) {
	int i;
	printf("Dia chi n: 0x%x, gia tri n: %d\n", n,*n);
	while ((*n) <= 0) {
		printf("Nhap n>0: \n");
		scanf_s("%d", n);
	}
	for (i = 0; i < (*n); i++) {
		printf("arr[%d] = \n", i);
		scanf_s("%d", &arr[i]);
	}
}

void minMax(int* arr, int n, int* min, int* max) {
	int i;
	for (i = 0; i < (n); i++) {
		if ((*min) > arr[i]) {
			(*min) = arr[i];
		}
		if ((*max) < arr[i]) {
			(*max) = arr[i];
		}
	}
}
void minMax2(int* arr, int n, int* min2, int* max2) {
	int i;
	int min, max;
	minMax(arr, n, &min, &max);

	for (i = 0; i < (n); i++) {
		if ((*min2) > arr[i] && arr[i] != min) {
			(*min2) = arr[i];
		}
		if ((*max2) < arr[i] && arr[i] != max) {
			(*max2) = arr[i];
		}
	}
	if (((*min2) != (min)) && ((*max2) != max) && ((*min2) < (*max2))) {
		ketQua(*min2, *max2);
	}
	else {
		printf("Khong co ket qua phu hop!!!");
	}
}

void ketQua(int min2, int max2) {
	printf("\nGia tri nho thu hai va lon thu hai cua mang la: %d\t%d", min2, max2);
}