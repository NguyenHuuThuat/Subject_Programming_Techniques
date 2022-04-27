#include<stdio.h>
#include<Windows.h>
#include<conio.h>

#define NUMBER_ITEM 5

void veMenu(int selectedItem);

int main()
{
	int i = 0, select = 1;

	char press = ' ', isQuit = '1';
	while (1)
	{
		veMenu(select);
		press = _getch();
		switch (press)
		{
		case 119:
			//press w
			select--;
			if (select < 1) select = 1;
			break;
		case 115:
			//press s
			select++;
			if (select > 5) select = 5;
			break;
		case 13:
			//press Enter
			printf("Da chon %d", select);
			//Do something
			switch (select)
			{
			case 1:
				system("cls");
				//item 1
				break;
			case 2:
				//item 2
				break;
			default:
				break;
			}
			printf("Do you want continue:\n0.No\n1.Yes\n");

			isQuit = _getch();
			while (isQuit != '0' && isQuit != '1')
			{
				printf("Enter again!!!");
				isQuit = _getch();
			}
			break;
		default:
			break;
		}

		if (isQuit == '0')
		{
			break;
		}
	}

	return 0;
}

void veMenu(int selectedItem)
{

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 80);
	printf("                  ____________________________\n");
	printf("                 | Menu:                     |\n");
	int i = 0;
	for (i = 0; i < NUMBER_ITEM; i++)
	{
		if (i == (selectedItem - 1) % NUMBER_ITEM)
		{
			printf("                 |");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
			printf("Item %d                     |\n", i + 1);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 80);
			printf("                 |");
			printf("Item %d                     |\n", i + 1);
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 80);
	printf("                 |___________________________|\n");

}