/*Viết chương trình để tạo một xâu kí tự, là xâu đảo ngược của một xâu bất kì được nhập vào từ bàn phím*/

#include<stdio.h>

int main()
{
	char a[20];
	int i = 0;
	int j;

	printf("Nhap xau : ");
	scanf_s("%s", a);

	for (i = 0; i < 20; i++)
	{
		if (a[i] == '\0')
		{
			j = i - 1;
			for (j = i - 1; j >= 0; j--)
			{
				a[i] = a[j];
			}
			a[i] = a[i] + '\0';
			break;
		}
	}


}