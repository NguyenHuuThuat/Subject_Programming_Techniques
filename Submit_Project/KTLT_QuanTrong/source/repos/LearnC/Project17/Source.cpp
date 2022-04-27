/*Viết chương trình liệt kê n số nguyên tố đầu tiên*/

#include<stdio.h>
#include<math.h>

int main() {
	int n;
	int i, m = 2, count = 0 ;
	printf("Nhap n");
	scanf_s("%d", &n);

	if (n < 1) {
		printf("Nhap so nguyen duong!!!");
	}
	else {
		while (1) {
			int mark = 1;
			for (i = 2; i <= sqrt(m); i++) {
				if (m % i == 0) {
					mark = 0;
					break;
				}
			}
			if (mark == 1) {
				count++;
				printf("%d, ", m);
			}
			if (count >= n) {
				break;
			}
			m++;
		}
	}
	return 0;
}