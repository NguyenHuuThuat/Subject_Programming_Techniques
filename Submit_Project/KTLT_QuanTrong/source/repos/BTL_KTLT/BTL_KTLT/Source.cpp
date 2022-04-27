#include<stdio.h>

//Định nghĩa kiểu cấu trúc
struct DIEMMOC {
	float x;
	float y;
};
typedef struct DIEMMOC DiemMoc;

//khai báo nguyên mẫu hàm
//void nhap();
void bangTiHieu();

int main() {

	bangTiHieu();


	return 0;
}

//Triển khai các hàm
//void nhap() {
//	int i;
//	int n;
//	DiemMoc p;
//	DiemMoc arr[100];
//	printf("Nhap so diem moc: \n");
//	scanf("%d", &n);
//	for (i = 0; i <= n; i++) {
//		printf("x%d = ", i);
//		scanf("%f", &p.x);
//		printf("y%d = ", i);
//		scanf("%f", &p.y);
//	}
//	for (i = 0; i <= n; i++) {
//		printf("(%f , %f) ", p.x, p.y);
//	}
//}

void bangTiHieu() {
	int i, j;
	int X[] = { 11, 13, 14, 18, 19, 21 };
	int Y[] = { 1342, 2210, 2758, 5850, 6878, 9282 };
	int tiHieu[10];

	for (i = 0; i < 6; i++) {
		tiHieu[i] = Y[i];
	}

	for (j = 1; i < 6; j++) {
		for (i = 1; i < 6; i++) {
			tiHieu[i] = (tiHieu[i + 1] - tiHieu[i]) / (X[i + 1] = X[i]);
		}
		printf("%d\n", tiHieu[j]);
	}



}