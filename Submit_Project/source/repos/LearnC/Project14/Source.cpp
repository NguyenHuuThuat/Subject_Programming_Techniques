/* Viết chương trình tìm ước chung lớn nhất và bội số chung nhỏ nhất của
hai số nguyên a, b*/


#include<stdio.h>

int main() {
	int a, b, UCLN, BCNN;
	printf("Nhap a: \n");
	scanf_s("%d", &a);
	printf("Nhap b: \n");
	scanf_s("%d", &b);

	BCNN = a * b;
	//while (a != b)
	//{
	//	if (a > b) {
	//		a = a - b;
	//	}
	//	else {
	//		b = b - a;
	//	}
	//}
	//cach 2
	while (a != 0) {
		int x = a;
		a = b % a;
		b = x;


	}
	printf("\nUCLN = %d", b);
	printf("\nBCNN = %d", BCNN / b);


}