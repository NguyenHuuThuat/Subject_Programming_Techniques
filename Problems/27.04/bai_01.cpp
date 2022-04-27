/* vector cỡ n*/

#include<stdio.h>
#include<math.h>

int main() {
	int size = 3;
	int vector1[3] = { 1 , 2 , 3 };
	int vector2[3] = { 4 , 5 , 6 };
	int i ;
	float d = 0 ;
	float tichVoHuong = 0 ;

	//hien thi vector
	printf("Vector1 = ");
	for (i = 0; i < 3; i++) {
		printf("\t%d ",vector1[i]);
	}
	printf("\nVector2 = ");
	for (i = 0; i < 3; i++) {
		printf("\t%d ", vector2[i]);
	}

	//tinh chieu dai cua verctor
	for (i = 0; i < 3; i++) {
		d = sqrt(d * d + vector1[i] * vector1[i]);
	}
	printf("\nchieu dai cua vetor la d = %f ",d);

	//tich vo huong cua 2 vector
	for (i = 0; i < 3; i++) {
		tichVoHuong = tichVoHuong + (vector1[i] * vector2[i]);
	}
	printf("\ntich vo huong cua 2 vector la: %f", tichVoHuong);
	return 0;
}