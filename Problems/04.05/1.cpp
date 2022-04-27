/*Viết chương trình để in ra xâu đảo ngược của một xâu bất kì được nhập vào từ bàn phím*/

#include<stdio.h>

int main()
{

	char a[20];
	int i = 0;

	printf("Nhap xau : ");
	scanf_s("%s", a);

	for (i = 0; i < 20; i++)
	{
		if (a[i] == '\0')
		{
			int j = i - 1;
			for (j = i - 1; j >= 0; j--)
			{
				printf("%c", a[j]);
			}
			break;
		}
	}

}