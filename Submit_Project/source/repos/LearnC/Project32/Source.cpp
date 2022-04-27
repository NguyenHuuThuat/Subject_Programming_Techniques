/*Viết chương trình với các chức năng sau:
a) Nhập vào số nguyên dương n
b) Tính tổng các chữ số của n
c) Phân tích n thành các thừa số nguyên tố*/

#include<stdio.h>
#include<math.h>

int nhapso();
int tinhTongCacCS(int n);
void phanTichSNT(int n);

int main() {
	int n;
	//printf("Nhap so: \n");
	//scanf_s("%d", &n);
	n = nhapso();
	printf("So vua nhap co %d chu so!!!\n", tinhTongCacCS(n));
	phanTichSNT(n);
	return 0;
}

int nhapso() {
	int n = 0;
	while (n <= 0) {
		printf("Nhap n > 0: ");
		scanf_s("%d", &n);
	}
	return n;
}
int tinhTongCacCS(int n) {
	int m = n;
	int tmp = 0;
	int count = 0;
	while (m > 0) {
		tmp = m % 10;
		count++;
		m /= 10;
		tmp = 0;
	}
	return count;
}
void phanTichSNT(int n) {
	int m = n;
	int i=2;
	int count = 0;

	printf("\nphan tich %d ra so NT\n", n);
	while (i <= n) {
		if (n % i == 0) {
			printf("%2d  ", i);
			n /= i;
		}
		else {
			i++;
		}
	}
}