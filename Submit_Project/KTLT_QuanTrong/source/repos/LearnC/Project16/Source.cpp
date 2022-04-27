/*Viết chương trình phân tích một số nguyên thành các thừa số nguyên tố
Ví dụ: Số 28 được phân tích thành 2 x 2 x 7*/

#include<stdio.h>

int main() {
	int i = 2, n;
	printf("Nhap n: \n");
	scanf_s("%d", &n);

	printf("\nPhan tich n = ");
	while (n > 1) {
		if (n % i == 0) {
			printf(" %d ", i);
			if (n != i) {
				printf("x");
			}
			n = n / i;
		}
		else {
			i++;
		}
	}
	return 0;


}