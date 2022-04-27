/*Nhập vào hai số dương a, b sao cho a < b. Tìm và in ra tất cả các số
nguyên tố trong đoạn [a, b]*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool soNT(int n);

int main() {
	int a, b;
	int i;
	printf("Nhap doan [a , b]\n");
	printf("Nhap a: \n");
	scanf_s("%d", &a);
	printf("Nhap b: \n");
	scanf_s("%d", &b);

	for (i = a; i <= b; i++) {
		if (soNT(i)) {
			printf("%d  ", i);
		}
	}
	return 0;
}

bool soNT(int n) {
	int i;
	if (n < 2) {
		return false;
	}
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;

}
