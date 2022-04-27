/*Cho một số nguyên dương k được nhập vào từ bàn phím. Hãy viết
chương trình tìm và in ra tất cả các số thuận nghịch có 8 chữ số thỏa mãn chia
hết cho k.*/

#include<stdio.h>
#include<stdbool.h>

bool thuanNghich(long n);
bool chiaHet(long n, int k);

int main() {
	int i, k;
	printf("Nhap k: \n");
	scanf_s("%d", &k);

	for (i = 10000000; i < 99999999; i++) {
		if (thuanNghich(i) && chiaHet(i, k)) {
			printf("%10d", i);
		}
	}
	return 0;
}

bool thuanNghich(long n) {
	long m = n;
	long soDao = 0;
	while (m > 0)
	{
		soDao = soDao * 10 + m % 10;
		m /= 10;
	}
	return soDao = n;
}

bool chiaHet(long n, int k) {
	if (k == 0) {
		return false;
	}
	return n % k == 0;
}

