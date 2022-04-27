#include <stdio.h>
#include <string.h>

#define MAX_LEN_BUFF			1024


int main() {
	FILE* fp;
	char buff[MAX_LEN_BUFF];
	int mSoKyTu = 0;
	fp = fopen("../testBai1.txt", "r");
	while (fgets(buff, MAX_LEN_BUFF, fp)) {
		mSoKyTu = mSoKyTu + strlen(buff);
	}
	printf("So ky tu trong file la: %d\n\r", mSoKyTu);
	fclose(fp);
	return 1;

}