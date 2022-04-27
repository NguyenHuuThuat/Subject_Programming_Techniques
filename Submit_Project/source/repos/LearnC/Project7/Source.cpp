/* Nhập số tự nhiên n sau đó in ra các số chẵn nhỏ hơn n và các số lẻ nhỏ
hơn n*/

#include<stdio.h>

int main() {
	int n , i ;
	printf("Nhap n: \n");
	scanf_s("%d", &n);

	printf("So chan nho hon n la: \n");
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			printf("%d\t", i);
		}
	}
	printf("\nSo le nho hon n la: \n");
	for (i = 0; i < n; i++) {
		if (i % 2 == 1) {
			printf("%d\t", i);
		}
	}
	return 0;


}