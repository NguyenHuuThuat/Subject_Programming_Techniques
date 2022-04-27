/*Nhập vào 2 số tự nhiên m < n. Hãy liệt kê các số chính phương trong
đoạn [m, n]. Có bao nhiêu số chính phương trong đoạn đó?*/

#include<stdio.h>
#include<math.h>

int main() {
	int m, n;
	int i;
	float can;
	int thu = 0;

	printf("nhap [m , n]: \n");
	printf("Nhap m: \n");
	scanf_s("%d", &m);
	printf("Nhap n: \n");
	scanf_s("%d", &n);

	if (m >= n) {
		printf("Nhap lai m > n\n");
	}
	else {
		for (i = m; i <= n; i++) {
			can = (float) sqrt(i);
			thu = (int)can;
			if (thu == can) {
				printf("%d\t", i);
			}
		}
	}
	return 0;

}