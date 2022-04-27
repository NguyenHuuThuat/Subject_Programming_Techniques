/*Nhập một xâu ký tự và tìm từ dài nhất, chỉ rõ vị trí của nó trong xâu đó.
Nếu có nhiều từ có độ dài giống nhau thì chọn từ đầu tiên. */

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//khai bao nguyen ham

bool khoangTrang(char c);
int timViTri(char* str, int* length);
void hienThiTu(char* str, int pos, int* length);

int main() {
	char x[100];
	fgets(x, 99, stdin);
	int *len = 0;
	int pos = timViTri(x, len);

	printf("Xau vua nhap la: \n");
	puts(x);
	hienThiTu(x, pos, len);
	return 0;
}

bool khoangTrang(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}

int timViTri(char* str, int* length) {
	int len = 0;
	int lenMax = 0;
	int pos = 0;
	int posCur = 0;
	int i;
	int size = strlen(str);
	for (i = 0; i < size; i++) {
		if (khoangTrang(str[i])) {
			posCur = i - len;
			len++;
		}
		else {
			if (len > lenMax) {
				lenMax = len;
				pos = posCur;
			}
			len = 0;
		}
	}
	*length = lenMax;
	return pos;
}

void hienThiTu(char* str, int pos, int* length) {
	printf("Tu dai nhat la: \n");
	int i;
	for (i = pos; i < pos + *length; i++) {
		printf("%c", str[i]);
	}
	printf("\nDo dai lon nhat cua 1 tu trong xau la: %d, tai vi tri: %d", length, pos);
}
