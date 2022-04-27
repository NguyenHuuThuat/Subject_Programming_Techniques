/*Cho số dương n và mảng arr gồm n số nguyên tùy ý. Hãy:
a) Sắp xếp các phần tử trong mảng này theo thứ tự tăng dần từ trái qua phải
b) Sắp xếp các phần tử trong mảng này theo thứ tự giảm dần từ trái qua phải
c) Hiển thị kết quả trước và sau sắp xếp*/

#include<stdio.h>

void nhapMang(int* arr, int* n);
void sapXepTang(int* arr, int* n);

int main() {
	int n = 10;
	int arr[100];

	nhapMang(arr, &n);
	sapXepTang(arr, &n);
}

void nhapMang(int* arr, int* n) {
	int i;

	for (i = 0; i < *n; i++) {
		printf("arr[%d] = \n", i);
		scanf_s("%d", &arr[i]);
	}
	//in mang
	printf("Mang ban dau la: ");
	for (i = 0; i < *n; i++) {
		printf("%d\t", arr[i]);
	}
}

void sapXepTang(int* arr, int* n) {
	int* arr1;
	int i;
	int tmp = 0;

	for (i = 0; i < *n; i++) {
		if (arr[i] >  arr[i + 1]) {
			//doiCho(*arr[i], *arr[i + 1]);
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
		else {
			i++;
		}
	}
	//in mang
	printf("\n");
	printf("Mang sau khi duoc sap xep la: ");
	for (i = 0; i < *n; i++) {
		printf("%d\t", arr[i]);
	}
}

//void doiCho(int* a, int* b) {
//	int tmp =0 ;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}