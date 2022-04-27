/*Nhập 2 số tự nhiên m, n rồi kiểm tra xem chúng có nguyên tố cùng nhau
không(Hai số nguyên tố cùng nhau là 2 số có USCLN là 1)*/


#include<stdio.h>

int UCLN(int m, int n);

int main() {
	int m, n;
	printf("Nhap m: \n");
	scanf_s("%d", &m);
	printf("Nhap n: \n");
	scanf_s("%d", &n);
	if (UCLN(m, n) == 1) {
		printf("\n%d , %d la 2 so nguyen to cung nhau!!!", m, n);
	}
	else {
		printf("\n%d , %d la KHONG 2 so nguyen to cung nhau!!!", m, n);
	}
	return 0;
}
int UCLN(int m, int n) {
	int r = 0;
	while (m!=0)
	{
		r = m;
		m = n % m;
		n = r;
	}
	return n;
}
