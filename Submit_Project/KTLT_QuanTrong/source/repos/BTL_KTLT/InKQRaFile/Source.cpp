#include <stdio.h>

int main()
{
	FILE* fvb, * fnp;
	fvb = fopen("vb.txt", "a");
	fnp = fopen("np.txt", "wb");

	fputc('A', fvb);
	fputc(26, fvb);

	fputc('a', fnp);
	fputc(26, fvb);

	fclose(fvb);
	fclose(fnp);
}