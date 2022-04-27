/* Liêt kê thư viện */
#include <stdio.h>
#include <stdlib.h>

/* Khai báo hàm */
void printPoly(double poly[], int n);
double* multiPoly(double A[], double B[], int m, int n);
double horner(double F[], double a, int n);

/* Chương trình chính */
int main(void)
{
    double X[] = { 1, 2, 3, 4, 7 };
    double Y[] = { 17, 27.5, 76, 210.5, 1970 };
    const int size = sizeof(X) / sizeof(double);        // cỡ dữ liệu đầu vào
    double F[size];             // Mảng hệ số của đa thức nội suy
    double L[size][size];       // Mảng các đa thức Lagrange cơ bản
    double poly[size][2];       // Các đa thức con cần dùng trong quá trình tính toán
    // Biến chạy vòng lặp for
    int i, j, k;
    // Biến tạm trong quá trình tính toán
    double* tempPoly;
    double temp;


    /* 1. Tim các đa thức Lagrange cơ bản và in ra màn hình */

    /* Khởi tạo các đa thức con từ mảng X */
    for (i = 0; i < size; i++)
    {
        poly[i][0] = -X[i];
        poly[i][1] = 1;
    }
    for (i = 0; i < size; i++)

    {
        /* Khởi tạo tempPoly để tính đa thức Lagrange cơ bản */
        if (i == 0)
            tempPoly = poly[1];
        else
            tempPoly = poly[0];

        /* Tính đa thức Lagrange cơ bản L[i] thông qua tempPoly */
        k = 0;
        for (j = 0; j < size; j++)
        {
            if ((j != 0 && j != i && i != 0) || (i == 0 && j > 1))
            {
                tempPoly = multiPoly(tempPoly, poly[j], k + 2, 2);
                k++;
            }
        }
        temp = 1;
        for (j = 0; j < size; j++)
        {
            if (j != i)
                temp *= -poly[i][0] + poly[j][0];
        }

        /* Lưu các đa thức Lagrange cơ bản vào mảng L rồi in ra màn hình */
        for (j = 0; j < size; j++)
            L[i][j] = (tempPoly[j] / temp);
        printf("L[%d] = ", i + 1);
        printPoly(L[i], size);
    }
    /* Giải phóng bộ nhớ cho tempPoly sau khi không còn sử dụng */
    free(tempPoly);

    /* 2, Tìm các hệ số của đa thức nội suy thông qua các đa thức cơ bản */
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            F[i] += L[j][i] * Y[j];
        }
    }
    /* In đa thức nội suy ra màn hình */
    printf("F = ");
    printPoly(F, size);

    /*  Thử lại kết quả
    for (i = 0; i < size; i++)
        printf("F(%f) = %f\n", X[i], horner(F, X[i], size));
    */

    return 0;
}


/* Định nghĩa các hàm */

void printPoly(double poly[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (poly[i] != 0) // Chỉ in khi hệ số khác 0
        {
            // In hệ số
            if (poly[i] != 1 || i == 0)
                printf("%.2f", poly[i] > 0 ? poly[i] : -poly[i]);
            // In biến số
            if (i != 0)
                i > 1 ? printf("x^%d", i) : printf("x");
            // In dấu '+', '-'
            if (i != 0)
                poly[i - 1] > 0 ? printf(" + ") : printf(" - ");
        }
    }
    putchar('\n');
}

double* multiPoly(double A[], double B[], int m, int n)
{
    double* prod = (double*) malloc(sizeof(double) * (m + n - 1));

    for (int i = 0; i < m + n - 1; i++)
        prod[i] = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            prod[i + j] += A[i] * B[j];

    return prod;
}


double horner(double F[], double a, int n)
{
    int i;
    double result;

    result = 0;
    printf("Khởi tạo result = 0\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d. result = result * %f %c %f", i + 1, a,
            F[i] > 0 ? '+' : '-', F[i] > 0 ? F[i] : -F[i]);
        result = result * a + F[i];
        printf("    --> %s result = %f\n", i != 0 ? "temp" : "final", result);
    }

    return result;
}
