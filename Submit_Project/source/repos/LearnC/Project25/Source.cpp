/* Hãy viết chương trình tính tổng các chữ số của một số nguyên bất kỳ.
Ví dụ: số 8545604 có tổng các chữ số là: 8 + 5 + 4 + 5 + 6 + 0 + 4 = 32*/

#include<stdio.h>

int main() {
	long long n;
	int chuSo;
	int sum = 0;
	printf("Nhap n: ");
	scanf_s("%ld", &n);
	long long m = n;


	while (m > 0)
	{
		chuSo = m % 10;
		sum = sum + chuSo;
		chuSo = 0;
		m /= 10;
	}
	printf("\nTong cac chu so cua %ld la: %d", n, sum);
	return 0;

}