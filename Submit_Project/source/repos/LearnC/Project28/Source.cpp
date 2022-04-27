#include<stdio.h>
#include<math.h>

int main() {
	int h, m, n, i, j;
	scanf_s("%d", &h);

	if (h > 0) {
		for (i = 1; i <= h; i++) {
			for (j = 1; j < 2*h; j++) {
				if (abs(h - j) <= (i - 1)) {
					printf(" %d ", i-abs(h-j));
				}
				else {
					printf("   ");
				}
			}
			printf("\n");

		}
	}
	return 0;

}