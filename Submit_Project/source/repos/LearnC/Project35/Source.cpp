#include<stdio.h>

void lapPhuong(int* x);

int main() {
	//int arr[] = { 1,2,3,4,5 };
	//int* ptr = arr;
	//int i;

	////printf("\nDia chi mang: %x", arr);
	////printf("\nDia chi mangxxxxxxxxx: %x", &arr);
	////printf("\nDia chi phan tu dau tien cua mang: %x", &arr[0]);
	////printf("\nGia tri cua con tro ptr: %x", ptr);

	//for (i = 0; i < 5; i++) {
	//	printf("%5d", arr[i]);
	//}
	//printf("\n");
	//for (i = 0; i < 5; i++) {
	//	printf("%5d", *(ptr + i));
	//}
	//printf("\n");

	//for (; ptr <= &arr[4]; ptr++) {
	//	printf("%5d", *ptr);
	//}
	int x = 5;
	printf("Gia tri cua x ban dau la: %d", x);

	lapPhuong(&x);

	printf("\nGia tri cua x sau la: %d", x);




}

void lapPhuong( int* x) {
	*x = (*x) * (*x) * (*x);
}
