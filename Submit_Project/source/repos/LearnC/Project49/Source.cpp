/* Cho mảng số nguyên gồm n phần tử tùy ý. Hãy nhập giá trị nguyên x nào
đó và xác định phần tử có giá trị gần x nhất. Giá trị k nào đó gọi là gần x nhất nếu
|k - x| gần với 0 nhất. */

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

void nhapMang(int* arr, int* n);
int timHieuMin(int* arr, int* n, int x);
//bool xuatHien(int* b, int* n, int v);
void inKetQua(int* arr, int* n, int x, int hieu);

int main() {
	int n;
	int arr[100];
	int x = 5;
	int hieu = 0;

	nhapMang(arr, &n);
	hieu = timHieuMin(arr, &n, x);
	inKetQua(arr, &n, x, hieu);

	return 0;
}

void nhapMang(int* arr, int* n) {
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

int timHieuMin(int* arr, int* n, int x) {
	int hieu = abs(arr[0] - x);
	int i;

	for (i = 1; i < *n; i++) {
		if (hieu > abs(arr[i] - x)) {
			hieu = abs(arr[i] - x);
		}
	}
	return hieu;
}

//bool xuatHien(int* b, int* n, int v) {
//	int i;
//	for (i = 0; i < *n; i++) {
//		if (b[i] == v) {
//			return false;
//		}
//	}
//	return true;
//}

void inKetQua(int* arr, int* n, int x, int hieu) {
	int i;
	int b[100];
	int* count = 0;

	for (i = 0; i < *n; i++) {
		if ((abs(arr[i] - x) == hieu)) {
			printf("\n%5d", arr[i]);
		}
	}


}