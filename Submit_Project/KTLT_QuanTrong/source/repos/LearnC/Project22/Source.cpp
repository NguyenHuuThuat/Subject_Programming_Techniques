/*Một số được gọi là số thuận nghịch nếu ta đọc từ trái sang phải hay từ
phải sang trái số đó ta vẫn nhận được một số giống nhau. Hãy nhập một số và
kiểm tra xem số đó có phải số thuật nghịch hay không (ví dụ số: 558855).*/

#include<stdio.h>

int main() {
	long i, n;
	printf("Nhap n: \n");
	scanf_s("%ld", &n);
	long m = n;
	long dao = 0;

	while(m > 0) {
		dao = dao * 10 + m % 10;
		m /= 10;
	}
	if (dao == n) {
		printf("Hai so do thuan nghich");
	}
	else {
		printf("Hai so do khong thuan nghich");
	}
	return 0;
}