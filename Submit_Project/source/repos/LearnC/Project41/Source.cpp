#include<stdio.h>
#include<string.h>

int main() {
	char str1[] = "Viet Nam";
	char str2[] = "Ha Noi";
	char str[100];

	printf("\nDo dai xau str1: %d", strlen(str1));
	printf("\nDo dai xau str2: %d\n", strlen(str2));
	printf("\nDo dai xau str: %d\n", strlen(str));

	strcpy_s(str, str1);

	strcat_s(str, str2);
	puts(str);



}