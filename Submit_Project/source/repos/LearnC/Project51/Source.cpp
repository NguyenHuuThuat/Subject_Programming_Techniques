/* Đếm số từ của xâu ký tự nhập vào từ bàn phím. Ví dụ xâu “I can’t speak
English” gồm 4 từ. */

#include<stdio.h>
#include<string.h>

int laKhoangTrang(char c);
int demTu(char* arr);

int main() {
	char nhapMang[1000];
	fgets(nhapMang, 999, stdin);

	printf("\nso tu cua xau ky tu la: %d", demTu(nhapMang));
	return 0;
}

int laKhoangTrang(char c) {
	return (c == ' ' || c == '\t');
}

int demTu(char* arr) {
	int i;
	int count = 0;
	int size = strlen(arr);

	for (i = 0; i < size - 1; i++) {
		if (!laKhoangTrang(arr[i]) && laKhoangTrang(arr[i + 1]) ||
			!laKhoangTrang(arr[i]) && !laKhoangTrang(arr[i + 1]) && i + 1 == size - 1) {
			count++;
		}
	}
	return count;
}