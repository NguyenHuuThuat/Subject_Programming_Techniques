#include <stdio.h>

int main() {
	int soMu1[] = { 1,2, 4 }; //(1 + 2x + 4x^2)
	int soMu2[] = { 5,6}; // (5 +6x)
	int mangChuaMu[4];
	for (int i = 0; i < 4; i++)
	{
		mangChuaMu[i] = 0;
	}
	for (int i  = 0;  i< 3;i ++)
	{
		for (int j = 0; j < 2; j++)
		{
			mangChuaMu[i + j] = mangChuaMu[i + j] + soMu1[i] * soMu2[j];
			printf("%d\n", mangChuaMu[i]);
		}

	}
	char dataIn[1000];
	for (int i = 0; i < 1000; i++)
	{
		dataIn[i] = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		printf("%d\t",mangChuaMu[i]);
		sprintf(dataIn, "%s %d\t", dataIn, mangChuaMu[i]);
	}

	printf("\n in string :%s\n", dataIn);

}