/*Nhập số tự nhiên n rồi tính n! theo công thức:
n! = 1 nếu n = 0
n! = n*(n - 1) * (n - 2) * ... * 2 * 1 nếu n > 0*/
//khong de quy

#include<stdio.h>

int main() {
	int i, n;
	printf("Nhap n: \n");
	scanf_s("%d", &n);
	long long gt = 1;

	if (n < 0) {
		printf("Nhap n khong am");
	}
	else {
		for (i = 1; i <= n; i++) {
			gt *= i;
		}
	}
	printf("\nn! = %ld", gt);
	return 0;
}