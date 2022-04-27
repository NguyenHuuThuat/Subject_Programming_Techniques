/* Nhập họ và tên theo cấu trúc: họ-đệm-tên và chuyển xâu đó sang biểu diễn
theo cấu trúc tên-đệm-họ */

#include<stdio.h>
#include<string.h>

//Khai bao nguyen ham
int dauCachDau(char* c);
int dauCachCuoi(char* c);
void hienThi(char* c);


int main() {
	char x[100];
	fgets(x, 99, stdin);

	hienThi(x);

	return 0;

}

int dauCachDau(char* c) {
	int len = strlen(c);
	int i;

	for (i = 0; i < len - 1; i++) {
		if (c[i] == ' ') {
			return i;
		}
	}
	return -1;
}

int dauCachCuoi(char* c) {
	int len = strlen(c);
	int i;

	for (i = len - 1; i >= 0; i--) {
		if (c[i] == ' ') {
			return i;
		}
	}
	return -1;
}

void hienThi(char* c) {
	int first = dauCachDau(c);
	int last = dauCachCuoi(c);
	int len = strlen(c);
	int i;

	if (first != -1 && last != -1) {
		// in ten
		for (i = last + 1; i < len; i++) {
			printf("%c", c[i]);
		}
		//in dem
		for (i = first; i <= last; i++) {
			printf("%c", c[i]);
		}
		//in ho
		for (i = 0; i < first; i++) {
			printf("%c", c[i]);
		}
	}
	else {
		printf("Y.C nhap dung quy cach~!!!\n");
	}
}