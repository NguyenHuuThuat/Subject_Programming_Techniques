/*Nhập vào một xâu ký tự bất kỳ, thực hiện:
a. Viết hoa toàn bộ xâu
b. Viết thường toàn bộ xâu */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void xauHoa(char* c);
void xauThuong(char* c);

int main() {
	char x[100];
	fgets(x, 99, stdin);

	printf("Xua ky tu vua nhap la: \n");
	puts(x);
	xauHoa(x);
	xauThuong(x);

	return 0;

}

void xauHoa(char *c) {
	int i;
	int size = strlen(c);

	for (i = 0; i < size; i++) {
		c[i] = toupper(c[i]);
	}
	printf("xau ky tu hoa la: %s\n", c);
	 
}

void xauThuong(char* c) {
	int i;
	int size = strlen(c);

	for (i = 0; i < size; i++) {
		c[i] = tolower(c[i]);
	}
	printf("xau ky tu thuong la: %s\n", c);

}