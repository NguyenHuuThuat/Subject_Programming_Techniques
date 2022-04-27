#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define SO_MOC_LON_NHAT 20
/*Khai báo nguyên mẫu hàm*/
void nhap(int* n, double x[], double y[][SO_MOC_LON_NHAT]);
/*câu a*/
void bangSaiPhanThuan(int n, double x[], double y[][SO_MOC_LON_NHAT]);
void bangSaiPhanNghich(int n, double x[], double y[][SO_MOC_LON_NHAT]);
void bangTyHieuThuan(int n, double x[], double y[][SO_MOC_LON_NHAT]);
void bangTyHieuNghich(int n, double x[], double y[][SO_MOC_LON_NHAT]);
/*Câu b*/
void newtonTienMocBatKy(int n, double x[], double y[][SO_MOC_LON_NHAT]);
void newtonLuiMocBatKy(int n, double x[], double y[][SO_MOC_LON_NHAT]);
void newtonTienMocCachDeu(int n, double x[], double y[][SO_MOC_LON_NHAT]);
void newtonLuiMocCachDeu(int n, double x[], double y[][SO_MOC_LON_NHAT]);
/*câu c*/
double* heSoNewtonTienMocBatKy(int n, double x[], double  y[][SO_MOC_LON_NHAT]);
double* heSoNewtonTienMocCachDeu(int n, double x[], double  y[][SO_MOC_LON_NHAT]);
double* heSoNewtonLuiMocBatKy(int n, double x[], double  y[][SO_MOC_LON_NHAT]);
double* heSoNewtonLuiMocCachDeu(int n, double x[], double  y[][SO_MOC_LON_NHAT]);

void hoocle(double arr[], int n);
/*Hàm bổ trợ*/
double giaiThua(int n);
void cpMang(double* x, double* y, int n);
void nhanHeSo(double* x, double p, int n);
void inMangMotChieu(double* x, int n);
//void ghifile(int n, double x[], double  y[][SO_MOC_LON_NHAT]);

/*Chương trình chính*/
int main() {
	int n;
	double* arr;
	double x[SO_MOC_LON_NHAT];
	double y[SO_MOC_LON_NHAT][SO_MOC_LON_NHAT];

	nhap(&n, x, y);
	/*Câu a*/
	//bangSaiPhanThuan(n, x, y);
	bangTyHieuThuan(n, x, y);
	//bangSaiPhanNghich(n, x, y);
	//bangTyHieuNghich(n, x, y);
	/*câu b*/
	newtonTienMocBatKy(n, x, y);
	//newtonLuiMocBatKy(n, x, y);
	//newtonTienMocCachDeu(n, x, y);
	//newtonLuiMocCachDeu(n, x, y);
	/*Câu c*/
	heSoNewtonTienMocBatKy(n, x, y);
	//heSoNewtonTienMocCachDeu(n, x, y);
	//heSoNewtonLuiMocBatKy(n, x, y);
	//heSoNewtonLuiMocCachDeu(n, x, y);
	//ghifile(n, x, y);
	//ghiFile(*x, y[SO_MOC_LON_NHAT][SO_MOC_LON_NHAT]);

	arr = heSoNewtonTienMocBatKy(n, x, y);

	hoocle(arr, n);

	return 0;
}

