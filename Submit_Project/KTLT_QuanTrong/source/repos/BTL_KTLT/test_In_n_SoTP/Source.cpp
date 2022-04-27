#include<stdio.h>
#include<math.h>


int main() {
	double a = 2.34333234334;

	printf("%d.", int(a));
	for (int i = 1; i < 4; i++) {
		printf("%d", (int)(a * pow(10, i)) % 10);


	}


}

