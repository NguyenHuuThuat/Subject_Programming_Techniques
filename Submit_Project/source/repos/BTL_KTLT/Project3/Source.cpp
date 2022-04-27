#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

/*Khai báo nguyên mẫu hàm*/
void nhap(int* n, double x[], double y[][20]);
void bangSaiPhanThuan(int n, double x[], double y[][20]);
void bangSaiPhanNghich(int n, double x[], double y[][20]);
void bangTyHieuThuan(int n, double x[], double y[][20]);
void bangTyHieuNghich(int n, double x[], double y[][20]);
void newtonTienMocBatKy(int n, double x[], double y[][20]);
void newtonLuiMocBatKy(int n, double x[], double y[][20]);
double giaiThua(int n);
void newtonTienMocCachDeu(int n, double x[], double y[][20]);
void newtonLuiMocCachDeu(int n, double x[], double y[][20]);
void ghifile();

void test(int n, double x[], double  y[][20]);
void cpArr(double* x, double* y, int n);
void printArr(double* x, int n);
void mulConstArr(double* x, double _cons, int len);
/*Chương trình chính*/
char mangIn[1000];

int main() {
	int n;
	double x[20];
	double y[20][20];

	for (int i = 0; i < 1000; i++) {
		mangIn[i] = 0;
	}

	nhap(&n, x, y);
	//ghifile();
	//ghiFile(*x, y[20][20]);
	//bangSaiPhanThuan(n, x, y);
	bangTyHieuThuan(n, x, y);
	//bangSaiPhanNghich(n, x, y);
	//bangTyHieuNghich(n, x, y);
	newtonTienMocBatKy(n, x, y);
	//newtonLuiMocBatKy(n, x, y);
	//newtonTienMocCachDeu(n, x, y);
	test(n, x, y);
	//newtonLuiMocCachDeu(n, x, y);
	//ghifile(n, x, y);




	return 0;
}

/*Hàm nhập mốc các điểm và hiển thị dưới dạng bảng*/
void nhap(int* n, double x[], double y[][20]) {
	int i;

	printf("  Nhap so diem moc (so cap (x,y)) : \n");
	scanf("%d", n);
	printf("  Nhap vao du lieu: \n");
	for (i = 0; i < *n; i++) {
		printf("  x[%d] = \n", i);
		scanf("%lf", &x[i]);
		printf("  y[%d] = \n", i);
		scanf("%lf", &y[i][0]);
	}
	//*n = 5;
	//x[0] = 0;
	//x[1] = 2;
	//x[2] = 4;
	//x[3] = 5;
	//x[4] = 7;

	//y[0][0] = 1;
	//y[1][0] = 3;
	//y[2][0] = 2;
	//y[3][0] = 5;
	//y[4][0] = 6;




	printf("  Bang cac moc noi suy da nhap la: \n");
	sprintf(mangIn, "%s  Bang cac moc noi suy da nhap la: \n ", mangIn);
	printf("\tx");
	sprintf(mangIn,"%s\tx",mangIn);

	for (i = 0; i < *n; i++) {
		printf("%10.3lf", x[i]);
		sprintf(mangIn,"%s%10.3lf",mangIn, x[i]);

	}
	printf("\n		_________________________________________________________");
	sprintf(mangIn,"%s\n		_________________________________________________________",mangIn);

	printf("\n\ty");
	sprintf(mangIn,"%s\n\ty",mangIn);

	for (i = 0; i < *n; i++) {
		printf("%10.3lf", y[i][0]);
		sprintf(mangIn,"%s%10.3lf",mangIn, y[i][0]);

	}
}

/*Hàm lập bảng sai phân thuận*/
void bangSaiPhanThuan(int n, double x[], double y[][20]) {
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
		}
	}
	printf("\nBang sai phan la: \n");
	printf("\n\t x\t Y");
	for (k = 0; k <= n - 2; k++) {
		printf("\t Y^%d", k + 1);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("\t%0.2lf", x[i]);
		for (j = 0; j < n - i; j++)
		{
			printf("\t%0.2lf", y[i][j]);
		}
		printf("\n");
	}
}

/*Hàm lập bảng tỷ hiệu thuận*/
void bangTyHieuThuan(int n, double x[], double y[][20]) {
	int i, j, k;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[i + j] - x[j]);
		}
	}
	printf("\n\nBang ty hieu la: \n");
	printf("\n\t x\t Y");
	for (k = 0; k <= n - 2; k++) {
		printf("\t T^%d", k + 1);
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("\t%0.2lf", x[i]);
		for (j = 0; j < n - i; j++)
		{
			printf("\t%0.2lf", y[i][j]);
		}
		printf("\n");
	}
}

