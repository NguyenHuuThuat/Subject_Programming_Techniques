// viet chuong trinh cho phep nguoi dung lua chon chuc nang:
	// cong, tru, nhan, chia du, chia nguyen hai so nguyen a, b.
#include<stdio.h>

int main() {
	int luaChon;
	int a, b;
	printf("\n===========MENU============\n"
		"1. Tinh tong hai so nguyen. \n2. Tinh hieu hai so nguyen. \n3.Nhan hai so nguyen. \n4. Chia du hai so nguyen. \n5. Chia nguyen hai so nguyen.\n0. Thoat!!! ");
	printf("\nLua chon cua ban?    ");
	scanf_s("%d", &luaChon);

	switch (luaChon)
	{
	case 0: break;
	case 1: {
		printf("Nhap 2 so nguyen a va b\n");
		scanf_s("%d%d", &a, &b);
		printf("%d + %d = %d", a, b, a + b);
	};
	case 2: {
		printf("Nhap 2 so nguyen a va b\n");
		scanf_s("%d%d", &a, &b);
		printf("%d - %d = %d", a, b, a - b);
	};
	case 3: {
		printf("Nhap 2 so nguyen a va b\n");
		scanf_s("%d%d", &a, &b);
		printf("%d * %d = %d", a, b, a * b);
	};
	case 4: {
		char c = '\%';
		printf("Nhap 2 so nguyen a va b\n");
		scanf_s("%d%d", &a, &b);
		printf("%d ""%"" %d = %d", a, b, a % b);
	};
	case 5: {
		printf("Nhap 2 so nguyen a va b\n");
		scanf_s("%d%d", &a, &b);
		printf("%d / %d = %d", a, b, a / b);
	};
	default:
		printf("Nhap sai lua chon!!!");
		break;
	};
	return 0;
}