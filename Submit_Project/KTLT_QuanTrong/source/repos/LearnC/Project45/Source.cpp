/*Euclid*/

#include<stdio.h>

int main() {
	int UCLN, BCNN;
	int r = 0;
	int m = 0, n = 0;

	//nhap m, n
	while ((m <= 0) || (n <= 0)) {
		printf("Nhap m,n la 2 so nguyen duong!!! \n");
		printf("m = \n");
		scanf_s("%d", &m);
		printf("n = \n");
		scanf_s("%d", &n);
	}
	BCNN = m * n;
	while (n != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	UCLN = m;
	printf("UCLN = %d", UCLN);
	printf("BCNN = %d", BCNN / UCLN);
	return 0;
}