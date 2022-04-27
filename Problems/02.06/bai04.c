#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
	char ho_ten[50];
	unsigned int tuoi;
	unsigned long luong;

}S_TT_NGUOI;


// sap xep luong giam dan
void giamDan(S_TT_NGUOI* pInput, int n) {
	int tg;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((pInput + i)->luong < (pInput + j)->luong) {
				// Hoan vi 2 so a[i] va a[j]
				S_TT_NGUOI sTmp;
				strcpy(sTmp.ho_ten, (pInput + i)->ho_ten);
				sTmp.luong = (pInput + i)->luong;
				sTmp.tuoi = (pInput + i)->tuoi;


				strcpy((pInput + i)->ho_ten, (pInput + j)->ho_ten);
				(pInput + i)->luong = (pInput + j)->luong;
				(pInput + i)->tuoi = (pInput + j)->tuoi;


				strcpy((pInput + j)->ho_ten, sTmp.ho_ten);
				(pInput + j)->luong = sTmp.luong;
				(pInput + j)->tuoi = sTmp.tuoi;
			}
		}
	}
}

int main() {

	unsigned int mSoLuongNguoi;
	S_TT_NGUOI* pTTNguoi;
	unsigned long mTongLuong = 0;

	int i;
	FILE* fp;
	fp = fopen("../fileBai4.bin", "wb");

	printf("Nhap so luong nguoi: \t");
	scanf("%d", &mSoLuongNguoi);

	pTTNguoi = (S_TT_NGUOI*)malloc(mSoLuongNguoi * sizeof(S_TT_NGUOI));
	for (i = 0; i < mSoLuongNguoi; i++)
	{
		fflush(stdin);
		printf("Ho Ten nguoi thu %d: \t", i + 1);
		fflush(stdin);
		int c;
		while ((c = getchar()) != EOF && c != '\n') // xoa bo dem
			;
		gets(pTTNguoi[i].ho_ten);
		printf("Tuoi nguoi thu %d: \t", i + 1);
		scanf("%d", &pTTNguoi[i].tuoi);
		printf("Luong nguoi thu %d: \t", i + 1);
		scanf("%ld", &pTTNguoi[i].luong);
		fwrite(&pTTNguoi[i], sizeof(S_TT_NGUOI), 1, fp);

		mTongLuong += pTTNguoi[i].luong;
	}
	fclose(fp);
	// tim luong cao nhat
	giamDan(pTTNguoi, mSoLuongNguoi);
	printf("Ho Ten va Luong nguoi cao nhat la: \n");

	for (i = 0; i < mSoLuongNguoi; i++)
	{
		printf("+) %d Ho ten: %s - Luong: %ld \n\r", i + 1, pTTNguoi[i].ho_ten, pTTNguoi[i].luong);
		if (i != mSoLuongNguoi - 1) {
			if (pTTNguoi[i].luong != pTTNguoi[i + 1].luong) {
				break;
			}
		}
	}

	// Tb luong 
	double mTbLuong = mTongLuong / mSoLuongNguoi;
	printf("Tb Luong la: \t%lf\n", mTbLuong);
	printf("Danh sach nguoi co luong cao hon luong TB la: \n");
	for (i = 0; i < mSoLuongNguoi; i++)
	{
		printf("+) %d Ho ten: %s - Luong: %ld \n\r", i + 1, pTTNguoi[i].ho_ten, pTTNguoi[i].luong);
		if (i != mSoLuongNguoi - 1) {
			if (mTbLuong > pTTNguoi[i + 1].luong) {
				break;
			}
		}
	}
	//sua noi dung thu k, -> doc file, lay k -> sua
	int stt;
	S_TT_NGUOI sTmp;
	printf("So TT can sua: \t");
	scanf("%d", &stt);
	if ((stt > 0) && (stt <= mSoLuongNguoi)) {
		printf("Thong tin can sua: \n");

		printf("Ho Ten : \t");
		fflush(stdin);
		int c;
		while ((c = getchar()) != EOF && c != '\n') // xoa bo dem
			;
		gets(sTmp.ho_ten);
		printf("Tuoi: \t");
		scanf("%d", &sTmp.tuoi);
		printf("Luong: \t");
		scanf("%ld", &sTmp.luong);

		fp = fopen("../fileBai4.bin", "rb");
		for (i = 0; i < mSoLuongNguoi; i++) {
			S_TT_NGUOI tmp;
			fread(&tmp, sizeof(S_TT_NGUOI), 1, fp);
			if (i != (stt + 1)) {
				strcpy((pTTNguoi + i)->ho_ten, tmp.ho_ten);
				(pTTNguoi + i)->luong = tmp.luong;
				(pTTNguoi + i)->tuoi = tmp.tuoi;
			}
			else {
				strcpy((pTTNguoi + i)->ho_ten, sTmp.ho_ten);
				(pTTNguoi + i)->luong = sTmp.luong;
				(pTTNguoi + i)->tuoi = sTmp.tuoi;
			}
		}
		fclose(fp);

		//ghi file
		fp = fopen("../fileBai4.bin", "wb");
		for (i = 0; i < mSoLuongNguoi; i++)
		{
			fwrite(&pTTNguoi[i], sizeof(S_TT_NGUOI), 1, fp);
		}
		fclose(fp);
	}
	else
	{
		printf("STT nhap khong dung!");
	}

	return 1;
}