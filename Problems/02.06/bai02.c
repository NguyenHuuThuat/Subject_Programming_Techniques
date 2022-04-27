#include <stdio.h>
#include <string.h>

#define MAX_LEN_BUFF			1024


int main() {
	FILE* fp;
	char buff[MAX_LEN_BUFF];
	char duLieuFile[MAX_LEN_BUFF];

	int mIndexMangBuff = 0;
	fp = fopen("../SFile.txt", "r");
	while (fgets(buff, MAX_LEN_BUFF, fp)) {
		strcpy(&duLieuFile[mIndexMangBuff], buff);
		mIndexMangBuff = mIndexMangBuff + strlen(buff);
	}
	fclose(fp);

	fp = fopen("../Dfile.txt", "w");
	fprintf(fp, duLieuFile);
	fclose(fp);
	printf("Done!\n\r");
	return 1;
}