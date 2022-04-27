#include<stdio.h>

int main() {
	int i = 222, sum = 0;

	do {
		sum = sum + i;
		i++;

	} while (i < 5);
	
	printf("sum = %d", sum);


}