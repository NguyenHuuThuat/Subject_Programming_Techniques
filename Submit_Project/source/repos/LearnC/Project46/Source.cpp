#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>


void lapPhuong(int* nPtr);

int main() {
	int n = 5;
	int i;
	printf("Gia tri ban dau: n = %d\n", n);

	lapPhuong(&n);
	printf("Gia tri luc sau: n = %d\n", n);

	for (i = 0; i < 10; i++) {
		printf("%i : %d\n",i, 1 + (rand() % 6));

	}

	return 0;
}

void lapPhuong(int* nPtr) {
	*nPtr = (*nPtr) * (*nPtr) * (*nPtr);


}