#include <stdio.h>
void insertionSort(int a[], int n);

int main()
{
	int a[] = { 5,4,3,2,1 };
	int n = 5;
	insertionSort(a, n);

	return 0;
}



void insertionSort(int a[], int n)
{
	int i, cur, j;
	int count = 0;
	for (i = 1; i < n; i++)
	{
		cur = a[i];
		j = i;
		while ((j > 0) && (a[j - 1] > cur))
		{
			count += 2;
			a[j] = a[j - 1];
			j = j - 1;
		}
		a[j] = cur;
	}
	printf("So phep so sanh là: %d", count);
}