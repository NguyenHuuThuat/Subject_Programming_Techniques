/*Nhập số tự nhiên n rồi tính tổng: S = 1 + 2 + ... + n.*/

#include<stdio.h>

int main() {
	int n, i;
	int sum = 0;
	printf("Nhap n: \n");
	scanf_s("%d", &n);

	for (i = 0; i <= n; i++) {
		sum = sum + i;
	}
	printf("S = 1 + 2 + ... + n =  %d", sum);
	return 0;


}