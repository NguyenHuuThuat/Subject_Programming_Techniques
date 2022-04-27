#include<stdio.h>
#include<math.h>

double ham1(double x) {
	return (x * x * x * x * x - 29 * x * x * x * x - 24 * x * x * x + 9 * x * x + 99 * x + 1999);
}
//double ham2(double x) {
//	return (pow(2, x) + x - 4);
//}
///*double ham3(double x) {
//	return (x * x * x + x - 5);
//}*/
//double ham4(double x) {
//	return(log(x * x * x + 3 * x - 5) + 1);
//}
//double ham5(double x) {
//	return(sin(x) * sin(x) - cos(x) * cos(x) * cos(x));
//}
double nghiem(double (*f)(double x), double a, double b, double eps) {
	int count = 0;
	if (f(a) * f(b) > 0) {
		printf("Ham khong doi dau tren [a,b]\n");
		system("pause");
		return -1;
	}
	else {
		while ((fabs(f(a)) > eps) && (fabs(f(b)) > eps) && (b - a >= eps)) {
			count++;
			if (f((a + b) / 2.0) * f(a) < 0) {
				b = (a + b) / 2.0;
				printf("%lf      ", a);
				printf("%lf      ", b);
				printf("%lf    ", b);
				printf("%lf\n", fabs(a - b));
			}
			else {
				a = (a + b) / 2;
				printf("%lf      ", a);
				printf("%lf      ", b);
				printf("%lf    ", a);
				printf("%.10lf\n", fabs(a - b));
			}
		}
		printf("\nso vong lap la:  %d\n\n", count);
		if (fabs(f(b)) <= eps) {
			return b;
		}
		else {
			return a;
		}
	}
}
int main() {
	double epsilon, a, b;
	printf("Nhap sai so muc tieu: ");
	scanf_s("%lf", &epsilon);
	printf("Nhap khoang phan ly (a,b): \n");
	printf("a= ");
	scanf_s("%lf", &a);
	printf("b= ");
	scanf_s("%lf", &b);
	printf("\n");
	printf("   a              b             x           |a-b|\n");
	printf("%lf\n\n", nghiem(ham1, a, b, epsilon)); 
	//printf("%lf\n\n", nghiem(ham2, a, b,epsilon));//a=1,b=2
	//printf("%lf\n\n", nghiem(ham3, a, b,epsilon));//a=1,b=2 BỎ!!!
	//printf("%lf\n\n", nghiem(ham4, a, b, epsilon));//a=1.2,b=2
	//printf("%lf\n\n", nghiem(ham5, a, b, epsilon));//a=0,b=1,defaul a=2,b=3


	return 0;
}