#include<stdio.h>

int main() {
	int a = 10;
	float b = 1.999;


	int* ptr = &a;
	float* fPtr;
	fPtr = &b;

	printf("\nGia tri cua bien a la:  %d", a);
	printf("\nDia chi cua bien a la:  %x", &a);
	printf("\nGia tri cua ptr la:  %x", ptr);

	printf("\nGia tri cua fPtr la:  %x", fPtr);
	printf("\nGia tri cua b la:  %f", *fPtr);






	return 0;
}