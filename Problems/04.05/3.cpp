/* Viết chương trình để chuyển một xâu kí tự được nhập vào từ bàn phím thành xâu đảo ngược của nó.*/

#include<stdio.h>
#include<string.h>

void daoXau();

int main() {

	char a[];
	printf("Nhap xau : ");
	scanf_s("%s", a);
	printf("Xau dao nguoc la: ", a);
	return 0;
}

void daoXau() {
	char a[];
	strlen(a);
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