/*Hàm lập bảng sai phân nghịch*/
void bangSaiPhanNghich(int n, double x[], double y[][20]) {
	int i, j, k;
	for (i = 1; i < n; i++) {
		for (j = n - 1; j > (i - 1); j--) {
			y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
		}
	}
	printf("\nBang sai phan NGHICH la: \n");
	printf("\n\t x\t Y");
	for (k = 0; k <= n - 2; k++) {
		printf("\t Y^%d", k + 1);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("\t%0.2lf", x[i]);
		for (j = 0; j <= i; j++)
		{
			printf("\t%0.2lf", y[i][j]);
		}
		printf("\n");
	}
}

/*Hàm lập bảng tỷ hiệu nghịch*/
void bangTyHieuNghich(int n, double x[], double y[][20]) {
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		for (j = n; j >= i; j--) {
			y[j][i] = (y[j][i - 1] - y[j - 1][i - 1]) / (x[j] - x[j - i]);
		}
	}
	printf("\n\nBang ty hieu NGHICH la: \n");
	printf("\n\t x\t Y");
	for (k = 0; k <= n - 2; k++) {
		printf("\t T^%d", k + 1);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("\t%0.2lf", x[i]);
		for (j = 0; j <= i; j++)
		{
			printf("\t%0.2lf", y[i][j]);
		}
		printf("\n");
	}


}

/*Hàm hiển thị đa thức nội suy Newton tiến với mốc bất kỳ*/
void newtonTienMocBatKy(int n, double x[], double y[][20]) {
	int i, j;

	printf("\nDa thuc noi suy Newton tien moc bat ky la: \n");
	printf("P(x) = ");
	for (i = 0; i < n; i++) {
		if (i == 0) {
			if (y[0][1] >= 0) {
				printf("%.4lf + ", y[0][0]);
			}
			else {
				printf("%.4lf - ", y[0][0]);
			}
		}
		else {
			printf("%.4lf", y[0][i]);
			for (j = 0; j < i; j++) {
				if (x[j] < 0) {
					printf("(x + %.4lf)", -x[j]);
				}
				else  if (x[j] > 0) {
					printf("(x - %.4lf)", x[j]);
				}
				else {
					printf("x");
				}
			}
			if (i != n - 1) {
				if (y[0][i + 1] >= 0) {
					printf(" + ");
				}
			}
		}

	}

}

/*Hàm hiển thị đa thức nội suy Newton lùi với mốc bất kỳ*/
void newtonLuiMocBatKy(int n, double x[], double y[][20]) {
	int i, j;

	printf("\nDa thuc noi suy Newton lui voi moc bat ky la: \n");
	printf("P(x) = ");
	for (i = n; i > 0; i--) {
		if (i == n) {
			if (y[n - 1][1] >= 0) {
				printf("%.2lf + ", y[n - 1][0]);
			}
			else {
				printf("%.2lf - ", -y[n - 1][0]);
			}
		}
		else {
			printf("%.2lf", y[n - 1][n - i]);
			for (j = n; j > i; j--) {
				if (x[j - 1] < 0) {
					printf("(x + %.2lf)", -x[j - 1]);
				}
				else  if (x[j - 1] > 0) {
					printf("(x - %.2lf)", x[j - 1]);
				}
				else {
					printf("x");
				}
			}
			if (i != n - 1) {
				if (y[n - 1][i + 1] >= 0) {
					printf(" + ");
				}
			}
		}

	}

}

/*Hàm tính giai thừa*/
double giaiThua(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return n * giaiThua(n - 1);
}

/*Hàm hiển thị đa thức nội suy Newton tiến với mốc cách đều*/
void newtonTienMocCachDeu(int n, double x[], double y[][20]) {
	int i, j;
	double denta = x[1] - x[0];

	printf("\nDa thuc Newton tien moc cach deu la: \n");
	printf("P(x) = ");
	for (i = 0; i < n; i++) {
		if (i == 0) {
			if ((y[0][1]) / (giaiThua(i) * pow(denta, i)) >= 0) {
				printf("%.2lf + ", y[0][0]);
			}
			else {
				printf("%.2lf - ", y[0][0]);
			}
		}
		else {
			printf("%.2lf", (y[0][i]) / (giaiThua(i) * pow(denta, i)));
			for (j = 0; j < i; j++) {
				if (x[j] < 0) {
					printf("(x + %.2lf)", -x[j]);
				}
				else  if (x[j] > 0) {
					printf("(x - %.2lf)", x[j]);
				}
				else {
					printf("x");
				}
			}
			if (i != n - 1) {
				if (y[0][i + 1] >= 0) {
					printf(" + ");
				}
			}
		}

	}
}

