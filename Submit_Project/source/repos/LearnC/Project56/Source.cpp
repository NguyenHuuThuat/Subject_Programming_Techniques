/*  Cho một chuỗi ký tự đầu vào, hãy cho biết nó có bao nhiêu ký tự là nguyên
âm, phụ âm, ký tự số và ký tự khác. */

#include<stdio.h>
#include<string.h>

//Khai bao nguyen ham
int demNguyenAm(char* c);
int demPhuAm(char* c);
int demSo(char* c);
int demKyTuKhac(char* c);

int main() {
	char x[100];
	fgets(x, 99, stdin);

	printf("So nguyen am trong chuoi vua nhap la: %d\n", demNguyenAm(x));
	printf("So phu am trong chuoi vua nhap la: %d\n", demPhuAm(x));
	printf("So so trong chuoi vua nhap la: %d\n", demSo(x));
	printf("So ky tu khac trong chuoi vua nhap la: %d\n", demKyTuKhac(x));

	return 0;
}

int demNguyenAm(char* c) {
	int len = strlen(c);
	int i, j;
	int count = 0;
	char nguyenAm[] = { 'a', 'e', 'o', 'i', 'u' };
	int len2 = strlen(nguyenAm);

	for (i = 0; i < len; i++) {
		for (j = 0; j < len2; j++) {
			if (c[i] == nguyenAm[j]) {
				count++;
			}
		}
	}
	return count;
}

int demPhuAm(char* c) {
	int len = strlen(c);
	int i, j;
	int count = 0;
	char phuAm[] = { 'b' , 'c' , 'd' , 'f' , 'g' , 'h' , 'j' , 'k' , 'l' , 'm', 'n' , 'p' , 'q' ,
		'r' , 's' , 't' , 'v' , 'w' , 'x' , 'y' , 'z' };
	int len2 = strlen(phuAm);

	for (i = 0; i < len; i++) {
		for (j = 0; j < len2; j++) {
			if (c[i] == phuAm[j]) {
				count++;
			}
		}
	}
	return count;
}
int demSo(char* c) {
	int len = strlen(c);
	int i, j;
	int count = 0;
	char so[] = { '0','1','2','3','4','5','6','7','8','9'};
	int len2 = strlen(so);

	for (i = 0; i < len; i++) {
		for (j = 0; j < len2; j++) {
			if (c[i] == so[j]) {
				count++;
			}
		}
	}
	return count;
}

int demKyTuKhac(char* c) {
	return strlen(c) - demNguyenAm(c) - demPhuAm(c) - demSo(c);
}