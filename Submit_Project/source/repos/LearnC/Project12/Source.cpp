/*Nhập số tự nhiên n rồi tính tổng các số tự nhiên không lớn hơn n và chia
hết cho 7*/

#include<stdio.h>

int main() {
	int i, n;
	int sum = 0;\
	printf("Nhap n: \n");
	scanf_s("%d", &n);

	for (i = 0; i <= n; i++) {
		if (i % 7 == 0) {
			sum = sum + i;
		}
	}
	printf("S = %d", sum);
	return 0;


}