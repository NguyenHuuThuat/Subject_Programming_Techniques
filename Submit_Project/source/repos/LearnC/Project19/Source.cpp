#include<stdio.h>

int main() {
	unsigned int n;
	unsigned int i = 2;
	int count = 0;
	printf("Nhap n:  ");
	scanf_s("%d", &n);

	if (n < 1) {
		printf("\nNhap lai n!!!");
	}
	else if (n == 1) {
		printf("1 = p^0, p la so thuc");
	}
	else
	{
		while (n > 1) {
			if (n % i == 0) {
				count++;
				if (n == i) {
					printf("%d^%d", i, count);
				}
				n /= i;
			}
			else {
				if (count > 0) {
					printf("%d^%d\tx", i, count);
					count = 0;
				}
				i++;
			}
		}
	}




}