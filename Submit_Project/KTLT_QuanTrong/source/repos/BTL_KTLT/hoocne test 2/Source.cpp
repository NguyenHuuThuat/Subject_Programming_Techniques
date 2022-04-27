#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

/*Khai báo nguyên mẫu hàm*/
void nhap(int* n, double x[], double y[][20]);
void bangTyHieuThuan(int n, double x[], double y[][20]);
void newtonTienMocBatKy(int n, double x[], double y[][20]);
double* heSoNewtonTienMocBatKy(int n, double x[], double  y[][20]);
double giaiThua(int n);
void cpMang(double* x, double* y, int n);
void nhanHeSo(double* x, double p, int n);
void inMangMotChieu(double* x, int n);

int main() {
	int i, n;
	double* arr;
	double x[20];
	double y[20][20];

	nhap(&n, x, y);
	/*Câu a*/
	bangTyHieuThuan(n, x, y);
	/*câu b*/
	newtonTienMocBatKy(n, x, y);
	/*Câu c*/
	arr = heSoNewtonTienMocBatKy(n, x, y);
	printf("AAAAAAAAAAAAAA\n");
	for (i = 0; i < n; i++) {
		printf("%lf\t", arr[i]);
	}
	
	


	return 0;
}

/*hàm coppy mảng */
void cpMang(double* x, double* y, int n) {
	int i;
	for (i = 0; i < n; i++) {
		x[i] = y[i];
	}
}
void nhap(int* n, double x[], double y[][20]) {
	int i;
	*n = 0;

	printf("  Nhap so diem moc (so cap (x,y)) : \n");
	while (*n < 2) {
		printf("Chu y: n > 1 :\n");
		scanf("%d", n);
	}
	printf("  Nhap vao du lieu: \n");
	for (i = 0; i < *n; i++) {
		printf("  x[%d] = \n", i);
		scanf("%lf", &x[i]);
		printf("  y[%d] = \n", i);
		scanf("%lf", &y[i][0]);
	}
	printf("  Bang cac moc noi suy da nhap la: \n");
	printf("\tx");
	for (i = 0; i < *n; i++) {
		printf("%10.3lf", x[i]);
	}
	printf("\n   _________________________________________________________");
	printf("\n\ty");
	for (i = 0; i < *n; i++) {
		printf("%10.3lf", y[i][0]);
	}
}

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

void newtonTienMocBatKy(int n, double x[], double y[][20]) {
	int i, j;

	printf("\nDa thuc noi suy Newton tien moc bat ky la: \n");
	printf("P(x) = ");
	for (i = 0; i < n; i++) {
		if (i == 0) {
			if (y[0][1] >= 0) {
				printf("%.2lf + ", y[0][0]);
			}
			else {
				printf("%.2lf - ", y[0][0]);
			}
		}
		else {
			printf("%.2lf", y[0][i]);
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
//hàm nhân 1 số vào mảng
void nhanHeSo(double* x, double p, int n) {
	int i;
	for (i = 0; i < n; i++) {
		x[i] = p * x[i];
	}
}

//hàm in mảng
void inMangMotChieu(double* x, int n) {
	int i;

	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%lf\t", x[i]);
	}
}



double * heSoNewtonTienMocBatKy(int n, double x[], double  y[][20]) {
	double** mangMu = NULL;  //Ma trận lưu hệ số của các đa thức trong quá trình tính toán
	double* tmpMangMu = NULL; //Mảng lưu hệ số tạm thời của đa thức
	int i, j, ii, iii;
	double static r[100];
	/*Cấp phát bộ nhớ động cho mảng tmpMangMu*/
	tmpMangMu = (double*)malloc(n * sizeof(double));

	/*Cấp phát bộ nhớ động cho mảng 2 chiều mangMu*/
	mangMu = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++) {
		mangMu[i] = (double*)malloc(n * sizeof(double));
	}

	/*Gán tất cả phần tử trong ma trận mangMu bằng 0*/
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			mangMu[i][j] = 0;
		}
	}

	/*kết thúc khởi tạo, bắt đầu tính hệ số của từng đa thức*/
	printf("\n\nMa tran he so la: \n");
	for (i = 0; i < n; i++) {
		/*Trường hợp cơ sở*/
		if (i == 0) {     //hàng đầu của ma trận
			mangMu[0][0] = y[0][0];
			inMangMotChieu(mangMu[i], n);
			continue;
		}
		if (i == 1) {    //hàng thứ 2 của ma trận
			mangMu[i][0] = -x[0];
			mangMu[i][1] = 1;
			cpMang(tmpMangMu, mangMu[i], n); //coppy mangMu[i] => tmpMangMu
			nhanHeSo(mangMu[i], y[0][i], n); //nhân trả hệ số sau khi đã sao chép mảng "cố định" ra mảng tạm
			inMangMotChieu(mangMu[i], n);
			continue;
		}
		/*Trường hợp tổng quát*/
		for (ii = 0; ii < i + 1; ii++) {  //mũ của đa thức đầu vào vòng for không lớn hơn mũ của các đa thức đã xét
			for (iii = 0; iii < 2; iii++) {    //đa thức nhân tiếp theo luôn luôn có dạng x + a => có bậc 0, 1
				if (iii == 0) {
					mangMu[i][iii + ii] = mangMu[i][iii + ii] - tmpMangMu[ii] * x[i - 1];
				}
				else {
					mangMu[i][iii + ii] = mangMu[i][iii + ii] + tmpMangMu[ii] * 1;
				}
			}
		}
		cpMang(tmpMangMu, mangMu[i], n);
		nhanHeSo(mangMu[i], y[0][i], n);
		inMangMotChieu(mangMu[i], n);
	}
	//In kết quả. cộng các cột của ma trận với nhau ra hệ số của các toán hạng của đa thức
	for (int i = 0; i < n; i++)
	{
		tmpMangMu[i] = 0;
		for (int j = 0; j < n; j++)
		{
			tmpMangMu[i] = tmpMangMu[i] + mangMu[j][i];
		}
	}
	// giải phóng bộ nhớ mảng mũ
	for ( i = 0; i < n; i++)
	{
		free(mangMu[i]);
	}
	free(mangMu);

	printf("\nHe so mu cua da thuc la: \n");
	for (int i = 0; i < n; i++)
	{
		printf("\nMu %i : %lf", i, tmpMangMu[i]);
	}

	for (i = 0; i < n; i++) {
		r[i] = tmpMangMu[i];
	}

	return tmpMangMu;
}

