#include<stdio.h>
#include<ctype.h>

int main() {
	//char c;
	//c = getchar();
	//scanf_s("%c", &c);
	//printf("%d", c); //in ma ASCII
	//printf("\n%c", c);

	////char str[200] = "Nguyen Huu Thuat!!!";
	//char str[100];

	//fflush(stdin);
	//gets_s(str);


	//printf("\n%s", str);

	char x = ' ';
	if (isblank(x)) {
		printf("%c la khoang trang!!!\n", x);
	}
	else {
		printf("%c khong la khoang trang",x);
	}
	return 0;

}