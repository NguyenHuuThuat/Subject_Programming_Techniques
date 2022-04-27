/*Bài 5: Nhập số nguyên dương n và tính tổng: S = 1 + 1.2 + 1.2.3 + ... + 1.2.3...n.*/


#include<stdio.h>

int main() {
	int i, n;
	long sum = 0;
	long gt=1;
	printf("Nhap n: \n");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++) {
		gt = gt * i;
		sum = sum + gt;
	}
	printf("S = %ld", sum);

}