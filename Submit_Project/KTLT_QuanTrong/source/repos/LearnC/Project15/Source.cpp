/*Viết chương trình nhập số nguyên n và kiểm tra n có phải số nguyên tố
hay không*/

#include<stdio.h>

int main() {
	int i, n;
	printf("Nhap n: \n");
	scanf_s("%d", &n);
	
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			printf("n khong la so nguyen to");
		}
		else {
			printf("n la so nguyen to");
		}
	}


}