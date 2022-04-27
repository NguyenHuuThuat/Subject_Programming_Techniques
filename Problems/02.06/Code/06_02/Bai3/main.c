#include <stdio.h>
#include <string.h>

#define MAX_LEN_BUFF			1024

int main() {
	FILE* fp;
	int i;
	char c;
	char duLieuFile[MAX_LEN_BUFF];
	int mIndexMangBuff = 0;
	int *pInt;
	fp = fopen("../bin1.bin", "wb");

	int mSoLuongSo;
	printf("Nhap so luong cac so thap phan can luu: \t");
	scanf("%d", &mSoLuongSo);
	pInt = (int*)malloc(mSoLuongSo * sizeof(int));
	for (i = 0; i < mSoLuongSo; i++)
	{
		int tmpNhap;
		printf("So thu %d:\t", i + 1);
		scanf("%d", &tmpNhap);
		fwrite(&tmpNhap, sizeof(int), 1, fp);
	}
	fclose(fp);
	printf("Mo lai File va in cac so vua nhap duoi dang thap phan...\n");
	fp = fopen("../bin1.bin", "rb");
	for (i = 0; i < mSoLuongSo; i++) {
		int tmp;
		fread(&tmp, sizeof(int), 1, fp);
		printf("So thu %d:\t%d\n\r", i + 1, tmp);
		pInt[i] = tmp;
	}
	fclose(fp);

	// sao chep tep
	printf("\n\rSao chep tep...\n");

	fp = fopen("../bin2_cpy.bin", "wb");
	for (i = 0; i < mSoLuongSo; i++)
	{
		fwrite(&pInt[i], sizeof(int), 1, fp);
	}
	fclose(fp);
	return 1;
}