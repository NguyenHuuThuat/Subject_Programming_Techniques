#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<Windows.h>

#define SO_MOC_LON_NHAT 20
#define NUMBER_ITEM 9
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
void ghifile1(int* n, double x[], double  y[][20]);
void ghifile2(int n, double x[], double  y[][20]);
void ghifile3(int n, double x[], double  y[][20]);
void ghifile4(int n, double x[], double  y[][20]);
void ghifile5(int n, double x[], double  y[][20]);

/*Tạo menu*/
void veMenu(int selectedItem);

/*Chương trình chính*/
int main() {
	int n;
	int h, flat;
	int havechange[8];
	double* arr;
	double x[SO_MOC_LON_NHAT];
	double y[SO_MOC_LON_NHAT][SO_MOC_LON_NHAT];

	//Lựa chọn bằng menu
	int i = 0, select = 0;

	char press = ' ', isQuit = '1';
	while (1)
	{
		veMenu(select);
		press = getch();
		switch (press)
		{
		case 72:
			//press mũi tên lên
			select--;
			if (select < 0) select = 0;
			break;
		case 80:
			//press mũi tên xuống
			select++;
			if (select > 8) select = 8;
			break;
		case 13:
			//press Enter
			printf("\nDa chon %d", select);
			//Do something
			switch (select)
			{
			case 0:
				ClearFile();
				printf("\n Da xoa du lieu trong file newton.txt !")
					break;
			case 1:
				//item 1
				nhap(&n, x, y);
				havechange[1] = 1;
				printf("\n *. Neu la moc cach deu chon Item 3 de in bang sai phan thuan !");
				printf("\n *. Neu la moc khong cach deu chon Item 2 de in bang ty hieu thuan !");

				break;
			case 2:
				//item 2
				if (havechange[1] != 1) {
					printf("\nBan chua nhap cac moc !");
				}
				else {
					bangTyHieuThuan(n, x, y);
					havechange[2] = 1;
					printf("\nCo the tiep tuc chon Item 4 ung voi truong hop bang ty hieu Thuan va In ngay da thuc noi suy newton tien moc bat ky !");
					printf("\nhoac Item 5 neu muon in lai bang ty hieu Nghich va In ngay da thuc noi suy newton lui moc bat ky !");
				}
				break;
			case 3:
				//item 3
				if (havechange[1] != 1) {
					printf("\nBan chua nhap cac moc !");
				}
				else {
					h = x[1] - x[0];
					for (int i = 1; i < n; i++)
					{
						if (h == x[i] - x[i - 1]) {
							flat = 1;
						}
						else
						{
							flat = 0;
							break;
						}
					}
					if (flat == 1) {
						bangSaiPhanThuan(n, x, y);
						havechange[3] = 1;
						printf("\nCo the tiep tuc chon Item 6 ung voi truong hop bang sai phan Thuan va In ngay da thuc noi suy newton tien moc cach deu !");
						printf("\nhoac Item 7 neu muon in lai bang sai phan Nghich va va In ngay da thuc noi suy newton lui moc cach deu !");
					}
					else {
						printf("\nKhong ve duoc bang sai phan, chi ve duoc bang ty hieu co the chon Item 2");
					}
				}
				break;
			case 4:
				//item 4
				if (havechange[2] == 1)
				{
					newtonTienMocBatKy(n, x, y);
					havechange[4] = 1;
					printf("\nTiep tuc chon Item 8 neu ban muon tinh gia tri cua da thuc tai 1 diem bang so do Hoocne !");
				}
				else
				{
					printf("\nChua co bang ty hieu, Chon Item 2 de thiet lap bang ty hieu !");
				}
				break;
			case 5:
				//item 5
				if (havechange[1] == 1)
				{
					bangTyHieuNghich(n, x, y);
					newtonLuiMocBatKy(n, x, y);
					havechange[5] = 1;
					printf("\nTiep tuc chon Item 8 neu ban muon tinh gia tri cua da thuc tai 1 diem bang so do Hoocne !");
				}
				else {
					printf("\nBan chua nhap cac moc !");
				}
				break;
			case 6:
				//item 6
				if (havechange[3] == 1)
				{
					newtonTienMocCachDeu(n, x, y);
					havechange[6] = 1;
					printf("\nTiep tuc chon Item 8 neu ban muon tinh gia tri cua da thuc tai 1 diem bang so do Hoocne !");
				}
				else {
					printf("\nChua co bang sai phan, Chon Item 3 de thiet lap bang sai phan !");
				}
				break;
			case 7:
				//item 7
				if (havechange[1] != 1) {
					printf("\nBan chua nhap cac moc !");
				}
				else {
					h = x[1] - x[0];
					for (int i = 1; i < n; i++)
					{
						if (h == x[i] - x[i - 1]) {
							flat = 1;
						}
						else
						{
							flat = 0;
							break;
						}
					}
					if (flat == 1) {
						bangSaiPhanNghich(n, x, y);
						newtonLuiMocCachDeu(n, x, y);
						havechange[7] = 1;
						printf("\nTiep tuc chon Item 8 neu ban muon tinh gia tri cua da thuc tai 1 diem bang so do Hoocne !");
					}
					else {
						printf("\nKhong ve duoc bang sai phan,  co the chon Item 5 !");
					}
				}
				break;
			case 8:
				//item 8
				if (havechange[4] == 1 || havechange[5] == 1 || havechange[6] == 1 || havechange[7] == 1)
				{
					if (havechange[4] == 1)
					{
						heSoNewtonTienMocBatKy(n, x, y);
						arr = heSoNewtonTienMocBatKy(n, x, y);
						hoocle(arr, n);
					}
					else if (havechange[5] == 1)
					{
						heSoNewtonLuiMocBatKy(n, x, y);
						arr = heSoNewtonLuiMocBatKy(n, x, y);
						hoocle(arr, n);
					}
					else if (havechange[6] == 1)
					{
						heSoNewtonTienMocCachDeu(n, x, y);
						arr = heSoNewtonTienMocCachDeu(n, x, y);
						hoocle(arr, n);
					}
					else if (havechange[7] == 1) {
						heSoNewtonLuiMocCachDeu(n, x, y);
						arr = heSoNewtonLuiMocCachDeu(n, x, y);
						hoocle(arr, n);
					}
				}
				else
				{
					printf("Chon Item 4 -> 7 de lap da thuc Newton !");
				}
				break;
			default:
				break;
			}
			printf("\nDo you want continue:\n0.No\n1.Yes\n");

			isQuit = getch();
			while (isQuit != '0' && isQuit != '1')
			{
				printf("Enter again!!!");
				isQuit = getch();
			}
			break;
		default:
			break;
		}

		if (isQuit == '0')
		{
			break;
		}
	}


	//nhap(&n, x, y);
	/*Câu a*/
	//bangSaiPhanThuan(n, x, y);
	//bangTyHieuThuan(n, x, y);
	//bangSaiPhanNghich(n, x, y);
	//bangTyHieuNghich(n, x, y);
	/*câu b*/
	//newtonTienMocBatKy(n, x, y);
	//newtonLuiMocBatKy(n, x, y);
	//newtonTienMocCachDeu(n, x, y);
	//newtonLuiMocCachDeu(n, x, y);
	/*Câu c*/
	//heSoNewtonTienMocBatKy(n, x, y);
	//heSoNewtonTienMocCachDeu(n, x, y);
	//heSoNewtonLuiMocBatKy(n, x, y);
	//heSoNewtonLuiMocCachDeu(n, x, y);
	//ghifile(n, x, y);
	//ghiFile(*x, y[SO_MOC_LON_NHAT][SO_MOC_LON_NHAT]);

	arr = heSoNewtonTienMocBatKy(n, x, y);

	//hoocle(arr, n);

	return 0;
}
//Tạo giao diện Menu

