/* Nhập vào một chuỗi ký tự và in ra các từ theo thứ tự ngược lại. Ví dụ: “I
love learning C programming” -> “programming C learning love I” */

#include<stdio.h>
#include<string.h>

void tachTu(char* c);
void hienThi(char c[100][20], int size);

int main() {
	char x[100];
	fgets(x, 99, stdin);

	tachTu(x);
	
	return 0;
}

void tachTu(char* c) {
	char arr[100][20];
	int i = 0;
	char* p;
	const char* dauHieu = " .,;-\t\n";
	for (p = strtok(c, dauHieu); p != NULL; p = (strtok(NULL, dauHieu))) {
		strcpy(arr[i++], p);
	}
	hienThi(arr, i);
}

void hienThi(char c[100][20], int size) {
	int i;
	for (i = size - 1; i >= 0; i--) {
		printf("%s   ", c[i]);
	}
}