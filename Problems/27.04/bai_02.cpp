/* Ma Tran */

#include<stdio.h>
#include<math.h>
#include<conio.h>

int main() {
    int a[50][50], *p;
    int i, j, m, n;
    p = &a[0][0] ;

    printf("nhap so hang n="); 
    scanf_s("%d", &n);
    printf("nhap so cot m="); 
    scanf_s("%d", &m);

    //Nhap vao ma tran
    printf("nhap vao ma tran:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf_s("%d", &a[i][j]);
        }
    }
    printf("ma tran vua nhap cach 1 la:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("ma tran vua nhap cach 2 la:\n");
    for (i = 0; i <= m * n; i++) {
        p += i;
    }
    printf("%d", p);

}