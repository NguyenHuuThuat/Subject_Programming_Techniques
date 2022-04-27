/*Dãy số Fibonacci được định nghĩa như sau: F0 = 1, F1 = 1; Fn = Fn-1 + Fn-
2 với n >= 2. Hãy viết chương trình tìm số Fibonacci thứ n*/
//DE QUY

#include<stdio.h>

int deQuy(int n);

int main() {
	int n;
	printf("Nhap n: \n");
	scanf_s("%d", &n);
	printf("So Fibonacci thu n la: %d", deQuy(n));
	return 0;
}
int deQuy(int n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 1;
	}
	else
	{
		return deQuy(n - 1) + deQuy(n - 2);
	}

}

