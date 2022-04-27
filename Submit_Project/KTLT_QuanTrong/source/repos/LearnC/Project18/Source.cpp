#include<stdio.h>


void hienUoc(int n);

int main() {
	hienUoc(12);
	return 0;

}

void hienUoc(int n) {
	int i = 2;
	int dauInRa = 1;
	while (n > 1) {
		if (n % i == 0) {
			if (dauInRa != i) {
				printf("%d\t", i);
				dauInRa = i;
			}
			n /= i;
		}
		else {
			i++;
		}
	}
}