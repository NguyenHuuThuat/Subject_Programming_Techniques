/*Nhập số tự nhiên n rồi tính n! theo công thức:
n! = 1 nếu n = 0
n! = n*(n - 1) * (n - 2) * ... * 2 * 1 nếu n > 0*/
//khong de quy

#include<stdio.h>

long long giaiThua(int n);

int main() {
	int i, n;
	printf("Nhap n: \n");
	scanf_s("%d", &n);
	printf("\nn! = %ld", giaiThua(n));
	return 0;
}

long long giaiThua(int n) {
	if (n == 0) {
		return 1;
	}
	//if (n == 1) {
	//	return 1;
	//}
	if (n > 0)
	{
		return n * giaiThua(n - 1);
	}
}