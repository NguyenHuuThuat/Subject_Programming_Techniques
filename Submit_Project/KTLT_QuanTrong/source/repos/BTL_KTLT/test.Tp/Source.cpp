#include <stdio.h>
#include <math.h>

void hienThiSoTP(double num, int n);
int main(void)
{
    double num = 3.1590;
    int n;

    // Lấy n từ bàn phím
    printf("n = ");
    scanf("%d", &n);

    // In số có n chữ số đằng sau dấu phẩy
	hienThiSoTP(num, n);

    return 0;
}


void hienThiSoTP(double num, int n) {
	int i;
	long int current_digit, next_digit;

	if ((num < 0) && (num > -1)) {
		printf("-0.");
	}
	else {
		printf("%d.", (int)num);
	}
	for (i = 0; i < n; i++)
	{
		current_digit = (long int)(num * pow(10, ((double)i + 1))) % 10;
		next_digit = (long int)(num * pow(10, ((double)i + 2))) % 10;

		if (i == n - 1 && next_digit > 4)
			printf("%ld", abs(current_digit + 1));
		else
			printf("%ld", abs(current_digit));
	}
}
