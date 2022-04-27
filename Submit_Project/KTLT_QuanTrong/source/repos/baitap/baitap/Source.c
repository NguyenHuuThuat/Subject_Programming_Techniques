#include<stdio.h>
#include<math.h>

double ham1(double x) {
	return (x * x - 2.0);
}
double ham2(double x) {
	return (pow(2, x) + x - 4);
}

double ham3(double x) {
	return (x * x * x + x - 5.0);
}

double Nghiem(double(*f) (double x), double a, double b) {
	if (f(a) * f(b) >= 0) {
		printf("Ham khong doi dau tren [a,b] \n");
		return -1;
	}
	else {
		while ((fabs(f(a)) > 0.0000001) && (fabs(f(b)) > 0.0000001) && (b - a) >= 0.000001) {
			if (f((a + b) / 2.0) * f(a) < 0) b = (a + b) / 2.0;
			else a = (a + b) / 2.0;
		}
		if (fabs(f(b)) <= 0.0000001) return b; else return a;
	}

}
int main() {
	printf("Nghiem 1 la: %lld\n", Nghiem(ham1, 0, 10));
	printf("Nghiem 2 la: %lld\n", Nghiem(ham2,1.0, 2.0));
	printf("Nghiem 3 la: %lld\n", Nghiem(ham3, 1.0, 2.0));
	return 0;
}