void veMenu(int selectedItem)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("   __________________________________________________________\n");
	printf("  |                           Menu:                          |\n");
	printf("   __________________________________________________________\n");

	int i = 0;
	for (i = 0; i < NUMBER_ITEM; i++)
	{
		if (i == (selectedItem) % NUMBER_ITEM)
		{
			printf("  |");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			printf("Item %d                                                    |\n", i);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			printf("  |");
			printf("Item %d                                                    |\n", i);
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("   __________________________________________________________\n");
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
	ghifile1(n, x, y);
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
	printf("\n\nBang sai phan la: \n");
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
	ghifile2(n, x, y);
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
	ghifile5(n, x, y);
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
	ghifile3(n, x, y);
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
	ghifile4(n, x, y);
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
	Indathuc1(n, x, y);

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
	Indathuc2(n, x, y);
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
	Indathuc3(n, x, y);
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
	Indathuc4(n, x, y);
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
	Indathuc5(n, tmpMangMu, mangMu);
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
	Indathuc5(n, tmpMangMu, mangMu);
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
	Indathuc5(n, tmpMangMu, mangMu);
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
		//nhanHeSo(mangMu[n - i - 1], (y[n - 1][n - i - 1]) / (giaiThua(n - i - 1) * pow(denta, (double(n) - i - 1))), n);
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
	Indathuc5(n, tmpMangMu, mangMu);
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
	ghifilehoocle(n, mangKQ, p, arr, &c);
	free(mangKQ);
	printf("\nGia tri cua da thuc tai c la: f(c) = %lf", p);


}

//ham ghi các bảng tỷ hiệu và sai phân file
void ghifile1(int* n, double x[], double  y[][20]) {
	int i, j;
	//ghi lai diem moc
	FILE* fout1 = fopen("newton.txt", "a");
	if (fout1 == NULL) {
		printf("Khong mo duoc file !");
	}
	else {
		fprintf(fout1, "Bang moc cac diem: \n");
		fprintf(fout1, "\n \t x");
		for (i = 0; i < *n; i++) {
			fprintf(fout1, "\t%lf", x[i]);
		}
		fprintf(fout1, "\n _____________________________________");
		fprintf(fout1, "\n \t y");
		for (j = 0; j < i; j++) {
			fprintf(fout1, "\t%lf", y[j][0]);
		}
	}
	fprintf(fout1, "\n\n");
	fclose(fout1);
}

void ghifile2(int n, double x[], double  y[][20]) {
	int i, j;
	//ghi lai bang sai phan thuan

	FILE* fout2 = fopen("newton.txt", "a");
	if (fout2 == NULL) {
		printf("Khong mo duoc file !");
	}
	fprintf(fout2, "Bang sai phan thuan: \n");
	fprintf(fout2, "\n \t X");
	fprintf(fout2, "\t Y");
	for (int i = 0; i < n - 1; i++)
	{
		fprintf(fout2, "\t Y^%d", i + 1);
	}
	fprintf(fout2, "\n      ___________________________________");
	for (int i = 0; i < n; i++) {
		fprintf(fout2, "\n \t %0.2lf", x[i]);

		for (int k = 0; k < n - i; k++) {
			fprintf(fout2, "\t %0.2lf", y[i][k]);
		}
	}
	fprintf(fout2, "\n\n");
	fclose(fout2);
}


void ghifile3(int n, double x[], double  y[][20]) {
	int i, j;
	//ghi lai bang sai phan nghich

	FILE* fout3 = fopen("newton.txt", "a");
	if (fout3 == NULL) {
		printf("Khong mo duoc file !");
	}
	fprintf(fout3, "Bang sai phan nghich: \n");
	fprintf(fout3, "\n \t X");
	fprintf(fout3, "\t Y");
	for (int i = 0; i < n - 1; i++)
	{
		fprintf(fout3, "\t Y^%d", i + 1);
	}
	fprintf(fout3, "\n      ___________________________________");
	for (int i = 0; i < n; i++) {
		fprintf(fout3, "\n \t %0.2lf", x[i]);

		for (int k = 0; k <= i; k++) {
			fprintf(fout3, "\t %0.2lf", y[i][k]);
		}
	}
	fprintf(fout3, "\n\n");
	fclose(fout3);
}

void ghifile4(int n, double x[], double  y[][20]) {
	int i, j;
	//ghi lai bang ty hieu thuan

	FILE* fout4 = fopen("newton.txt", "a");
	if (fout4 == NULL) {
		printf("Khong mo duoc file !");
	}
	fprintf(fout4, "Bang ty hieu nghich: \n");
	fprintf(fout4, "\n \t X");
	fprintf(fout4, "\t Y");
	for (int i = 0; i < n - 1; i++)
	{
		fprintf(fout4, "\t Y^%d", i + 1);
	}
	fprintf(fout4, "\n      ___________________________________");
	for (int i = 0; i < n; i++) {
		fprintf(fout4, "\n \t %0.2lf", x[i]);

		for (int k = 0; k <= i; k++) {
			fprintf(fout4, "\t %0.2lf", y[i][k]);
		}
	}
	fprintf(fout4, "\n\n");
	fclose(fout4);
}


void ghifile5(int n, double x[], double  y[][20]) {
	int i, j;
	//ghi lai bang ty hieu nghich

	FILE* fout5 = fopen("newton.txt", "a");
	if (fout5 == NULL) {
		printf("Khong mo duoc file !");
	}
	fprintf(fout5, "Bang sai phan thuan: \n");
	fprintf(fout5, "\n \t X");
	fprintf(fout5, "\t Y");
	for (int i = 0; i < n - 1; i++)
	{
		fprintf(fout5, "\t Y^%d", i + 1);
	}
	fprintf(fout5, "\n      ___________________________________");
	for (int i = 0; i < n; i++) {
		fprintf(fout5, "\n \t %0.2lf", x[i]);

		for (int k = 0; k < n - i; k++) {
			fprintf(fout5, "\t %0.2lf", y[i][k]);
		}
	}
	fprintf(fout5, "\n\n");
	fclose(fout5);
}

//ghi lai so do hoocne

void ghifilehoocle(int n, double* mangKQ, double p, double arr[], float* c)
{
	int i;
	FILE* fout7 = fopen("newton.txt", "a");

	fprintf(fout7, "\nNhap gia tri can tinh : \n");
	fprintf(fout7, "%f", *c);
	fprintf(fout7, "\n\n");
	for (i = 0; i < n; i++) {
		fprintf(fout7, "%16.4lf", arr[n - i - 1]);
	}
	fprintf(fout7, "\n                 ");
	for (i = 1; i < n; i++) {
		fprintf(fout7, "%16.4lf ", mangKQ[i - 1] * (*c));
	}
	fprintf(fout7, "\n-------------------------------------------------------------------\n");
	for (i = 0; i < n; i++) {
		fprintf(fout7, "%16.4lf ", mangKQ[i]);
	}
	fprintf(fout7, "\nGia tri cua da thuc tai c la: f(c) = %lf", p);
	fclose(fout7);
}
//Xóa files
void ClearFile() {
	FILE* f = fopen("newton.txt", "w");//f tuong trung cho cac con tro file tu fout1 ->5
	if (f == NULL) {
		printf("Khong xoa duoc noi dung trong file !");
	}
	fclose(f);
}

//ghi lai da thuc 

void Indathuc1(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
	int i, j;
	FILE* fout8 = fopen("newton.txt", "a");
	fprintf(fout8, "\nDa thuc noi suy Newton tien moc bat ky la: \n");
	fprintf(fout8, "\nP(x) = ");
	for (i = 0; i < n; i++) {
		if (i == 0) {
			if (y[0][1] >= 0) {
				fprintf(fout8, "%.2lf + ", y[0][0]);
			}
			else {
				fprintf(fout8, "%.2lf - ", y[0][0]);
			}
		}
		else {
			fprintf(fout8, "%.2lf", y[0][i]);
			for (j = 0; j < i; j++) {
				if (x[j] < 0) {
					fprintf(fout8, "(x + %.2lf)", -x[j]);
				}
				else  if (x[j] > 0) {
					fprintf(fout8, "(x - %.2lf)", x[j]);
				}
				else {
					fprintf(fout8, "x");
				}
			}
			if (i != n - 1) {
				if (y[0][i + 1] >= 0) {
					fprintf(fout8, " + ");
				}
			}
		}

	}
	fprintf(fout8, "\n\n");
	fclose(fout8);

}

void Indathuc2(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
	int i, j;
	FILE* fout9 = fopen("newton.txt", "a");
	fprintf(fout9, "\nDa thuc noi suy Newton lui voi moc bat ky la: \n");
	fprintf(fout9, "\nP(x) = ");
	for (i = n; i > 0; i--) {
		if (i == n) {
			if (y[n - 1][1] >= 0) {
				fprintf(fout9, "%.2lf + ", y[n - 1][0]);
			}
			else {
				fprintf(fout9, "%.2lf - ", -y[n - 1][0]);
			}
		}
		else {
			fprintf(fout9, "%.2lf", y[n - 1][n - i]);
			for (j = n; j > i; j--) {
				if (x[j - 1] < 0) {
					fprintf(fout9, "(x + %.2lf)", -x[j - 1]);
				}
				else  if (x[j - 1] > 0) {
					fprintf(fout9, "(x - %.2lf)", x[j - 1]);
				}
				else {
					fprintf(fout9, "x");
				}
			}
			if (i != 1) {
				if (y[n - 1][i - 1] >= 0) {
					fprintf(fout9, " + ");
				}
			}
		}

	}
	fprintf(fout9, "\n\n");
	fclose(fout9);

}

void Indathuc3(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
	int i, j;
	double denta = x[1] - x[0];
	FILE* fout10 = fopen("newton.txt", "a");
	fprintf(fout10, "\nDa thuc Newton tien moc cach deu la: \n");
	fprintf(fout10, "\nP(x) = ");
	for (i = 0; i < n; i++) {
		if (i == 0) {
			if ((y[0][1]) >= 0) {
				fprintf(fout10, "%.2lf + ", y[0][0]);
			}
			else {
				fprintf(fout10, "%.2lf  ", y[0][0]);
			}
		}
		else {
			fprintf(fout10, "%.2lf", (y[0][i]) / (giaiThua(i) * pow(denta, i)));
			for (j = 0; j < i; j++) {
				if (x[j] < 0) {
					fprintf(fout10, "(x + %.2lf)", -x[j]);
				}
				else  if (x[j] > 0) {
					fprintf(fout10, "(x - %.2lf)", x[j]);
				}
				else {
					fprintf(fout10, "x");
				}
			}
			if (i != n - 1) {
				if (y[0][i + 1] >= 0) {
					fprintf(fout10, " + ");
				}
			}
		}

	}
	fprintf(fout10, "\n\n");
	fclose(fout10);
}

void Indathuc4(int n, double x[], double y[][SO_MOC_LON_NHAT]) {
	int i, j;
	double denta = x[1] - x[0];
	FILE* fout11 = fopen("newton.txt", "a");
	fprintf(fout11, "\nDa thuc Newton lui moc cach deu la: \n");
	fprintf(fout11, "\nP(x) = ");
	for (i = n; i > 0; i--) {
		if (i == n) {
			if ((y[n - 1][1]) / (giaiThua(i) * pow(denta, i)) >= 0) {
				fprintf(fout11, "%.2lf + ", y[n - 1][0]);
			}
			else {
				fprintf(fout11, "%.2lf - ", y[n - 1][0]);
			}
		}
		else {
			fprintf(fout11, "%.2lf", (y[n - 1][n - i]) / (giaiThua(n - i) * pow(denta, ((double)n - i))));
			for (j = n; j > i; j--) {
				if (x[j - 1] < 0) {
					fprintf(fout11, "(x + %.2lf)", -x[j - 1]);
				}
				else  if (x[j - 1] > 0) {
					fprintf(fout11, "(x - %.2lf)", x[j - 1]);
				}
				else {
					fprintf(fout11, "x");
				}
			}
			if (i != 1) {
				if (y[n - 1][i - 1] >= 0) {
					fprintf(fout11, " + ");
				}
			}
		}
	}
	fprintf(fout11, "\n\n");
	fclose(fout11);
}

//ghi lai da thuc(he so)
void Indathuc5(int n, double tmpMangMu[], double** mangMu)
{
	int i;
	FILE* fout12 = fopen("newton.txt", "a");
	fprintf(fout12, "\n\nMa tran he so la: \n");
	for (i = 0; i < n; i++) {
		fprintf(fout12, "\n");
		for (i = 0; i < n; i++) {
			fprintf(fout12, "%lf\t", mangMu[i]);
		}
	}
	fprintf(fout12, "\nHe so mu cua da thuc la: \n");
	for (int i = 0; i < n; i++)
	{
		fprintf(fout12, "\nMu %i : %lf", i, tmpMangMu[i]);
	}
	fprintf(fout12, "\n\n");
	fclose(fout12);
}