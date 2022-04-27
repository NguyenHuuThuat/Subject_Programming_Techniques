/*Đếm ký tự nhập từ bàn phím*/

#include<stdio.h>

int main() {
	int garde;
	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	int dCount = 0;

	printf("Nhap tu dem!!!\n");
	printf("nhap EOF de ket thuc nhap");

	while (garde = getchar() != EOF) {
		switch (garde)
		{
			case 'A':
			case 'a':
				++aCount;
				break;

			case 'B':
			case 'b':
				++bCount;
				break;

			case 'C':
			case 'c':
				++cCount;
				break;

			case 'D':
			case 'd':
				++dCount;
				break;

			case'\n':
			case '\t':
			case ' ':
				break;
		default:
			printf("phan tu dem khong dung\n");
			break;
		}
	}
	printf("\nTotals for each letter grade are:\n");
	printf("A: %d\n", aCount); /* display number of A grades */
	printf("B: %d\n", bCount); /* display number of B grades */
	printf("C: %d\n", cCount); /* display number of C grades */
	printf("D: %d\n", dCount); /* display number of D grades */
	return 0;



}