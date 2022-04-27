﻿/*Viết các chương trình có các hàm nhập ma trận, in ma
trận, cài đặt phép toán trên ma trận: cộng hai ma trận,
nhân vô hướng, nhân 2 ma trận, phép biến đổi sơ cấp
trên ma trận*/

#include<stdio.h>
#include<stdlib.h>

int  soHangMaTran1 = 0;
int  soCotgMaTran1 = 0;

int  soHangMaTran2 = 0;
int  soCotgMaTran2 = 0;

void inMaTran(int** pMaTran, int soHang, int soCot) {
	int i, j;
	for (i = 0; i < soHang; i++)
	{
		for (j = 0; j < soCot; j++)
		{
			printf("%d\t", pMaTran[i][j]);
		}
		printf("\n");
	}
}

void nhapMaTran(int** pMaTran, int soHang, int soCot) {
	int i, j;
	for (i = 0; i < soHang; i++)
	{
		for (j = 0; j < soCot; j++)
		{
			printf("Nhap Mang[%d][%d]: ", i, j);
			scanf_s("%d", &pMaTran[i][j]);
		}
	}
}


void cong2MaTran(int** pMatran1, int** pMatran2) {
	int i, j;

	if ((soHangMaTran1 == soHangMaTran2) && (soCotgMaTran1 == soCotgMaTran2)) { // ok 
		int** pMaTranTong = NULL;

		// cap phat bo nho dong
		pMaTranTong = (int**)malloc(soHangMaTran1 * sizeof(int*));

		for (i = 0; i < soHangMaTran1; i++)
		{
			pMaTranTong[i] = (int*)malloc(soCotgMaTran1 * sizeof(int));
		}

		for (i = 0; i < soHangMaTran1; i++)
		{
			for (j = 0; j < soCotgMaTran1; j++)
			{
				pMaTranTong[i][j] = pMatran1[i][j] + pMatran2[i][j];
			}
		}
		printf("Tong 2 ma tran la: ");
		inMaTran(pMaTranTong, soHangMaTran1, soCotgMaTran1);

	}
	else {
		printf("2 ma tran khong cong duoc ! \n");
	}
}




void nhanVoHuong(int** pMatran, int soHang, int soCot) {
	int i, j, heSoNhan;
	int** pMaTranKetQua = NULL;


	printf("Nhap he so nhan: \n");
	scanf_s("%d", &heSoNhan);


	// cap phat bo nho dong
	pMaTranKetQua = (int**)malloc(soHang * sizeof(int*));

	for (i = 0; i < soHang; i++)
	{
		pMaTranKetQua[i] = (int*)malloc(soCot * sizeof(int));
	}

	for (i = 0; i < soHang; i++)
	{
		for (j = 0; j < soCot; j++)
		{
			pMaTranKetQua[i][j] = heSoNhan * pMatran[i][j];
		}
	}
	printf("Tich vo huong ma tran la: \n");
	inMaTran(pMaTranKetQua, soHang, soCot);
}




void nhan2MaTran(int** pMatran1, int** pMatran2) {
	int i, j, k, sum = 0;

	if ((soHangMaTran1 == soCotgMaTran2) && (soCotgMaTran1 == soHangMaTran2)) { // ok 
		int** pMaTranKetQua = NULL;

		// cap phat bo nho dong
		pMaTranKetQua = (int**)malloc(soHangMaTran1 * sizeof(int*));

		for (i = 0; i < soHangMaTran1; i++)
		{
			pMaTranKetQua[i] = (int*)malloc(soCotgMaTran2 * sizeof(int));
		}

		for (i = 0; i < soHangMaTran1; i++)
		{
			for (j = 0; j < soCotgMaTran2; j++)
			{
				sum = 0;
				for (int k = 0; k < soCotgMaTran1; k++)
				{
					sum = sum + pMatran1[i][k] * pMatran2[k][j];
				}
				pMaTranKetQua[i][j] = sum;
			}
		}
		printf("Ket qua ma tran 1 X ma tran 2 la: \n");
		inMaTran(pMaTranKetQua, soHangMaTran1, soCotgMaTran2);

	}
	else {
		printf("2 ma tran khong nhan duoc coi nhau ! \n");
	}
}





int main() {

	int** pMaTran1 = NULL;
	int** pMaTran2 = NULL;

	int i;
	printf("Nhap vao so hang ma tran 1 = ");
	scanf_s("%d", &soHangMaTran1);

	printf("Nhap vao so cot ma tran 1 = ");
	scanf_s("%d", &soCotgMaTran1);

	printf("Nhap vao so hang ma tran 2 = ");
	scanf_s("%d", &soHangMaTran2);

	printf("Nhap vao so cot ma tran 2 = ");
	scanf_s("%d", &soCotgMaTran2);


	// cap phat bo nho dong

	pMaTran1 = (int**)malloc(soHangMaTran1 * sizeof(int*));

	for (i = 0; i < soHangMaTran1; i++)
	{
		pMaTran1[i] = (int*)malloc(soCotgMaTran1 * sizeof(int));
	}

	pMaTran2 = (int**)malloc(soHangMaTran2 * sizeof(int*));

	for (int i = 0; i < soHangMaTran2; i++)
	{
		pMaTran2[i] = (int*)malloc(soCotgMaTran2 * sizeof(int));
	}

	printf("Nhap Ma tran 1: \n");
	nhapMaTran(pMaTran1, soHangMaTran1, soCotgMaTran1);
	printf("Ma tran 1 vua nhap la: \n");
	inMaTran(pMaTran1, soHangMaTran1, soCotgMaTran1);


	printf("Nhap Ma tran 2: \n");
	nhapMaTran(pMaTran2, soHangMaTran2, soCotgMaTran2);
	printf("Ma tran 2 vua nhap la: \n");
	inMaTran(pMaTran2, soHangMaTran2, soCotgMaTran2);


	// cong 2 ma tran
	cong2MaTran(pMaTran1, pMaTran2);

	// nhan Vo Huong
	nhanVoHuong(pMaTran1, soHangMaTran1, soCotgMaTran1);
	// nhan 2 ma tran
	nhan2MaTran(pMaTran1, pMaTran2);

}