/*Hàm hiển thị đa thức nội suy Newton lùi với mốc cách đều*/
void newtonLuiMocCachDeu(int n, double x[], double y[][20]) {
	int i, j;
	double denta = x[1] - x[0];

	printf("\nDa thuc Newton lui moc cach deu la: \n");
	printf("P(x) = ");
	for (i = n; i > 0; i--) {
		if (i == n) {
			if ((y[n - 1][1]) / (giaiThua(i) * pow(denta, i)) >= 0) {
				printf("%.2lf + ", y[n - 1][0]);
			}
			else {
				printf("%.2lf - ", y[n - 1][0]);
			}
		}
		else {
			printf("%.2lf", (y[n - 1][n - i]) / (giaiThua(n - i) * pow(denta, ((double)n - i))));
			for (j = n; j > i; j--) {
				if (x[j - 1] < 0) {
					printf("(x + %.2lf)", -x[j - 1]);
				}
				else  if (x[j - 1] > 0) {
					printf("(x - %.2lf)", x[j - 1]);
				}
				else {
					printf("x");
				}
			}
			if (i != n - 1) {
				if (y[0][i + 1] >= 0) {
					printf(" + ");
				}
			}
		}

	}
}


/*Hàm ghi FILE*/
void ghifile() {
	FILE* fout = fopen("newton.txt", "a");
	fprintf(fout, mangIn);

	fclose(fout);
}

void test(int n, double x[], double  y[][20]) {
	double** mangMu = NULL;
	double* tmpMangMu = NULL;

	/*Cấp phát bộ nhớ động cho mảng tmpMangMu*/	
	tmpMangMu = (double*)malloc((n) * sizeof(double));

	/*Cấp phát bộ nhớ động cho mảng 2 chiều mangMu*/
	mangMu = (double **)malloc(n * sizeof(double*));
	for (int i = 0; i < n; i++)
	{
		mangMu[i] = (double*)malloc((n) * sizeof(double));
	}

	/*Gán tất cả phần tử trong ma trận mangMu bằng 0*/
	for (int i = 0; i < n; i++)
	{
		for (int  j = 0; j < n; j++)
		{
			mangMu[i][j] = 0;
		}
	}
	/*tính hệ số của từng đa thức*/
	for (int i = 0; i < n; i++)
	{
		if (i == 0) { /*Hàng đầu tiên của ma trận*/
			mangMu[0][0] = y[0][0];
			printArr(mangMu[i], n);
			continue; //không thực hiện lệnh ở dưới, nhảy lại vòng for chính
		}
		if (i == 1) { 
			mangMu[i][0] = -x[0]; //hệ số tự do
			mangMu[i][1] = 1;//hệ số bậc nhất của đa thức thứ nhất
			cpArr(tmpMangMu, mangMu[i], n); //coppy hệ số ra 1 mảng tạm
			mulConstArr(mangMu[i], y[0][i], n );//lấy mảng gốc nhân với Y1
			printArr(mangMu[i], n); //in toàn bộ hàng 1
			continue;
		}
		for (int ii = 0; ii < i+1; ii++)//chạy bậc của đa thức trước khi vào vòng for
		{
			for (int  iii = 0; iii < 2; iii++)//đa thức nhân tiếp theo luôn luôn có dạng x + a => có bậc 0, 1
			{
				if (iii == 0) {

					mangMu[i][iii + ii] = mangMu[i][iii + ii] - tmpMangMu[ii] * x[i - 1];
				}
				else {
					mangMu[i][iii + ii] = mangMu[i][iii + ii] + tmpMangMu[ii] * 1;
				}
			}

		}
		//printArr(mangMu[i], n);
		cpArr(tmpMangMu, mangMu[i], n);
		mulConstArr(mangMu[i], y[0][i], n);
		printArr(mangMu[i], n);

	}

	//cộng các cột của ma trận với nhau ra hệ số của các toán hạng của đa thức
	for (int i = 0; i < n; i++)
	{
		tmpMangMu[i] = 0;
		for (int j = 0; j < n; j++)
		{
			tmpMangMu[i] = tmpMangMu[i] + mangMu[j][i];
		}
		printf("\nMu %i : %lf", i, tmpMangMu[i]);
	}

}

/*hàm coppy mảng */
void cpArr(double* x, double* y, int n) {
	for (int i = 0; i < n; i++)
	{
		x[i] = y[i];
	}
}

/*Nhân các giá trị của mảng với 1 hằng số*/
void mulConstArr(double* x, double _cons, int len){
	for (int i = 0; i < len; i++)
	{
		x[i] = _cons * x[i];
	}
}
void printArr(double* x, int n) {
	printf("\n");
	for (int  i = 0; i < n; i++)
	{
		printf("%lf \t", x[i]);

	}
}