/*Hàm nhập mốc các điểm và hiển thị dưới dạng bảng*/
void nhap(int* n, double x[], double y[][SO_MOC_LON_NHAT]) {
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

/*Hàm lập bảng sai phân thuận*/
void bangSaiPhanThuan(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
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
void bangTyHieuThuan(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
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
void bangSaiPhanNghich(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
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
void bangTyHieuNghich(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
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
void newtonTienMocBatKy(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
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

/*Hàm hiển thị đa thức nội suy Newton lùi với mốc bất kỳ*/
void newtonLuiMocBatKy(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
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
			if (i != 1) {
				if (y[n - 1][i - 1] >= 0) {
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
void newtonTienMocCachDeu(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
	int i, j;
	double denta = x[1] - x[0];

	printf("\nDa thuc Newton tien moc cach deu la: \n");
	printf("P(x) = ");
	for (i = 0; i < n; i++) {
		if (i == 0) {
			if ((y[0][1]) >= 0) {
				printf("%.2lf + ", y[0][0]);
			}
			else {
				printf("%.2lf  ", y[0][0]);
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

/*Hàm hiển thị đa thức nội suy Newton lùi với mốc bất kỳ*/
void newtonLuiMocCachDeu(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
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
			if (i != 1) {
				if (y[n - 1][i - 1] >= 0) {
					printf(" + ");
				}
			}
		}
	}
}

/*Hàm tìm hệ số của các bậc của đa thức Neton tiến mốc bất kỳ*/
double* heSoNewtonTienMocBatKy(int n, double x[], double  y[][SO_MOC_LON_NHAT]) {
	double** mangMu = NULL;  //Ma trận lưu hệ số của các đa thức trong quá trình tính toán
	double* tmpMangMu = NULL; //Mảng lưu hệ số tạm thời của đa thức
	int i, j, ii, iii;


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
	for (i = 0; i < n; i++)
	{
		free(mangMu[i]);
	}
	free(mangMu);

	printf("\nHe so mu cua da thuc la: \n");
	for (int i = 0; i < n; i++)
	{
		printf("\nMu %i : %lf", i, tmpMangMu[i]);
	}
	return tmpMangMu;
}

/*Hàm tìm hệ số của các bậc của đa thức Neton tiến mốc cách đều*/
double* heSoNewtonTienMocCachDeu(int n, double x[], double  y[][SO_MOC_LON_NHAT]) {
	double** mangMu = NULL;  //Ma trận lưu hệ số của các đa thức trong quá trình tính toán
	double* tmpMangMu = NULL; //Mảng lưu hệ số tạm thời của đa thức
	int i, j, ii, iii;
	double denta = x[1] - x[0];


	/*Cấp phát bộ nhớ động cho mảng tmpMangMu*/
	tmpMangMu = (double*)malloc(n * sizeof(double));

	/*Cấp phát bộ nhớ động cho mảng 2 chiều mangMu*/
	mangMu = (double**)malloc(n * sizeof(double*));
	printf("\n\nMa tran he so la: \n");
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
	/*Trường hợp cơ sở*/
	for (i = 0; i < n; i++) {
		if (i == 0) {     //hàng đầu của ma trận
			mangMu[0][0] = y[0][0];
			inMangMotChieu(mangMu[i], n);
			continue;
		}
		if (i == 1) {    //hàng thứ 2 của ma trận
			mangMu[i][0] = -x[0];
			mangMu[i][1] = 1;
			cpMang(tmpMangMu, mangMu[i], n); //coppy mangMu[i] => tmpMangMu
			nhanHeSo(mangMu[i], (y[0][i] / denta), n); //nhân trả hệ số sau khi đã sao chép mảng "cố định" ra mảng tạm
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
		nhanHeSo(mangMu[i], (y[0][i]) / (giaiThua(i) * pow(denta, i)), n);
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
	for (i = 0; i < n; i++)
	{
		free(mangMu[i]);
	}
	free(mangMu);
	printf("\nHe so mu cua da thuc la: \n");
	for (int i = 0; i < n; i++)
	{
		printf("\nMu %i : %lf", i, tmpMangMu[i]);
	}
	return tmpMangMu;
}

/*Hàm tìm hệ số của các bậc của đa thức Neton tiến mốc bất kỳ*/
double* heSoNewtonLuiMocBatKy(int n, double x[], double  y[][SO_MOC_LON_NHAT]) {
	double** mangMu = NULL;  //Ma trận lưu hệ số của các đa thức trong quá trình tính toán
	double* tmpMangMu = NULL; //Mảng lưu hệ số tạm thời của đa thức
	int i, j, ii, iii;


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
	for (i = n - 1; i >= 0; i--) {
		/*Trường hợp cơ sở*/
		if (i == n - 1) {     //hàng đầu của ma trận
			mangMu[n - i - 1][0] = y[n - 1][0];
			inMangMotChieu(mangMu[n - i - 1], n);
			continue;
		}
		if (i == n - 2) {    //hàng thứ 2 của ma trận
			mangMu[n - i - 1][0] = -x[n - 1];
			mangMu[n - i - 1][1] = 1;
			cpMang(tmpMangMu, mangMu[n - i - 1], n); //coppy mangMu[i] => tmpMangMu
			nhanHeSo(mangMu[n - i - 1], y[n - 1][n - i - 1], n); //nhân trả hệ số sau khi đã sao chép mảng "cố định" ra mảng tạm
			inMangMotChieu(mangMu[n - i - 1], n);
			continue;
		}
		/*Trường hợp tổng quát*/
		for (ii = 0; ii < n - i; ii++) {  //mũ của đa thức đầu vào vòng for không lớn hơn mũ của các đa thức đã xét
			for (iii = 0; iii < 2; iii++) {    //đa thức nhân tiếp theo luôn luôn có dạng x + a => có bậc 0, 1
				if (iii == 0) {
					mangMu[n - i - 1][iii + ii] = mangMu[n - i - 1][iii + ii] - tmpMangMu[ii] * x[i + 1];
				}
				else {
					mangMu[n - i - 1][iii + ii] = mangMu[n - i - 1][iii + ii] + tmpMangMu[ii] * 1;
				}
			}
		}
		cpMang(tmpMangMu, mangMu[n - i - 1], n);
		nhanHeSo(mangMu[n - i - 1], y[n - 1][n - i - 1], n);
		inMangMotChieu(mangMu[n - i - 1], n);
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
	for (i = 0; i < n; i++)
	{
		free(mangMu[i]);
	}
	free(mangMu);

	printf("\nHe so mu cua da thuc la: \n");
	for (int i = 0; i < n; i++)
	{
		printf("\nMu %i : %lf", i, tmpMangMu[i]);
	}
	return tmpMangMu;
}
/*Hàm tìm hệ số của các bậc của đa thức Neton lùi mốc cách đều*/
double* heSoNewtonLuiMocCachDeu(int n, double x[], double  y[][SO_MOC_LON_NHAT]) {
	double** mangMu = NULL;  //Ma trận lưu hệ số của các đa thức trong quá trình tính toán
	double* tmpMangMu = NULL; //Mảng lưu hệ số tạm thời của đa thức
	int i, j, ii, iii;
	double denta = x[1] - x[0];


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
	for (i = n - 1; i >= 0; i--) {
		/*Trường hợp cơ sở*/
		if (i == n - 1) {     //hàng đầu của ma trận
			mangMu[n - i - 1][0] = y[n - 1][0];
			inMangMotChieu(mangMu[n - i - 1], n);
			continue;
		}
		if (i == n - 2) {    //hàng thứ 2 của ma trận
			mangMu[n - i - 1][0] = -x[n - 1];
			mangMu[n - i - 1][1] = 1;
			cpMang(tmpMangMu, mangMu[n - i - 1], n); //coppy mangMu[i] => tmpMangMu
			nhanHeSo(mangMu[n - i - 1], (y[n - 1][n - i - 1] / denta), n); //nhân trả hệ số sau khi đã sao chép mảng "cố định" ra mảng tạm
			inMangMotChieu(mangMu[n - i - 1], n);
			continue;
		}
		/*Trường hợp tổng quát*/
		for (ii = 0; ii < n - i; ii++) {  //mũ của đa thức đầu vào vòng for không lớn hơn mũ của các đa thức đã xét
			for (iii = 0; iii < 2; iii++) {    //đa thức nhân tiếp theo luôn luôn có dạng x + a => có bậc 0, 1
				if (iii == 0) {
					mangMu[n - i - 1][iii + ii] = mangMu[n - i - 1][iii + ii] - tmpMangMu[ii] * x[i + 1];
				}
				else {
					mangMu[n - i - 1][iii + ii] = mangMu[n - i - 1][iii + ii] + tmpMangMu[ii] * 1;
				}
			}
		}
		cpMang(tmpMangMu, mangMu[n - i - 1], n);
		nhanHeSo(mangMu[n - i - 1], (y[n - 1][n - i - 1]) / (giaiThua(n - i - 1) * pow(denta, (double(n) - i - 1))), n);
		inMangMotChieu(mangMu[n - i - 1], n);
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
	for (i = 0; i < n; i++)
	{
		free(mangMu[i]);
	}
	free(mangMu);

	printf("\nHe so mu cua da thuc la: \n");
	for (int i = 0; i < n; i++)
	{
		printf("\nMu %i : %lf", i, tmpMangMu[i]);
	}
	return tmpMangMu;
}



/*hàm coppy mảng */
void cpMang(double* x, double* y, int n) {
	int i;
	for (i = 0; i < n; i++) {
		x[i] = y[i];
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

//hoccne
void hoocle(double arr[], int n) {
	double p = 0;
	float c;
	int i;
	double* mangKQ = NULL;
	mangKQ = (double*)malloc(n * sizeof(double));

	printf("\nNhap gia tri can tinh : \n");
	scanf(" %f", &c);

	for (i = 0; i < n; i++) {
		printf("%16.4lf", arr[n - i - 1]);
	}

	p = arr[n - 1];
	mangKQ[0] = p;
	printf("\n                 ");
	for (i = 1; i < n; i++) {
		printf("%16.4lf ", p * c);
		p = p * c + arr[n - i - 1]; //n-2 -> 0
		mangKQ[i] = p;
	}
	printf("\n-------------------------------------------------------------------\n");
	for (i = 0; i < n; i++) {
		printf("%16.4lf ", mangKQ[i]);
	}
	free(mangKQ);
	printf("\nGia tri cua da thuc tai c la: f(c) = %lf", p);


}


