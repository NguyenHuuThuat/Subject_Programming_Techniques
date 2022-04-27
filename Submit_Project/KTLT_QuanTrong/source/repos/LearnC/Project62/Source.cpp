#include<stdio.h>

int main() {
	char Arr[4];
	int i;

	for (i = 0; i < 4; i++) {
		printf("Dia chi cua Arr[%d] la: %d", i, &Arr[i]);
	}
	return 0;

}