/*Nhập số tự nhiên n rồi liệt kê các ước số của nó. Số đó bao nhiêu ước?*/

#include<stdio.h>

int main() {
	int n, i, k = 0 ;
	printf("Nhap n: \n");
	scanf_s("%d", &n);

	printf("\nCac uoc cua n la: ");
	for (i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			printf("%d\t", i);
			k++;
		}
	}
	printf("\nn co %d uoc", k);
	return 0;
	


}