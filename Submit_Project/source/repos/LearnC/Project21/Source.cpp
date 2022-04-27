/*Dãy số Fibonacci được định nghĩa như sau: F0 = 1, F1 = 1; Fn = Fn-1 + Fn-
2 với n >= 2. Hãy viết chương trình tìm số Fibonacci thứ n*/
//KHONG DE QUY

#include<stdio.h>

int main() {
	int n;
	int i;
	unsigned long long f0 = 1;
	unsigned long long f1 = 1;
	unsigned long long fn = 0;
	printf("Nhap n: \n");
	scanf_s("%d", &n);
	if (n < 0) {
		printf("Nhap n khong am");
	}
	else {
		for (i = 2; i <= n; i++) {
			fn = f0 + f1;
			f0 = f1;
			f1 = fn;
		}
		printf("So Fibonacci thu n la: %d", fn);
	}
	return 0;
}