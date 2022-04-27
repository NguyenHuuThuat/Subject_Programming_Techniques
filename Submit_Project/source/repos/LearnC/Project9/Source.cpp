/*Nhập số tự nhiên n rồi tính tổng(lưu ý phép chia các số nguyên):*/

#include<stdio.h>

int main() {
	int n, i;
	float sum = 0;
	printf("Nhap n: \n");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++) {
		sum = sum + 1.0/i;
	}
	printf("S =  %f", sum);
	return 0;


}