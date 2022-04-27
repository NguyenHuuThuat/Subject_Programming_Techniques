/*Bài 4.1. Nhập vào số dương n và một mảng các phần tử từ arr[0] đến arr[n - 1].
Hãy tìm giá trị lớn nhất và nhỏ nhất trong mảng trên*/

#include<stdio.h>

void nhap(int* arr, int* n);
void minMax(int* arr, int* n, int* min, int* max);


int main() {
	int n;
	int arr[100];
	int min=-9999, max=arr[0];

	nhap(arr, &n);
	minMax(arr, &n, &min, &max);

	return 0;
}

void nhap(int* arr, int* n) {
	int i;
	while (*n <= 0) {
		printf("\nNhap n duong");
		scanf_s("%d", n);
	}
	for (i = 0; i < *n; i++) {
		printf("\narr[%d] = ", i);
		scanf_s("%d", &arr[i]);
	}
}

void minMax(int* arr, int* n, int* min, int* max) {
	int i;
	*min = arr[0];
	*max = arr[0];
	for (i = 1; i < *n; i++) {
		if (*min > arr[i]) {
			*min = arr[i];
		}
	}
	printf("GTNN cua mang la: %d", *min);
	for (i = 1; i < *n; i++) {
		if (*max < arr[i]) {
			*max = arr[i];
		}
	}
	printf("GTLN cua mang la: %d", *max);
}