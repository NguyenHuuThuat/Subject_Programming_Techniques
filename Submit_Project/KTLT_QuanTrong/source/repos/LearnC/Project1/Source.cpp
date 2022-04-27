#include<stdio.h>

int main() {
	char luaChon;
	printf("Con cho co may chan??? \n");
	printf("A. 1 \nB. 2 \nC.3 \nD.4 \n");
	printf("Chon dap an chinh xac nhat: ");
	luaChon = getchar( );

	switch (luaChon)
	{
		case 'a':
		case 'A':
		case 'b':
		case 'B':
		case 'c':
		case 'C': {
			printf("Rat tiec, dap an cua ban khong chinh xac!!!");
			break;
		};
		case 'd':
		case 'D': {
			printf("Xin chuc mung ban da tra loi chinh xac!!!");
			break;
		}
	default:
		printf("Ban nhap sai roi!!!");
		break;
	}
	return 0;


}