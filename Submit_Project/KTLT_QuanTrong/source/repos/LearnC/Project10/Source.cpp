/*Nhập vào một số tự nhiên n rồi tính:
a) S = tổng các số tự nhiên không lớn hơn n.
b) S1 = tổng các số tự nhiên lẻ không lớn hơn n.
c) S2 = tổng các số tự nhiên chẵn không lớn hơn n.*/

#include<stdio.h>

int main() {
	int n, i;
	int sum = 0, sum1 = 0, sum2 = 0;
	printf("Nhap n: \n");
	scanf_s("%d", &n);

	for (i = 0; i <= n; i++) {
		sum = sum + i;
	}
	printf("S = 1 + 2 + ... + n =  %d", sum);

	for (i = 0; i <= n; i++) {
		if (i % 2 == 0){
			sum1 = sum1 + i;
		}		
	}
	printf("S1 = 0 + 2 + ... +  =  %d", sum1);

	for (i = 0; i <= n; i++) {
		if (i % 2 == 1) {
			sum2 = sum2 + i;
		}
	}
	printf("S2 = 1 + 3 + ... +  =  %d", sum2);
	return 0;
}